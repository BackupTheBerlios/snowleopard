#===============================================================================
# Snow Leopard Typed Component Library
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
# Makefile for building the Snow Leopard Typed Component Library
#-------------------------------------------------------------------------------

#-------------------------------------------------------------------------------
# Include files.
.include "../config/makefiles/config.mk"

.include "makefiles/version.mk"

#-------------------------------------------------------------------------------

#-------------------------------------------------------------------------------
# Variables
#
LIB_BUILD_PATH	= $(BUILD_PATH)/libsltc

STATIC_LIBRARY	= $(LIB_BUILD_PATH)/libsltc.a

SHARED_LIBRARY 	= $(LIB_BUILD_PATH)/libsltc.so.$(SHARED_LIB_VERSION)
SHARED_SO_NAME	= libsltc.so.$(SHARED_SO_VERSION)

LIB_INCLUDE	= include
INCLUDE_PATHS   = -I$(LIB_INCLUDE) -I$(CONFIG_INCLUDE)

CFLAGS		= $(INCLUDE_PATHS) $(COMPILE_FLAGS) $(LIBRARY_FLAGS) 	\
		  $(DEBUG_FLAGS)

.include "makefiles/objects.mk"
.include "makefiles/includes.mk"

#-------------------------------------------------------------------------------
# Rules
#
all			: $(STATIC_LIBRARY) $(SHARED_LIBRARY)

$(STATIC_LIBRARY)	: $(OBJS)
	$(AR) rcs $(STATIC_LIBRARY) $(OBJS)

$(SHARED_LIBRARY)	: $(OBJS)
	$(CC) -shared -Wl,-soname,$(SHARED_SO_NAME) -o $(SHARED_LIBRARY) $(OBJS)

$(OBJS)			: build_path $(INCLUDES) $(CONFIG_C_INCLUDES) \
			  $(VERSION_C_INCLUDES)

.include "makefiles/object_rules.mk"

#-------------------------------------------------------------------------------
# Special rules
#
build_path		:
	mkdir -p $(LIB_BUILD_PATH)

clean			:
	rm -rf $(OBJS)			\
	rm -rf $(STATIC_LIBRARY)	\
	rm -rf $(SHARED_LIBRARY)

distclean		: clean
	rmdir $(LIB_BUILD_PATH)

#-------------------------------------------------------------------------------
#-<EOF>
