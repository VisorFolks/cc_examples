#
# CYANCORE LICENSE
# Copyrights (C) 2023, Cyancore Team
#
# File Name		: build.mk
# Description		: This file build project sources
# Primary Author	: Akash Kollipara [akashkollipara@gmail.com]
# Organisation		: Cyancore Core-Team
#

DEMO_DIR	:= $(GET_PATH)

OPTIMIZATION	:= s

EXE_MODE	:= terravisor

NUMBER_OF_RUNS	:= 5000

$(eval $(call add_define,NUMBER_OF_RUNS))
$(eval $(call add_include,$(DEMO_DIR)/))

DIR		:= $(DEMO_DIR)
include mk/obj.mk
