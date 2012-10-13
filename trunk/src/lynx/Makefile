#===============================================================================
# Lynx Typesetting System
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
# Makefile
#-------------------------------------------------------------------------------
# Makefile for building the Lynx typesetting system.
#-------------------------------------------------------------------------------

#-------------------------------------------------------------------------------
# Include makefiles
#
.include "../config/makefiles/config.mk"

#-------------------------------------------------------------------------------
# Variables
#
PRG		= lynx

LDFORMAT	= $(PRG_BUILD_PATH)/ldformat
LEQN		= $(PRG_BUILD_PATH)/leqn
LGM		= $(PRG_BUILD_PATH)/lgm
LGRAP		= $(PRG_BUILD_PATH)/lgrap
LIDEAL		= $(PRG_BUILD_PATH)/lideal
LPIC		= $(PRG_BUILD_PATH)/lpic
LREFER		= $(PRG_BUILD_PATH)/lrefer
LROFF		= $(PRG_BUILD_PATH)/lroff
LSOELIM		= $(PRG_BUILD_PATH)/lsoelim
LTBL		= $(PRG_BUILD_PATH)/ltbl
LYNX		= $(PRG_BUILD_PATH)/lynx

PRG_BUILD_PATH	= $(BUILD_PATH)/$(PRG)
PROGRAMS 	= $(LDFORMAT) $(LEQN) $(LGM) $(LGRAP) $(LIDEAL) $(LPIC) \
		  $(LREFER) $(LROFF) $(LSOELIM) $(LTBL) $(LYNX)

PRG_INCLUDE	= include
INCLUDE_PATHS 	= -I$(PRG_INCLUDE) -I$(TC_INCLUDE) -I$(CONFIG_INCLUDE)

CFLAGS		= $(INCLUDE_PATHS) $(COMPILE_FLAGS) $(DEBUG_FLAGS)

PRG_TST_PATH	= $(TST_PATH)/$(PRG)

.include "makefiles/objects.mk"
.include "makefiles/includes.mk"

#-------------------------------------------------------------------------------
# Rules
#
all		: build_path $(PROGRAMS)

$(LDFORMAT) 	: $(LDFORMAT_OBJS)
	$(CC) $(.ALLSRC) -o $(.TARGET)

$(LEQN)		: $(LEQN_OBJS)
	$(CC) $(.ALLSRC) -o $(.TARGET)

$(LGM)		: $(LGM_OBJS)
	$(CC) $(.ALLSRC) -o $(.TARGET)

$(LGRAP)	: $(LGRAP_OBJS)
	$(CC) $(.ALLSRC) -o $(.TARGET)

$(LIDEAL)	: $(LIDEAL_OBJS)
	$(CC) $(.ALLSRC) -o $(.TARGET)

$(LPIC)		: $(LPIC_OBJS)
	$(CC) $(.ALLSRC) -o $(.TARGET)

$(LREFER)	: $(LREFER_OBJS)
	$(CC) $(.ALLSRC) -o $(.TARGET)

$(LROFF)	: $(LROFF_OBJS)
	$(CC) $(.ALLSRC) -o $(.TARGET)

$(LSOELIM)	: $(LSOELIM_OBJS)
	$(CC) $(.ALLSRC) -o $(.TARGET)

$(LTBL)		: $(LTBL_OBJS)
	$(CC) $(.ALLSRC) -o $(.TARGET)

$(LYNX)		: $(LYNX_OBJS)
	$(CC) $(.ALLSRC) -o $(.TARGET)

.include "makefiles/object_rules.mk"

#-------------------------------------------------------------------------------
# Special rules
build_path	:
	mkdir -p $(PRG_BUILD_PATH)

clean		:
	rm -rf $(OBJS) 		\
	rm -rf $(PROGRAMS)

distclean	: clean
	rmdir $(PRG_BUILD_PATH)

test		: $(PROGRAMS)
	cd $(PRG_TST_PATH) ;	\
	${MAKE}

#-------------------------------------------------------------------------------
#-<EOF>
