#
# CYANCORE LICENSE
# Copyrights (C) 2019, Cyancore Team
#
# File Name		: config.mk
# Description		: This file consists of project config
# Primary Author	: Akash Kollipara [akashkollipara@gmail.com]
# Organisation		: Cyancore Core-Team
#

COMPILER	:= gcc
TC_VER		:= 5.4.0
FAMILY		:= mega_avr
PLATFORM	:= atmega328p
STDLOG_MEMBUF   := 0
BOOTMSGS        := 0
EARLYCON_SERIAL	:= 1		# Needed for boot message
CONSOLE_SERIAL	:= 1		# Needed for printf after boot
OBRDLED_ENABLE  := 0
TERRAKERN       := 0
