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
	$(PRG_INCLUDE)/codegen.h					\
	$(PRG_INCLUDE)/config_slcc.h 					\
	$(PRG_INCLUDE)/driver.h 					\
	$(PRG_INCLUDE)/error.h						\
	$(PRG_INCLUDE)/error_array.h					\
	$(PRG_INCLUDE)/error_codes.h					\
	$(PRG_INCLUDE)/error_handling.h					\
	$(PRG_INCLUDE)/hash_function.h					\
	$(PRG_INCLUDE)/info.h						\
	$(PRG_INCLUDE)/parse_tree.h					\
	$(PRG_INCLUDE)/parser.h						\
	$(PRG_INCLUDE)/reader.h						\
	$(PRG_INCLUDE)/settings.h 					\
	$(PRG_INCLUDE)/source_file.h					\
	$(PRG_INCLUDE)/source_object.h					\
	$(PRG_INCLUDE)/source_position.h				\
	$(PRG_INCLUDE)/source_string.h					\
	$(PRG_INCLUDE)/string_array.h					\
	$(PRG_INCLUDE)/strings.h					\
	$(PRG_INCLUDE)/token.h						\
	$(PRG_INCLUDE)/types.h 						\
	$(PRG_INCLUDE)/version_slcc.h

.include "../../libsltc/makefiles/includes.mk"

#-------------------------------------------------------------------------------
# Header file dependencies
#
CODEGEN_H_DEPS		= 

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
	$(PRG_INCLUDE)/error_array.h

ERROR_HANDLING_H_DEPS	= \
	$(PRG_INCLUDE)/error.h						\
	$(PRG_INCLUDE)/error_array.h					\
	$(PRG_INCLUDE)/error_codes.h

HASH_FUNCTION_H_DEPS	= \
	$(PRG_INCLUDE)/types.h

INFO_H_DEPS		=

LITERAL_H_DEPS		= \
	$(PRG_INCLUDE)/config_slcc.h					\
	$(CONFIG_C_INCLUDES)

PARSE_TREE_H_DEPS	= \
	$(PRG_INCLUDE)/source_object.h					\
	$(TC_INCLUDES)

PARSER_H_DEPS		=

READER_H_DEPS		= \
	$(PRG_INCLUDE)/source_file.h					\
	$(PRG_INCLUDE)/source_position.h				\
	$(PRG_INCLUDE)/source_string.h

SETTINGS_H_DEPS		= \
	$(PRG_INCLUDE)/string_array.h

SOURCE_FILE_H_DEPS	=

SORUCE_POSITION_H_DEPS	= \
	$(PRG_INCLUDE)/source_file.h					\
	$(PRG_INCLUDE)/source_string.h

SOURCE_OBJECTS_H_DEPS	= \
	$(PRG_INCLUDE)/types.h

SOURCE_STRING_H_DEPS	=

STRING_ARRAY_H_DEPS	= \
	$(TC_INCLUDES)

STRINGS_H_DEPS		= \
	$(PRG_INCLUDE)/config_slcc.h					\
	$(CONFIG_C_INCLUDES)

TOKEN_H_DEPS		= \
	$(PRG_INCLUDE)/literal.h					\
	$(PRG_INCLUDE)/source_position.h				\
	$(PRG_INCLUDE)/strings.h					\
	$(PRG_INCLUDE)/types.h						\
	$(CONFIG_C_INCLUDES)

TYPES_H_DEPS		=

VERSION_SLCC_H_DEPS	= \
	$(PRG_INCLUDE)/config_slcc.h					\
	$(CONFIG_C_INCLUDES)

#-------------------------------------------------------------------------------
# Source file dependencies
#
CODEGEN_DEPS		= \
	$(PRG_INCLUDE)/codegen.h $(CODEGEN_H_DEPS)

DRIVER_DEPS		= \
	$(PRG_INCLUDE)/driver.h $(DRIVER_H_DEPS) 			\
	$(PRG_INCLUDE)/error.h $(ERROR_H_DEPS)				\
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
	$(PRG_INCLUDE)/error_handling.h $(ERROR_HANDLING_H_DEPS)	\
	$(TC_INCLUDES)

HASH_FUNCTION_DEPS	= \
	$(PRG_INCLUDE)/hash_function.h $(HASH_FUNCTIONS_H_DEPS)		\
	$(PRG_INCLUDE)/types.h $(TYPES_H_DEPS)

INFO_DEPS		= \
	$(PRG_INCLUDE)/info.h $(INFO_H_DEPS)				\
	$(PRG_INCLUDE)/settings.h $(SETTINGS_H_DEPS)			\
	$(PRG_INCLUDE)/version_slcc.h $(VERSION_SLCC_H_DEPS)

LITERAL_DEPS		= \
	$(PRG_INCLUDE)/literal.h $(LITERAL_H_DEPS)

MAIN_DEPS		= \
	$(PRG_INCLUDE)/driver.h $(DRIVER_H_DEPS)			\
	$(PRG_INCLUDE)/error_handling.h $(ERROR_HANDLING_H_DEPS)	\
	$(PRG_INCLUDE)/info.h $(INFO_H_DEPS)				\
	$(PRG_INCLUDE)/settings.h $(SETTINGS_H_DEPS)

PARSE_TREE_DEPS		= \
	$(PRG_INCLUDE)/parse_tree.h $(PARSE_TREE_H_DEPS)		\
	$(PRG_INCLUDE)/source_object.h $(SOURCE_OBJECT_H_DEPS)		\
	$(TC_INCLUDES)

PARSER_DEPS		= \
	$(PRG_INCLUDE)/parse_tree.h $(PARSE_TREE_H_DEPS)		\
	$(PRG_INCLUDE)/parser.h $(PARSER_H_DEPS)

READER_DEPS		= \
	$(PRG_INCLUDE)/reader.h $(READER_H_DEPS)			\
	$(PRG_INCLUDE)/settings.h $(SETTINGS_H_DEPS)			\
	$(PRG_INCLUDE)/source_position.h $(SOURCE_POSITION_H_DEPS)	\
	$(TC_INCLUDES)

SETTINGS_DEPS		= \
	$(PRG_INCLUDE)/error_codes.h $(ERROR_CODES_H_DEPS)		\
	$(PRG_INCLUDE)/error_handling.h $(ERROR_HANDLING_H_DEPS)	\
	$(PRG_INCLUDE)/settings.h $(SETTINGS_H_DEPS)			\
	$(PRG_INCLUDE)/string_array.h $(STRING_ARRAY_H_DEPS)		\
	$(TC_INCLUDES)

SOURCE_FILE_DEPS	= \
	$(PRG_INCLUDE)/source_file.h $(SOURCE_FILE_H_DEPS)

SOURCE_POSITION_DEPS	= \
	$(PRG_INCLUDE)/source_file.h $(SOURCE_FILE_H_DEPS)		\
	$(PRG_INCLUDE)/source_position.h $(SOURCE_POSITION_H_DEPS)	\
	$(PRG_INCLUDE)/source_string.h $(SOURCE_STRING_H_DEPS)

SOURCE_STRING_DEPS	= \
	$(PRG_INCLUDE)/source_string.h $(SOURCE_STRING_H_DEPS)

STRING_ARRAY_DEPS	= \
	$(PRG_INCLUDE)/string_array.h $(STRING_ARRAY_H_DEPS)		\
	$(TC_INCLUDES)

TOKEN_DEPS		= \
	$(PRG_INCLUDE)/token.h $(TOKEN_H_DEPS)

TYPES_DEPS		= \
	$(PRG_INCLUDE)/types.h $(TYPES_H_DEPS)

VERSION_SLCC_DEPS	= \
	$(PRG_INCLUDE)/config_slcc.h $(CONFIG_SLCC_H_DEPS)		\
	$(PRG_INCLUDE)/version_slcc.h $(VERSION_SLCC_H_DEPS)		\
	$(CONFIG_C_INCLUDES)

#-------------------------------------------------------------------------------
#<EOF>
