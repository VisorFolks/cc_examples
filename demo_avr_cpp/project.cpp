/*
 * CYANCORE LICENSE
 * Copyrights (C) 2019, Cyancore Team
 *
 * File Name		: project.cpp
 * Description		: This file consists of project srouces in cpp
 * Primary Author	: Akash Kollipara [akashkollipara@gmail.com]
 * Organisation		: Cyancore Core-Team
 */

/* Include C headers incapsulated in 'extern "C"' */
extern "C"
{
	#include <stdio.h>
	#include <status.h>
	#include <terravisor/platform.h>
	#include <terravisor/bootstrap.h>
	#include <driver.h>
	#include <driver/watchdog.h>
	#include <hal/gpio.h>
#include <time.h>
}

#include "gpio.h"


class onBoardLed led;

/* Use EXPORT_C macro for calling cpp functoin in c file */
EXPORT_C(void plug())
{
	bootstrap();
	driver_setup_all();

	/* call the setup member of led object */
	led.setup();

	printf("Demo Program! - Cpp\n");
	printf("< ! > Running Blinky ... [");
	return;
}

char progress[] = "-\\|/";

EXPORT_C(void play())
{
	static unsigned char i = 0;
	char progress[] = "-\\|/";
	uint64_t time;
	char c = progress[(i++) % strlen(progress)];

	get_timestamp(&time);
	time /= 1000U;
	printf("[%012llu] Running Blinky ... [%c]", time, c);

	wdog_guard(3, true, NULL);
	/* call the toggle member of led object */
	led.toggle();
	wdog_hush();

	mdelay(500);
	printf("\b\b");
	return;
}
