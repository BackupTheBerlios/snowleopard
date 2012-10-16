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
# includes.mk
#-------------------------------------------------------------------------------
# Generated file containing a list of all includes files that are specific to
# the typed component library.
#-------------------------------------------------------------------------------

#-------------------------------------------------------------------------------
# Variables
#
TC_INCLUDES 	= \
	$(TC_INCLUDE)/array.c.h						\
	$(TC_INCLUDE)/array.h						\
	$(TC_INCLUDE)/char_functions.h					\
	$(TC_INCLUDE)/config_tc.h 					\
	$(TC_INCLUDE)/file_functions.h					\
	$(TC_INCLUDE)/integer_functions.h				\
	$(TC_INCLUDE)/linked_list.c.h					\
	$(TC_INCLUDE)/linked_list.h					\
	$(TC_INCLUDE)/string_functions.h				\
	$(TC_INCLUDE)/tree.c.h 						\
	$(TC_INCLUDE)/tree.h						\
	$(TC_INCLUDE)/version_tc.h

#-------------------------------------------------------------------------------
# Header file dependencies
#
ARRAY_C_H_DEPS			= \
	$(TC_INCLUDE)/config_tc.h

ARRAY_H_DEPS			= \
	$(TC_INCLUDE)/config_tc.h

CHAR_FUNCTIONS_H_DEPS   	=

CONFIG_TC_H_DEPS		= \
	$(CONFIG_C_INCLUDES)

FILE_FUNCTIONS_H_DEPS		= 

INTEGER_FUNCTIONS_H_DEPS	=

LINKED_LIST_C_H_DEPS		= \
	$(TC_INCLUDE)/config_tc.h

LINKED_LIST_H_DEPS		= \
	$(TC_INCLUDE)/config_tc.h

TREE_C_H_DEPS			= \
	$(TC_INCLUDE)/config_tc.h

STRING_FUNCTIONS_H_DEPS		= \
	$(TC_INCLUDE)/string_functions.h

TREE_H_DEPS			= \
	$(TC_INCLUDE)/config_tc.h

VERSION_TC_H_DEPS		= \
	$(CONFIG_C_INCLUDES)						\
	$(VERSION_C_INCLUDES)

#-------------------------------------------------------------------------------
# Source file dependencies
#
CHAR_FUNCTIONS_DEPS		= \
	$(TC_INCLUDE)/char_functions.h $(CHAR_FUNCTIONS_H_DEPS)

FILE_FUNCTIONS_DEPS		= \
	$(TC_INCLUDE)/file_functions.h $(FILE_FUNCTIONS_H_DEPS)

INTEGER_FUNCTIONS_DEPS		= \
	$(TC_INCLUDE)/integer_functions.h $(INTEGER_FUNCTIONS_H_DEPS)

STRING_FUNCTIONS_DEPS	= \
	$(TC_INCLUDE)/string_functions.h $(STRING_FUNCTIONS_H_DEPS)

VERSION_TC_DEPS		= \
	$(TC_INCLUDE)/config_tc.h $(CONFIG_TC_H_DEPS)			\
	$(TC_INCLUDE)/version_tc.h $(VERSION_TC_H_DEPS)			\
	$(CONFIG_C_INCLUDES)						\
	$(VERSION_C_INCLUDES)

#-------------------------------------------------------------------------------
#<EOF>
