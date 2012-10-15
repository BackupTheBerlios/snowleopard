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
# includes.mk
#-------------------------------------------------------------------------------
# Generated file containing a list of all includes files that are specific to
# the compiler front end.
#-------------------------------------------------------------------------------

#-------------------------------------------------------------------------------
# Variables
#
INCLUDES 		= \
	$(PRG_INCLUDE)/config_slcc.h 					\
	$(PRG_INCLUDE)/driver.h 					\
	$(PRG_INCLUDE)/error.h						\
	$(PRG_INCLUDE)/error_array.h					\
	$(PRG_INCLUDE)/error_codes.h					\
	$(PRG_INCLUDE)/error_handling.h					\
	$(PRG_INCLUDE)/info.h						\
	$(PRG_INCLUDE)/settings.h 					\
	$(PRG_INCLUDE)/string_array.h					\
	$(PRG_INCLUDE)/types.h 						\
	$(PRG_INCLUDE)/version_slcc.h

.include "../../libsltc/makefiles/includes.mk"

#-------------------------------------------------------------------------------
# Header file dependencies
#
CONFIG_SLCC_H_DEPS	= \
	$(CONFIG_C_INCLUDES)

DRIVER_H_DEPS		= \
	$(PRG_INCLUDE)/error_codes.h

ERROR_H_DEPS		= \
	$(PRG_INCLUDE)/error_codes.h

ERROR_ARRAY_H_DEPS	= \
	$(PRG_INCLUDE)/error.h						\
	$(TC_INCLUDES)

ERROR_CODES_H_DEPS	= \
	$(PRG_INCLUDE)/error.h						\
	$(PRG_INCLUDE)/error_array.h					\
	$(PRG_INCLUDE)/error_codes.h

INFO_H_DEPS		=

SETTINGS_H_DEPS		= \
	$(PRG_INCLUDE)/string_array.h

STRING_ARRAY_H_DEPS	= \
	$(TC_INCLUDES)

TYPES_H_DEPS		=

VERSION_SLCC_H_DEPS	= \
	$(PRG_INCLUDE)/config_slcc.h					\
	$(CONFIG_C_INCLUDES)

#-------------------------------------------------------------------------------
# Source file dependencies
#
DRIVER_DEPS		= \
	$(PRG_INCLUDE)/driver.h $(DRIVER_H_DEPS) 			\
	$(PRG_INCLUDE)/error_codes.h $(ERROR_CODES_H_DEPS)		\
	$(PRG_INCLUDE)/error_handling.h	$(ERROR_HANDLING_H_DEPS)	\
	$(PRG_INCLUDE)/settings.h $(SETTINGS_H_DEPS)			\
	$(TC_INCLUDES)

ERROR_ARRAY_DEPS	= \
	$(PRG_INCLUDE)/error.h	$(ERROR_H_DEPS)				\
	$(PRG_INCLUDE)/error_array.h $(ERROR_ARRY_H_DEPS)		\
	$(TC_INCLUDES)

ERROR_CODES_DEPS	= \
	$(PRG_INCLUDE)/error_codes.h $(ERROR_CODES_H_DEPS)

ERROR_HANDLING_DEPS	= \
	$(PRG_INCLUDE)/error.h $(ERROR_H_DEPS)				\
	$(PRG_INCLUDE)/error_array.h $(ERROR_ARRAY_H_DEPS)		\
	$(PRG_INCLUDE)/error_codes.h $(ERROR_CODES_H_DEPS)		\
	$(TC_INCLUDES)

INFO_DEPS		= \
	$(PRG_INCLUDE)/info.h $(INFO_H_DEPS)				\
	$(PRG_INCLUDE)/settings.h $(SETTINGS_H_DEPS)			\
	$(PRG_INCLUDE)/version_slcc.h $(VERSION_SLCC_H_DEPS)

MAIN_DEPS		= \
	$(PRG_INCLUDE)/driver.h $(DRIVER_H_DEPS)			\
	$(PRG_INCLUDE)/info.h $(INFO_H_DEPS)				\
	$(PRG_INCLUDE)/settings.h $(SETTINGS_H_DEPS)

SETTINGS_DEPS		= \
	$(PRG_INCLUDE)/error_codes.h $(ERROR_CODES_H_DEPS)		\
	$(PRG_INCLUDE)/error_handling.h $(ERROR_HANDLING_H_DEPS)	\
	$(PRG_INCLUDE)/settings.h $(SETTINGS_H_DEPS)			\
	$(PRG_INCLUDE)/string_array.h $(STRING_ARRAY_H_DEPS)		\
	$(TC_INCLUDES)

STRING_ARRAY_DEPS	= \
	$(PRG_INCLUDE)/string_array.h $(STRING_ARRAY_H_DEPS)		\
	$(TC_INCLUDES)

TYPES_DEPS		= \
	$(PRG_INCLUDE)/types.h $(TYPES_H_DEPS)

VERSION_SLCC_DEPS	= \
	$(PRG_INCLUDE)/config_slcc.h $(CONFIG_SLCC_H_DEPS)		\
	$(PRG_INCLUDE)/version_slcc.h $(VERSION_SLCC_H_DEPS)		\
	$(CONFIG_C_INCLUDES)

#-------------------------------------------------------------------------------
#<EOF>
