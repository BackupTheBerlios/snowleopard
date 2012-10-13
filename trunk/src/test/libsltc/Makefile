#===============================================================================
# Snow Leopard Test Suite
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
# Makefile
#-------------------------------------------------------------------------------
# Makefile for the typed component library testsuite
#-------------------------------------------------------------------------------

#-------------------------------------------------------------------------------
# Include files.
.include "../../config/makefiles/testsuite.mk"

#-------------------------------------------------------------------------------

#-------------------------------------------------------------------------------
# Variables
#
TST_RT_PATH		= $(TST_BUILD_PATH)/libsltc/rt
TST_TT_PATH		= $(TST_BUILD_PATH)/libsltc/tt
TST_UT_PATH		= $(TST_BUILD_PATH)/libsltc/ut

INCLUDE_PATHS   	= -I$(TST_TC_INCLUDE) -I$(TST_CONFIG_INCLUDE) \
			  -I$(TST_TST_INCLUDE)

CFLAGS			= $(INCLUDE_PATHS) $(TST_COMPILE_FLAGS) $(DEBUG_FLAGS)

#-------------------------------------------------------------------------------
# Regression tests
#

#-------------------------------------------------------------------------------
# Technical tests
#

#-------------------------------------------------------------------------------
# Unit tests
#
.include "unit_test/makefiles/objects.mk"
.include "unit_test/makefiles/includes.mk"

all			: $(UT_PROGRAMS)

$(UT_OBJS)		: build_path $(UT_INCLUDES) $(TST_CONFIG_C_INCLUDES) \
			  $(TST_VERSION_C_INCLUDES)

.include "unit_test/makefiles/object_rules.mk"

#-------------------------------------------------------------------------------
# Special rules
#
build_path		:
	mkdir -p $(TST_RT_PATH) ;			\
	mkdir -p $(TST_TT_PATH) ;			\
	mkdir -p $(TST_UT_PATH)

clean			:
	rm -rf $(TST_RT_PATH)/*	;		\
	rm -rf $(TST_TT_PATH)/*	;		\
	rm -rf $(UT_OBJS) $(UT_PROGRAMS)

distclean		: clean
	rmdir $(TST_RT_PATH)	;		\
	rmdir $(TST_TT_PATH)	;		\
	rmdir $(TST_UT_PATH)    ;		\
	rmdir $(TST_BUILD_PATH)/libsltc

#-------------------------------------------------------------------------------
#-<EOF>
