#
# CYANCORE LICENSE
# Copyrights (C) 2022, Cyancore Team
#
# File Name		: build.mk
# Description		: This file build project sources
# Primary Author	: Akash Kollipara [akashkollipara@gmail.com]
# Organisation		: Cyancore Core-Team
#

DEMO_DIR	:= $(GET_PATH)

OPTIMIZATION	:= 3

EXE_MODE	:= terravisor

ITERATIONS	:= 40000
TOTAL_DATA_SIZE	:= 1200
COMPILER_FLAGS	:= \"-O$(OPTIMIZATION)\"

$(eval $(call add_define,ITERATIONS))
$(eval $(call add_define,TOTAL_DATA_SIZE))
$(eval $(call add_define,COMPILER_FLAGS))
$(eval $(call add_include,$(DEMO_DIR)/))
$(eval $(call add_include,$(DEMO_DIR)/upstream))

DIR		:= $(DEMO_DIR)
Ex_SRCS		:= $(DIR)/upstream/core_list_join.c
Ex_SRCS		+= $(DIR)/upstream/core_matrix.c
Ex_SRCS		+= $(DIR)/upstream/core_main.c
Ex_SRCS		+= $(DIR)/upstream/core_state.c
Ex_SRCS		+= $(DIR)/upstream/core_util.c
include mk/obj.mk
