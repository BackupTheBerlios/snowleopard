#===============================================================================
# Snow Leopard Build Tool
#
# Copyright (C) 2012 Roel Sergeant
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
# Makefile for building the Snow Leopard C++ Build Tool
#-------------------------------------------------------------------------------

#-------------------------------------------------------------------------------
# Include makefiles
#
.include "../config/makefiles/config.mk"

#-------------------------------------------------------------------------------
# Variables
#
#==============================================================================
# Program: slbld
SLBLD_PRG		= slbld

SLBLD_BUILD_PATH	= $(BUILD_PATH)/$(PRG)
SLBLD			= $(SLBLD_BUILD_PATH)/$(PRG)

SLBLD_INCLUDE		= include
SLBLD_INCLUDE_PATHS	= -I$(SLBLD_INCLUDE) -I$(TC_INCLUDE) -I$(CONFIG_INCLUDE)

SLBLD_CFLAGS		= \
	$(CFLAGS) $(INCLUDE_PATHS) $(COMPILE_FLAGS) $(DEBUG_FLAGS)

SLBLD_LIBRARIES		= $(TC_STATIC_LIBRARY)

SLBLD_TST_PATH		= $(TST_PATH)/$(SLBLD)
#==============================================================================

PROGRAMS		= $(SLBLD)

.include "makefiles/includes.mk"
.include "makefiles/dependencies.mk"
.include "makefiles/objects.mk"

#-------------------------------------------------------------------------------
# Rules
#
all		: build_path build_libraries $(PROGRAMS)

#==============================================================================
# Program: slbld
$(SLBLD) 	: $(SLBLD_OBJS)
	$(CC) $(.ALLSRC) -o $(.TARGET)
#==============================================================================

.include "makefiles/object_rules.mk"

#-------------------------------------------------------------------------------
# Special rules
build_path		:
	mkdir -p $(PRG_BUILD_PATH)

build_libraries 	:
	cd ../libsltc ;			\
	${MAKE} libsltc_static_library

distclean_libraries	:
	cd ../libsltc ;			\
	${MAKE} distclean

clean			:
	rm -rf $(OBJS) 			\
	rm -rf $(PROGRAM)

distclean		: clean distclean_libraries
	rm -rf $(PRG_BUILD_PATH)/* ;	\
	rmdir $(PRG_BUILD_PATH) ;

test		: $(PROGRAMS)
	cd $(PRG_TST_PATH) ;		\
	${MAKE}

#-------------------------------------------------------------------------------
#-<EOF>
