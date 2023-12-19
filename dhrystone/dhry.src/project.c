/*
 * CYANCORE LICENSE
 * Copyrights (C) 2023, Cyancore Team
 *
 * File Name		: project.c
 * Description		: This file consists of project source to
 *			  execute dhrystone benchmark
 * Primary Author	: Akash Kollipara [akashkollipara@gmail.com]
 * Organisation		: Cyancore Core-Team
 */

#include <status.h>
#include <stdio.h>
#include <string.h>
#include <terravisor/bootstrap.h>
#include <driver.h>
#include <driver/onboardled.h>
#include <time.h>
#include <stdlib.h>
#include <dhry.h>

void plug()
{
	bootstrap();
	driver_setup_all();
	printf("Running Dhrystone ...\n");
#if MODE_REGISTER
	dhryR();
#else
	dhry();
#endif
	printf("Demo Program!\n");
	return;
}


void play()
{
	static unsigned char i = 0;
	char progress[] = "-\\|/";
	uint64_t time;
	char c = progress[(i++) % strlen(progress)];
	get_timestamp(&time);
	time /= 1000U;

	printf("[%012llu] Running Blinky ... [%c]", time, c);

	onboardled_toggle();

	mdelay(500);

	printf("\r");
	return;
}
