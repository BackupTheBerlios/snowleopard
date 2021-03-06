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
# includes.mk
#-------------------------------------------------------------------------------
# Generated file containing a list of all includes files that are specific to
# the lynx typesetting system.
#-------------------------------------------------------------------------------

#-------------------------------------------------------------------------------
# Variables
#
INCLUDES 		= \
	$(PRG_INCLUDE)/config_lynx.h 					\
	$(PRG_INCLUDE)/driver.h 					\
	$(PRG_INCLUDE)/info.h						\
	$(PRG_INCLUDE)/settings.h					\
	$(PRG_INCLUDE)/string_array.h					\
	$(PRG_INCLUDE)/version_lynx.h

.include "../../libsltc/makefiles/includes.mk"

#-------------------------------------------------------------------------------
# Header file dependencies
#
CONFIG_LYNX_H_DEPS	= \
	$(CONFIG_C_INCLUDES)

DRIVER_H_DEPS		= 

INFO_H_DEPS		= \
	$(PRG_INCLUDE)/version_lynx.h

SETTINGS_H_DEPS		= \
	$(PRG_INCLUDE)/string_array.h

STRING_ARRAY_H_DEPS	= \
	$(TC_INCLUDES)

VERSION_LYNX_H_DEPS	= \
	$(PRG_INCLUDE)/config_lynx.h					\
	$(CONFIG_C_INCLUDES)

#-------------------------------------------------------------------------------
# Source file dependencies
#
DRIVER_DEPS		= \
	$(PRG_INCLUDE)/driver.h $(DRIVER_H_DEPS)			\
	$(PRG_INCLUDE)/settings.h $(SETTINGS_H_DEPS)

INFO_DEPS		= \
	$(PRG_INCLUDE)/info.h $(INFO_H_DEPS)				\
	$(PRG_INCLUDE)/settings.h $(SETTINGS_H_DEPS)			\
	$(PRG_INCLUDE)/version_lynx.h $(VERSION_LYNX_H_DEPS)

LFORMAT_DRIVER_DEPS	= \
	$(PRG_INCLUDE)/driver.h $(DRIVER_H_DEPS)			\
	$(PRG_INCLUDE)/settings.h $(SETTINGS_H_DEPS)

LEQN_DRIVER_DEPS	= \
	$(PRG_INCLUDE)/driver.h $(DRIVER_H_DEPS)			\
	$(PRG_INCLUDE)/settings.h $(SETTINGS_H_DEPS)

LGM_DRIVER_DEPS		= \
	$(PRG_INCLUDE)/driver.h $(DRIVER_H_DEPS)			\
	$(PRG_INCLUDE)/settings.h $(SETTINGS_H_DEPS)

LGRAP_DRIVER_DEPS	= \
	$(PRG_INCLUDE)/driver.h $(DRIVER_H_DEPS)			\
	$(PRG_INCLUDE)/settings.h $(SETTINGS_H_DEPS)

LIDEAL_DRIVER_DEPS	= \
	$(PRG_INCLUDE)/driver.h $(DRIVER_H_DEPS)			\
	$(PRG_INCLUDE)/settings.h $(SETTINGS_H_DEPS)

LPIC_DRIVER_DEPS	= \
	$(PRG_INCLUDE)/driver.h $(DRIVER_H_DEPS)			\
	$(PRG_INCLUDE)/settings.h $(SETTINGS_H_DEPS)

LREFER_DRIVER_DEPS	= \
	$(PRG_INCLUDE)/driver.h $(DRIVER_H_DEPS)			\
	$(PRG_INCLUDE)/settings.h $(SETTINGS_H_DEPS)

LROFF_DRIVER_DEPS	= \
	$(PRG_INCLUDE)/driver.h $(DRIVER_H_DEPS)			\
	$(PRG_INCLUDE)/settings.h $(SETTINGS_H_DEPS)

LSOELIM_DRIVER_DEPS	= \
	$(PRG_INCLUDE)/driver.h $(DRIVER_H_DEPS)			\
	$(PRG_INCLUDE)/settings.h $(SETTINGS_H_DEPS)			\
	$(PRG_INCLUDE)/string_array.h $(STRING_ARRAY_H_DEPS)

LTBL_DRIVER_DEPS	= \
	$(PRG_INCLUDE)/driver.h $(DRIVER_H_DEPS)			\
	$(PRG_INCLUDE)/settings.h $(SETTINGS_H_DEPS)

LYNX_DRIVER_DEPS	= \
	$(PRG_INCLUDE)/driver.h $(DRIVER_H_DEPS)			\
	$(PRG_INCLUDE)/settings.h $(SETTINGS_H_DEPS)

MAIN_DEPS		= \
	$(PRG_INCLUDE)/driver.h $(DRIVER_H_DEPS)			\
	$(PRG_INCLUDE)/info.h $(INFO_H_DEPS)

SETTINGS_DEPS		=\
	$(PRG_INCLUDE)/settings.h $(SETTINGS_H_DEPS)			\
	$(PRG_INCLUDE)/string_array.h $(SETTINGS_H_DEPS)		\
	$(TC_INCLUDES)

STRING_ARRAY_DEPS	=\
	$(PRG_INCLUDE)/string_array.h $(STRING_ARRAY_H_DEPS)		\
	$(TC_INCLUDES)

VERSION_LYNX_DEPS	= \
	$(PRG_INCLUDE)/config_lynx.h $(CONFIG_LYNX_H_DEPS)		\
	$(PRG_INCLUDE)/version_lynx.h $(VERSION_LYNX_H_DEPS)		\
	$(CONFIG_C_INCLUDES)

#-------------------------------------------------------------------------------
#<EOF>
