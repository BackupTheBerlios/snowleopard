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
# tst_config.mk
#-------------------------------------------------------------------------------
# Configuration include for all testing Makefiles
#-------------------------------------------------------------------------------

#-------------------------------------------------------------------------------
# Configuration include files
#
TST_CONFIG_INCLUDE		= ../config/include

TST_VERSION_C_INCLUDES		= \
	$(CONFIG_INCLUDE)/version.c.h					\
	$(CONFIG_INCLUDE)/version.h

TST_VERSION_CXX_INCLUDES	= \
	$(CONFIG_INCLUDE)/version.cpp.hpp				\
	$(CONFIG_INCLUDE)/version.hpp

TST_CONFIG_C_INCLUDES		= \
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

TST_CONFIG_CPP_INCLUDES		= \
	$(CONFIG_INCLUDE)/config.hpp					\
	$(CONFIG_INCLUDE)/config_cpp.hpp				\
	$(CONFIG_INCLUDE)/macros.hpp

#-------------------------------------------------------------------------------
# Library include files
#
TST_TC_INCLUDE			= ../../libsltc/include

#-------------------------------------------------------------------------------
# Build path 
#
TST_BUILD_PATH			= /home/rsergeant/projects/build/snowleopard/test

#-------------------------------------------------------------------------------
# Compiler options
#
TST_COMPILE_FLAGS		= -std=c99 -Wall -Wextra
TST_DEBUG_FLAGS			= -g

#-------------------------------------------------------------------------------
#-<EOF>
