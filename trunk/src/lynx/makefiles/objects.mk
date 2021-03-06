#===============================================================================
# Lynx Typesetting System
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
# objects.mk
#-------------------------------------------------------------------------------
# Generated file containing the object files used for the lynx typesetting 
# system.
#-------------------------------------------------------------------------------

LDFORMAT_OBJS 		= \
	$(PRG_BUILD_PATH)/driver.o					\
	$(PRG_BUILD_PATH)/info.o					\
	$(PRG_BUILD_PATH)/ldformat_driver.o 				\
	$(PRG_BUILD_PATH)/main.o					\
	$(PRG_BUILD_PATH)/settings.o					\
	$(PRG_BUILD_PATH)/string_array.o				\
	$(PRG_BUILD_PATH)/version_lynx.o				\
	$(TC_BUILD_PATH)/libsltc.a

LEQN_OBJS 		= \
	$(PRG_BUILD_PATH)/driver.o					\
	$(PRG_BUILD_PATH)/info.o					\
	$(PRG_BUILD_PATH)/leqn_driver.o 				\
	$(PRG_BUILD_PATH)/main.o					\
	$(PRG_BUILD_PATH)/settings.o					\
	$(PRG_BUILD_PATH)/string_array.o				\
	$(PRG_BUILD_PATH)/version_lynx.o				\
	$(TC_BUILD_PATH)/libsltc.a

LGM_OBJS 		= \
	$(PRG_BUILD_PATH)/driver.o					\
	$(PRG_BUILD_PATH)/info.o					\
	$(PRG_BUILD_PATH)/lgm_driver.o 					\
	$(PRG_BUILD_PATH)/main.o					\
	$(PRG_BUILD_PATH)/settings.o					\
	$(PRG_BUILD_PATH)/string_array.o				\
	$(PRG_BUILD_PATH)/version_lynx.o				\
	$(TC_BUILD_PATH)/libsltc.a

LGRAP_OBJS 		= \
	$(PRG_BUILD_PATH)/driver.o					\
	$(PRG_BUILD_PATH)/info.o					\
	$(PRG_BUILD_PATH)/lgrap_driver.o 				\
	$(PRG_BUILD_PATH)/main.o					\
	$(PRG_BUILD_PATH)/settings.o					\
	$(PRG_BUILD_PATH)/string_array.o				\
	$(PRG_BUILD_PATH)/version_lynx.o				\
	$(TC_BUILD_PATH)/libsltc.a

LIDEAL_OBJS 		= \
	$(PRG_BUILD_PATH)/driver.o					\
	$(PRG_BUILD_PATH)/info.o					\
	$(PRG_BUILD_PATH)/lideal_driver.o 				\
	$(PRG_BUILD_PATH)/main.o					\
	$(PRG_BUILD_PATH)/settings.o					\
	$(PRG_BUILD_PATH)/string_array.o				\
	$(PRG_BUILD_PATH)/version_lynx.o				\
	$(TC_BUILD_PATH)/libsltc.a

LPIC_OBJS 		= \
	$(PRG_BUILD_PATH)/driver.o					\
	$(PRG_BUILD_PATH)/info.o					\
	$(PRG_BUILD_PATH)/lpic_driver.o 				\
	$(PRG_BUILD_PATH)/main.o					\
	$(PRG_BUILD_PATH)/settings.o					\
	$(PRG_BUILD_PATH)/string_array.o				\
	$(PRG_BUILD_PATH)/version_lynx.o				\
	$(TC_BUILD_PATH)/libsltc.a

LREFER_OBJS 		= \
	$(PRG_BUILD_PATH)/driver.o					\
	$(PRG_BUILD_PATH)/info.o					\
	$(PRG_BUILD_PATH)/lrefer_driver.o 				\
	$(PRG_BUILD_PATH)/main.o					\
	$(PRG_BUILD_PATH)/settings.o					\
	$(PRG_BUILD_PATH)/string_array.o				\
	$(PRG_BUILD_PATH)/version_lynx.o				\
	$(TC_BUILD_PATH)/libsltc.a

LROFF_OBJS 		= \
	$(PRG_BUILD_PATH)/driver.o					\
	$(PRG_BUILD_PATH)/info.o					\
	$(PRG_BUILD_PATH)/lroff_driver.o 				\
	$(PRG_BUILD_PATH)/main.o					\
	$(PRG_BUILD_PATH)/settings.o					\
	$(PRG_BUILD_PATH)/string_array.o				\
	$(PRG_BUILD_PATH)/version_lynx.o				\
	$(TC_BUILD_PATH)/libsltc.a

LSOELIM_OBJS 		= \
	$(PRG_BUILD_PATH)/driver.o					\
	$(PRG_BUILD_PATH)/info.o					\
	$(PRG_BUILD_PATH)/lsoelim_driver.o 				\
	$(PRG_BUILD_PATH)/main.o					\
	$(PRG_BUILD_PATH)/settings.o					\
	$(PRG_BUILD_PATH)/string_array.o				\
	$(PRG_BUILD_PATH)/version_lynx.o				\
	$(TC_BUILD_PATH)/libsltc.a

LTBL_OBJS 		= \
	$(PRG_BUILD_PATH)/driver.o					\
	$(PRG_BUILD_PATH)/info.o					\
	$(PRG_BUILD_PATH)/ltbl_driver.o 				\
	$(PRG_BUILD_PATH)/main.o					\
	$(PRG_BUILD_PATH)/settings.o					\
	$(PRG_BUILD_PATH)/string_array.o				\
	$(PRG_BUILD_PATH)/version_lynx.o				\
	$(TC_BUILD_PATH)/libsltc.a

LYNX_OBJS 		= \
	$(PRG_BUILD_PATH)/driver.o					\
	$(PRG_BUILD_PATH)/info.o					\
	$(PRG_BUILD_PATH)/lynx_driver.o 				\
	$(PRG_BUILD_PATH)/main.o					\
	$(PRG_BUILD_PATH)/settings.o					\
	$(PRG_BUILD_PATH)/string_array.o				\
	$(PRG_BUILD_PATH)/version_lynx.o				\
	$(TC_BUILD_PATH)/libsltc.a

OBJS			= \
	$(LDFORMAT_OBJS) $(LEQN_OBJS) $(LGM_OBJS) $(LGRAP_OBJS)		\
	$(LIDEAL_OBJS) $(LPIC_OBJS) $(LREFER_OBJS) $(LROFF_OBJS)	\
	$(LSOELIM_OBJS) $(LTBL_OBJS) $(LYNX_OBJS)

#-------------------------------------------------------------------------------
#<EOF>
