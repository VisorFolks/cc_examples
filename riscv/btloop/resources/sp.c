/*
 * CYANCORE LICENSE
 * Copyrights (C) 2019, Cyancore Team
 *
 * File Name		: platform_sp.c
 * Description		: This file contains sources for platform
 *			  software properties
 * Primary Author	: Akash Kollipara [akashkollipara@gmail.com]
 * Organisation		: Cyancore Core-Team
 */

#include <status.h>
#include <plat_defines.h>
#include <resource.h>

static uint8_t uart0pins[] = {16, 17};
static pinmux_t uart0 = addpins(0, uart0pins, serial);
swdev_t consoleUart =
{
	.swdev_id = console_uart,
	.hwdev_id = uart | 0,
	.pmux = &uart0
};

static uint8_t uart1pins[] = {18, 23};
static pinmux_t uart1 = addpins(0, uart1pins, serial);
swdev_t btuart =
{
	.swdev_id = bt_uart,
	.hwdev_id = uart | 1,
	.pmux = &uart1
};

sw_devid_t terra_devs[] =
{
	console_uart,
	bt_uart
};

visor_t terravisor = add_visor_devs(terra_devs);

swdev_t *sw_devs[] =
{
	&consoleUart,
	&btuart
};

sp_t software_prop =
{
	.terravisor = &terravisor,
	add_swdev(sw_devs),
};
