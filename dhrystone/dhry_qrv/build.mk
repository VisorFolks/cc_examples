#
# CYANCORE LICENSE
# Copyrights (C) 2023, Cyancore Team
#
# File Name		: build.mk
# Description		: This file builds and gathers project properties
# Primary Author	: Akash Kollipara [akashkollipara@gmail.com]
# Organisation		: Cyancore Core-Team
#

PROJECT_DIR	:= $(GET_PATH)

HZ		:= 1000000
MODE_REGISTER	:= 1
$(eval $(call add_define,HZ))
$(eval $(call add_define,MODE_REGISTER))

include $(PROJECT_DIR)/../dhry.src/build.mk
include $(PROJECT_DIR)/config.mk

DIR		:= $(PROJECT_DIR)
include mk/obj.mk

aux_target:
	make qemu_sifive_e_bl DEBUG=0
