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
PRG_BUILD_PATH	= $(BUILD_PATH)/slcc

PROGRAM 	= $(PRG_BUILD_PATH)/slcc

PRG_INCLUDE	= include
INCLUDE_PATHS 	= -I$(PRG_INCLUDE) -I$(CONFIG_INCLUDE)

COMPILER_OPTS	= $(INCLUDE_PATHS) $(COMPILE_FLAGS) $(DEBUG_FLAGS)

.include "makefiles/objects.mk"
.include "makefiles/includes.mk"

#-------------------------------------------------------------------------------
# Rules
#
$(PROGRAM) 	: $(OBJS)
	cc $(.ALLSRC) -o $(.TARGET)

$(OBJS)    	: build_path $(INCLUDES) $(CONFIG_C_INCLUDES) $(VERSION_C_INCLUDES)

.include "makefiles/object_rules.mk"

#-------------------------------------------------------------------------------
# Special rules
build_path	:
	mkdir -p $(PRG_BUILD_PATH)

clean		:
	rm -rf $(OBJS) 		\
	rm -rf $(PROGRAM)

distclean	: clean
	rmdir $(PRG_BUILD_PATH)

#-------------------------------------------------------------------------------
#-<EOF>
