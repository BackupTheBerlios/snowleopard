#===============================================================================
# Snow Leopard C++ Compiler Front End
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
# Makefile for building the Snow Leopard C++ Compiler Front End
#-------------------------------------------------------------------------------

#-------------------------------------------------------------------------------
# Include makefiles
#
.include "../config/makefiles/config.mk"

#-------------------------------------------------------------------------------
# Variables
#
PRG		= slcc

PRG_BUILD_PATH	= $(BUILD_PATH)/$(PRG)
PROGRAM 	= $(PRG_BUILD_PATH)/$(PRG)

PRG_INCLUDE	= include
INCLUDE_PATHS 	= -I$(PRG_INCLUDE) -I$(TC_INCLUDE) -I$(CONFIG_INCLUDE)

CFLAGS		= $(INCLUDE_PATHS) $(COMPILE_FLAGS) $(DEBUG_FLAGS)

PRG_TST_PATH	= $(TST_PATH)/$(PRG)

.include "makefiles/includes.mk"
.include "makefiles/dependencies.mk"
.include "makefiles/objects.mk"

#-------------------------------------------------------------------------------
# Rules
#
all		: build_path build_libsltc_a $(PROGRAM)

$(PROGRAM) 	: $(OBJS)
	$(CC) $(.ALLSRC) -o $(.TARGET)

.include "makefiles/object_rules.mk"

#-------------------------------------------------------------------------------
# Special rules
build_path	:
	mkdir -p $(PRG_BUILD_PATH)

build_libsltc_a :
	cd ../libsltc ;			\
	${MAKE} static_library

clean		:
	rm -rf $(OBJS) 			\
	rm -rf $(PROGRAM)

distclean	: clean
	rm -rf $(PRG_BUILD_PATH)/* ;	\
	rmdir $(PRG_BUILD_PATH) ;	\
	cd ../libsltc ;			\
	${MAKE} distclean

test		: $(PROGRAM)
	cd $(PRG_TST_PATH) ;		\
	${MAKE}

#-------------------------------------------------------------------------------
#-<EOF>
