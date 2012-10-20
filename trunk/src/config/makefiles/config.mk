#===============================================================================
# Snow Leopard Compiler Project
#
# Copyright (C) 2008, 2009, 2010, 2011, 2012 Roel Sergeant
#
# This program is free software: you can redistribute it and/or modify it under
# the terms of the GNU General Public License as published by the Free
# Software Foundation, either version 3 of the License, or (at your option) any
# later version
#
# This program is distributed in the hope that it will be useful, but WITHOUT
# ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
# FOR A PARTICULAR PURPOSE. See the GNU General Public License for more 
# details.
#
# You should have received a copy of the GNU General Public License along with
# this program. If not, see <http://www.gnu.org/licenses/>
#===============================================================================

#-------------------------------------------------------------------------------
# config.mk
#-------------------------------------------------------------------------------
# Configuration include for all Makefiles
#-------------------------------------------------------------------------------

#-------------------------------------------------------------------------------
# Configuration include files
#
CONFIG_INCLUDE		= ../config/include

VERSION_C_INCLUDES	= \
	$(CONFIG_INCLUDE)/version.c.h					\
	$(CONFIG_INCLUDE)/version.h

VERSION_CPP_INCLUDES	= \
	$(CONFIG_INCLUDE)/version.cpp.hpp				\
	$(CONFIG_INCLUDE)/version.hpp

CONFIG_C_INCLUDES	= \
	$(CONFIG_INCLUDE)/config.h 					\
	$(CONFIG_INCLUDE)/config_c.h 					\
	$(CONFIG_INCLUDE)/config_complex.h 				\
	$(CONFIG_INCLUDE)/config_float.h				\
	$(CONFIG_INCLUDE)/config_int_char.h				\
	$(CONFIG_INCLUDE)/config_io.h					\
	$(CONFIG_INCLUDE)/macros.h					\
	$(CONFIG_INCLUDE)/os_fixinclude.h				\
	$(CONFIG_INCLUDE)/platform_include.h				\
	$(CONFIG_INCLUDE)/typed_call_macros.h

CONFIG_CPP_INCLUDES	= \
	$(CONFIG_INCLUDE)/config.hpp					\
	$(CONFIG_INCLUDE)/config_cpp.hpp				\
	$(CONFIG_INCLUDE)/macros.hpp

#-------------------------------------------------------------------------------
# Library include files
#
TC_INCLUDE		= ../libsltc/include
TST_INCLUDE		= ../libsltst/include

#-------------------------------------------------------------------------------
# Build path 
#
BUILD_PATH		= /home/rsergeant/projects/build/snowleopard

TC_BUILD_PATH		= $(BUILD_PATH)/libsltc
TST_BUILD_PATH		= $(BUILD_PATH)/libsltst

#-------------------------------------------------------------------------------
# Compiler options
#
COMPILE_FLAGS		= -std=c99 -Wall -Wextra -Werror
LIBRARY_FLAGS		= -fPIC
DEBUG_FLAGS		= -g $(CMD_LINE_DEBUG_FLAGS)

#-------------------------------------------------------------------------------
# Testing library
TST_PATH		= ../test

#-------------------------------------------------------------------------------
#-<EOF>
