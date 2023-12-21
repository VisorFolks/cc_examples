/*
 * CYANCORE LICENSE
 * Copyrights (C) 2019, Cyancore Team
 *
 * File Name		: project.c
 * Description		: This file consists of project srouces
 * Primary Author	: Akash Kollipara [akashkollipara@gmail.com]
 * Organisation		: Cyancore Core-Team
 */

#include <status.h>
#include <stdio.h>
#include <string.h>
#include <terravisor/bootstrap.h>
#include <arch.h>
#include <driver.h>
#include <interrupt.h>
#include <mmio.h>
#include <driver/sysclk.h>
#include <hal/clint.h>
#include <hal/gpio.h>
#include "bt_serial.h"

static unsigned long long t;
static unsigned int ticks = 16384;
static gpio_port_t bled;

char *banner = "BT Loopback!\n< ! > Type anything...\n\n";

static void test()
{
	arch_di_mtime();
	t = clint_read_time();
	clint_config_tcmp(0, (t + ticks));
	arch_ei_mtime();
	gpio_pin_toggle(&bled);
}


void plug()
{
	bootstrap();
	driver_setup_all();
	link_interrupt(int_local, 7, test);

	gpio_pin_alloc(&bled, PORTA, 5);
	gpio_pin_mode(&bled, out);
	gpio_pin_clear(&bled);

	t = clint_read_time();
	clint_config_tcmp(0, (t + ticks));
	arch_ei_mtime();

	printf("%s", banner);
	fputs(stdbt, banner);
	return;
}

void play()
{
	char c;
	fgetc(stdbt, &c);
	fputc(stdbt, c);
	fputc(stdout, c);
	return;
}
