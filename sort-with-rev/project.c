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
#include <arch.h>
#include <stdio.h>
#include <terravisor/bootstrap.h>
#include <driver.h>
#include "sort_with_rev/app.h"

void plug()
{
	/* < ! > Plug in one time setup code */

	/* Boot system */
	bootstrap();
	driver_setup_all();

	/* Print Banner */
	printf("\n=================================================\n");
	printf(" Example on Cyancore: Sort by reversing array!");
	printf("\n=================================================\n");

	/* Run the app */
	main();
	return;
}

void play()
{
	/* < ! > Play looping code here*/

	/* Put CPU to sleep until interrupt is received */
	/* This is a power saving feature */
	arch_wfi();
	return;
}
