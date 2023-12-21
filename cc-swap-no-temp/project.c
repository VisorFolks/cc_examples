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
#include <arch.h>
#include <terravisor/bootstrap.h>
#include <driver.h>

void plug()
{
	/* < ! > Plug in one time setup code */
	/* < ! > Plug in one time setup code */

	/* Boot system */
	bootstrap();
	driver_setup_all();

	/* Print Banner */
	printf("\n=================================================\n");
	printf(" Example on Cyancore: Swap without temp!");
	printf("\n=================================================\n");

	/* Algorithm */
	unsigned char a, b;

	a = 0x12;
	b = 0x34;

	printf("Before SWAP ] a = %x, b = %x\n", (unsigned int)a, (unsigned int)b);

	b ^= a;
	a ^= b;
	b ^= a;

	printf("After SWAP  ] a = %x, b = %x\n", (unsigned int)a, (unsigned int)b);

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
