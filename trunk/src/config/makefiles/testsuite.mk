#===============================================================================
# Snow Leopard Compiler Project
#
# Copyright (C) 2011, 2012 Roel Sergeant
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
# testsuite.mk
#-------------------------------------------------------------------------------
# Configuration include for the testsuite Makefiles
#-------------------------------------------------------------------------------

#-------------------------------------------------------------------------------
# Configuration include files
#
TST_CONFIG_INCLUDE		= ../../config/include

TST_VERSION_C_INCLUDES		= \
	$(TST_CONFIG_INCLUDE)/version.c.h				\
	$(TST_CONFIG_INCLUDE)/version.h

TST_VERSION_CXX_INCLUDES	= \
	$(TST_CONFIG_INCLUDE)/version.cpp.hpp				\
	$(TST_CONFIG_INCLUDE)/version.hpp

TST_CONFIG_C_INCLUDES		= \
	$(TST_CONFIG_INCLUDE)/config.h 					\
	$(TST_CONFIG_INCLUDE)/config_c.h 				\
	$(TST_CONFIG_INCLUDE)/config_complex.h 				\
	$(TST_CONFIG_INCLUDE)/config_float.h				\
	$(TST_CONFIG_INCLUDE)/config_int_char.h				\
	$(TST_CONFIG_INCLUDE)/config_io.h				\
	$(TST_CONFIG_INCLUDE)/macros.h					\
	$(TST_CONFIG_INCLUDE)/os_fixinclude.h				\
	$(TST_CONFIG_INCLUDE)/platform_include.h			\
	$(TST_CONFIG_INCLUDE)/typed_call_macros.h

TST_CONFIG_CPP_INCLUDES		= \
	$(TST_CONFIG_INCLUDE)/config.hpp				\
	$(TST_CONFIG_INCLUDE)/config_cpp.hpp				\
	$(TST_CONFIG_INCLUDE)/macros.hpp

#-------------------------------------------------------------------------------
# Library include files
#
TST_TC_INCLUDE			= ../../libsltc/include

#-------------------------------------------------------------------------------
# Build path 
#
TST_BUILD_PATH			= ../../../../../build/snowleopard/test

#-------------------------------------------------------------------------------
# Compiler options
#
TST_COMPILE_FLAGS		= -std=c99 -Wall -Wextra
TST_DEBUG_FLAGS			= -g

#-------------------------------------------------------------------------------
#-<EOF>
