/*
 * CYANCORE LICENSE
 * Copyrights (C) 2022, Cyancore Team
 *
 * File Name		: bt_serial.c
 * Description		: This file contains sources of bt uart
 * Primary Author	: Akash Kollipara [akashkollipara@gmail.com]
 * Organisation		: Cyancore Core-Team
 */

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <status.h>
#include <syslog.h>
#include <lock/spinlock.h>
#include <resource.h>
#include <machine_call.h>
#include <arch.h>
#include <driver.h>
#include <interrupt.h>
#include <hal/uart.h>
#include <hal/gpio.h>
#include <driver/sysclk.h>
#include "bt_serial.h"

FILE *stdbt;
static FILE dev;

static uart_port_t bt_port;
static gpio_port_t io[2];

static void bt_serial_irq_handler(void);

static status_t bt_serial_setup(void)
{
	uart_get_properties(&bt_port, bt_uart);
	bt_port.irq_handler = bt_serial_irq_handler;

	sysdbg2("UART engine @ %p\n", bt_port.baddr);
	sysdbg2("UART baud @ %lubps\n", bt_port.baud);
	sysdbg2("UART irqs - %u\n", bt_port.irq);
	/*
	 * If memory mapping is applicable,
	 * put it in mmu supported guide.
	 */
	return uart_setup(&bt_port, trx, no_parity);
}

static status_t bt_serial_write(const char c)
{
	status_t ret;
	while(!uart_buffer_available(&bt_port));
	ret = uart_tx(&bt_port, c);
	return ret;
}

static int_wait_t con_read_wait;
static char con_buff[32];
static uint8_t wp, rp, occ;


static status_t bt_serial_read(char *c)
{
	status_t ret = success;
	if(!occ)
	{
		ret = wait_lock(&con_read_wait);
		ret |= wait_till_irq(&con_read_wait);
	}

	*c = con_buff[(wp++)];
	wp = wp % 32;
	occ--;

	return ret;
}

static void bt_serial_irq_handler(void)
{
	if(uart_rx_pending(&bt_port))
	{
		wait_release_on_irq(&con_read_wait);
		while(uart_rx_pending(&bt_port))
		{
			uart_rx(&bt_port, &con_buff[(rp++)]);
			rp = rp % 32;
			occ++;
		}
	}
}

static status_t bt_serial_pre_clk_config(void)
{
	return success;
}

static status_t bt_serial_post_clk_config(void)
{
	uart_update_baud(&bt_port);
	return success;
}

static sysclk_config_clk_callback_t bt_handle =
{
	.pre_config = &bt_serial_pre_clk_config,
	.post_config = &bt_serial_post_clk_config
};

status_t bt_serial_driver_setup(void)
{
	status_t ret;
	ret = bt_serial_setup();
	ret |= sysclk_register_config_clk_callback(&bt_handle);
	dev.write = &bt_serial_write;
	dev.read = &bt_serial_read;
	stdbt = &dev;
	return ret;
}

status_t bt_serial_driver_exit(void)
{
	status_t ret;
	ret = sysclk_deregister_config_clk_callback(&bt_handle);
	ret |= uart_shutdown(&bt_port);
	for(uint8_t i = 0; i < bt_port.pmux->npins; i++)
	{
		ret |= gpio_disable_alt_io(&io[i]);
		ret |= gpio_pin_free(&io[i]);
	}
	return ret;
}

#if CONSOLE_SERIAL==1
INCLUDE_DRIVER(bt, bt_serial_driver_setup, bt_serial_driver_exit, 0, 255, 255);
#endif
