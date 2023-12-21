/*
 * CYANCORE LICENSE
 * Copyrights (C) 2022, Cyancore Team
 *
 * File Name		: sp.c
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

swdev_t schedTimer =
{
	.swdev_id = sched_timer,
	.hwdev_id = timer | 0,
};

static uint8_t led0pins[] = {5};
static pinmux_t obled0 = addpins(0, led0pins, 0);
swdev_t onBoardLED0 =
{
	.swdev_id = onboard_led | 0,
	.pmux = &obled0
};

sw_devid_t terra_devs[] =
{
	console_uart, sched_timer, (onboard_led | 0),
};

visor_t terravisor = add_visor_devs(terra_devs);

swdev_t *sw_devs[] =
{
	&consoleUart, &schedTimer, &onBoardLED0,
};

sp_t software_prop =
{
	.terravisor = &terravisor,
	add_swdev(sw_devs),
};
