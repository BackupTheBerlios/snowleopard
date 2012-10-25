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
# dependencies.mk
#-------------------------------------------------------------------------------
# Generated file containing a list of all include file dependencies that are 
# specific to the compiler front end.
#-------------------------------------------------------------------------------

#-------------------------------------------------------------------------------
# Header file dependencies
#
ARGUMENTS_H_DEPS		= \
	$(PRG_INCLUDE)/token.h						\
	$(PRG_INCLUDE)/types.h

BINARY_SEARCH_H_DEPS		= \
	$(PRG_INCLUDE)/strings.h

BUILT_IN_IDENTIFIERS_H_DEPS	=

BUILT_IN_TYPES_H_DEPS		=

CODEGEN_H_DEPS			= 

CONFIG_SLCC_H_DEPS		= \
	$(CONFIG_C_INCLUDES)

CONSTRUCTS_H_DEPS		= \
	$(PRG_INCLUDE)/statements.h

CPP_SYMTAB_H_DEPS		= \
	$(PRG_INCLUDE)/symbol_table.h

DEBUG_H_DEPS			=

DEBUG_FUNCTIONS_H_DEPS		=

DECLARATIONS_H_DEPS		= \
	$(PRG_INCLUDE)/definitions.h					\
	$(PRG_INCLUDE)/specifiers.h					\
	$(PRG_INCLUDE)/types.h

DEFINITIONS_H_DEPS		= \
	$(PRG_INCLUDE)/built_in_types.h					\
	$(PRG_INCLUDE)/specifiers.h					\
	$(PRG_INCLUDE)/source_object_array.h				\
	$(PRG_INCLUDE)/source_object_f.h				\
	$(PRG_INCLUDE)/types.h

DRIVER_H_DEPS			= \
	$(PRG_INCLUDE)/error_codes.h

ERROR_H_DEPS			= \
	$(PRG_INCLUDE)/error_codes.h					\
	$(PRG_INCLUDE)/source_position.h				

ERROR_ARRAY_H_DEPS		= \
	$(PRG_INCLUDE)/error.h						\
	$(TC_INCLUDES)

ERROR_CODES_H_DEPS		= \
	$(PRG_INCLUDE)/error.h						\
	$(PRG_INCLUDE)/error_array.h

ERROR_HANDLING_H_DEPS		= \
	$(PRG_INCLUDE)/error.h						\
	$(PRG_INCLUDE)/error_array.h					\
	$(PRG_INCLUDE)/error_codes.h					\
	$(PRG_INCLUDE)/source_position.h

FEATURES_H_DEPS			=

HASH_FUNCTION_H_DEPS		= \
	$(PRG_INCLUDE)/types.h

INFO_H_DEPS			=

LEXER_H_DEPS			= \
	$(PRG_INCLUDE)/source_position.h				\
	$(PRG_INCLUDE)/token.h

LEXER_FUNCTIONS_H_DEPS		= \
	$(PRG_INCLUDE)/config_slcc.h					\
	$(PRG_INCLUDE)/strings.h					\
	$(CONFIG_C_INCLUDES)

LITERAL_H_DEPS			= \
	$(PRG_INCLUDE)/config_slcc.h					\
	$(CONFIG_C_INCLUDES)

MACROS_SLCC_H_DEPS		=

OPTIMIZE_FLAGS_H_DEPS		=

PARSE_TREE_H_DEPS		= \
	$(PRG_INCLUDE)/source_object.h					\
	$(TC_INCLUDES)

PARSER_H_DEPS			=

PREPROCESSOR_H_DEPS		= \
	$(PRG_INCLUDE)/preprocessor.h

PREPROCESSOR_SYMTAB_H_DEPS	= \
	$(PRG_INCLUDE)/symbol_table.h

READER_H_DEPS			= \
	$(PRG_INCLUDE)/source_file.h					\
	$(PRG_INCLUDE)/source_position.h				\
	$(PRG_INCLUDE)/source_string.h

SETTINGS_H_DEPS			= \
	$(PRG_INCLUDE)/features.h					\
	$(PRG_INCLUDE)/optimize_flags.h					\
	$(PRG_INCLUDE)/string_array.h					\
	$(PRG_INCLUDE)/warnings.h

SOURCE_FILE_H_DEPS		=

SORUCE_POSITION_H_DEPS		= \
	$(PRG_INCLUDE)/source_file.h					\
	$(PRG_INCLUDE)/source_string.h

SOURCE_OBJECT_H_DEPS		= \
	$(PRG_INCLUDE)/constructs.h					\
	$(PRG_INCLUDE)/declarations.h					\
	$(PRG_INCLUDE)/source_object_f.h				\
	$(PRG_INCLUDE)/statements.h					\
	$(PRG_INCLUDE)/templates.h					\
	$(PRG_INCLUDE)/types.h

SOURCE_OBJECT_ARRAY_H_DEPS	= \
	$(PRG_INCLUDE)/source_object_f.h				\
	$(TC_INCLUDES)

SOURCE_OBJECT_F_H_DEPS		= \

SOURCE_STRING_H_DEPS		=

SPECIFIERS_H_DEPS		= \
	$(PRG_INCLUDE)/types.h

STATEMENTS_H_DEPS		= \
	$(PRG_INCLUDE)/arguments.h

STRING_ARRAY_H_DEPS		= \
	$(TC_INCLUDES)

STRINGS_H_DEPS			= \
	$(PRG_INCLUDE)/config_slcc.h					\
	$(CONFIG_C_INCLUDES)

SYMBOL_TABLE_H_DEPS		= \
	$(PRG_INCLUDE)/definitions.h					\
	$(PRG_INCLUDE)/hash_function.h					\
	$(PRG_INCLUDE)/source_position.h				\
	$(PRG_INCLUDE)/token.h						\
	$(PRG_INCLUDE)/types.h

TEMPLATES_H_DEPS		=

TOKEN_H_DEPS			= \
	$(PRG_INCLUDE)/literal.h					\
	$(PRG_INCLUDE)/source_position.h				\
	$(PRG_INCLUDE)/strings.h					\
	$(PRG_INCLUDE)/types.h						\
	$(CONFIG_C_INCLUDES)

TYPES_H_DEPS			=

VERSION_SLCC_H_DEPS		= \
	$(PRG_INCLUDE)/config_slcc.h					\
	$(CONFIG_C_INCLUDES)

WARNINGS_H_DEPS			=

#-------------------------------------------------------------------------------
# Source file dependencies
#
BINARY_SEARCH_DEPS		= \
	$(PRG_INCLUDE)/binary_search.h $(BINARY_SEARCH_H_DEPS)		\
	$(PRG_INCLUDE)/strings.h $(STRINGS_H_DEPS)			\
	$(PRG_INCLUDE)/types.h $(TYPES_H_DEPS)

CPP_SYMTAB_DEPS			= \
	$(PRG_INCLUDE)/cpp_symtab.h $(CPP_SYMTAB_H_DEPS)		\
	$(PRG_INCLUDE)/error_codes.h $(ERROR_CODES_H_DEPS)		\
	$(PRG_INCLUDE)/error_handling.h $(ERROR_HANDLING_H_DEPS)	\
	$(PRG_INCLUDE)/hash_function.h $(HASH_FUNCTION_H_DEPS)		\
	$(PRG_INCLUDE)/symbol_table.h $(SYMBOL_TABLE_H_DEPS)

CPP_SYMTAB_BUILT_IN_DEPS	= \
	$(PRG_INCLUDE)/built_in_identifiers.h 				\
		$(BUILT_IN_IDENTIFIERS_H_DEPS)				\
	$(PRG_INCLUDE)/built_in_types.h $(BUILT_IN_TYPES_H_DEPS)	\
	$(PRG_INCLUDE)/cpp_symtab.h $(CPP_SYMTAB_H_DEPS)		\
	$(PRG_INCLUDE)/source_position.h $(SOURCE_POSITION_H_DEPS)	\
	$(PRG_INCLUDE)/strings.h $(STRINGS_H_DEPS)			\
	$(PRG_INCLUDE)/symbol_table.h $(SYMBOL_TABLE_H_DEPS)		\
	$(PRG_INCLUDE)/token.h $(TOKEN_H_DEPS)

CODEGEN_DEPS			= \
	$(PRG_INCLUDE)/codegen.h $(CODEGEN_H_DEPS)

DEFINITIONS_DEPS		= \
	$(PRG_INCLUDE)/built_in_types.h $(BUILT_IN_TYPES_H_DEPS)	\
	$(PRG_INCLUDE)/definitions.h $(DEFINITIONS_H_DEPS)		\
	$(PRG_INCLUDE)/types.h $(TYPES_H_DEPS)

DRIVER_DEPS			= \
	$(PRG_INCLUDE)/codegen.h $(CODEGEN_H_DEPS)			\
	$(PRG_INCLUDE)/driver.h $(DRIVER_H_DEPS) 			\
	$(PRG_INCLUDE)/error.h $(ERROR_H_DEPS)				\
	$(PRG_INCLUDE)/error_codes.h $(ERROR_CODES_H_DEPS)		\
	$(PRG_INCLUDE)/error_handling.h	$(ERROR_HANDLING_H_DEPS)	\
	$(PRG_INCLUDE)/parser.h $(PARSER_H_DEPS)			\
	$(PRG_INCLUDE)/settings.h $(SETTINGS_H_DEPS)

DRIVER_ARGUMENTS_DEPS		= \
	$(PRG_INCLUDE)/driver.h $(DRIVER_H_DEPS) 			\
	$(PRG_INCLUDE)/error.h $(ERROR_H_DEPS)				\
	$(PRG_INCLUDE)/error_codes.h $(ERROR_CODES_H_DEPS)		\
	$(PRG_INCLUDE)/error_handling.h	$(ERROR_HANDLING_H_DEPS)	\
	$(PRG_INCLUDE)/features.h $(FEATURES_H_DEPS)			\
	$(PRG_INCLUDE)/macros_slcc.h $(MACROS_SLCC_H_DEPS)		\
	$(PRG_INCLUDE)/optimize_flags.h $(OPTIMIZE_FLAGS_H_DEPS)	\
	$(PRG_INCLUDE)/settings.h $(SETTINGS_H_DEPS)			\
	$(PRG_INCLUDE)/warnings.h $(WARNINGS_H_DEPS)			\
	$(TC_INCLUDES)

ERROR_ARRAY_DEPS		= \
	$(PRG_INCLUDE)/error.h	$(ERROR_H_DEPS)				\
	$(PRG_INCLUDE)/error_array.h $(ERROR_ARRY_H_DEPS)		\
	$(TC_INCLUDES)

ERROR_CODES_DEPS		= \
	$(PRG_INCLUDE)/error_codes.h $(ERROR_CODES_H_DEPS)

ERROR_HANDLING_DEPS		= \
	$(PRG_INCLUDE)/error.h $(ERROR_H_DEPS)				\
	$(PRG_INCLUDE)/error_array.h $(ERROR_ARRAY_H_DEPS)		\
	$(PRG_INCLUDE)/error_codes.h $(ERROR_CODES_H_DEPS)		\
	$(PRG_INCLUDE)/error_handling.h $(ERROR_HANDLING_H_DEPS)	\
	$(PRG_INCLUDE)/source_position.h $(SOURCE_POSITION_H_DEPS)	\
	$(PRG_INCLUDE)/types.h $(TYPES_H_DEPS)				\
	$(TC_INCLUDES)

FEATURES_DEPS			= \
	$(PRG_INCLUDE)/features.h $(FEATURES_H_DEPS)			\
	$(PRG_INCLUDE)/macros_slcc.h $(MACROS_SLCC_H_DEPS)

HASH_FUNCTION_DEPS		= \
	$(PRG_INCLUDE)/hash_function.h $(HASH_FUNCTIONS_H_DEPS)		\
	$(PRG_INCLUDE)/types.h $(TYPES_H_DEPS)

INFO_DEPS			= \
	$(PRG_INCLUDE)/info.h $(INFO_H_DEPS)				\
	$(PRG_INCLUDE)/settings.h $(SETTINGS_H_DEPS)			\
	$(PRG_INCLUDE)/version_slcc.h $(VERSION_SLCC_H_DEPS)

LEXER_DEPS			= \
	$(PRG_INCLUDE)/binary_search.h $(BINARY_SEARCH_H_DEPS)		\
	$(PRG_INCLUDE)/config_slcc.h $(CONFIG_SLCC_H_DEPS)		\
	$(PRG_INCLUDE)/error_codes.h $(ERROR_CODES_H_DEPS)		\
	$(PRG_INCLUDE)/error_handling.h $(ERROR_HANDLING_H_DEPS)	\
	$(PRG_INCLUDE)/lexer.h $(LEXER_H_DEPS)				\
	$(PRG_INCLUDE)/lexer_functions.h $(LEXER_FUNCTIONS_H_DEPS)	\
	$(PRG_INCLUDE)/literal.h $(LITERAL_H_DEPS)			\
	$(PRG_INCLUDE)/preprocessor.h $(PREPROCESSOR_H_DEPS)		\
	$(PRG_INCLUDE)/preprocessor_symtab.h 				\
		$(PREPROCESSOR_SYMTAB_H_DEPS)				\
	$(PRG_INCLUDE)/reader.h $(READER_H_DEPS)			\
	$(PRG_INCLUDE)/settings.h $(SETTINGS_H_DEPS)			\
	$(PRG_INCLUDE)/source_position.h $(SOURCE_POSITION_H_DEPS)	\
	$(PRG_INCLUDE)/strings.h $(STRINGS_H_DEPS)			\
	$(PRG_INCLUDE)/token.h $(TOKEN_H_DEPS)				\
	$(CONFIG_C_INCLUDES)						\
	$(TC_INCLUDES)

LEXER_FUNCTIONS_DEPS		= \
	$(PRG_INCLUDE)/error_codes.h $(ERROR_CODES_H_DEPS)		\
	$(PRG_INCLUDE)/error_handling.h $(ERROR_HANDLING_H_DEPS)	\
	$(PRG_INCLUDE)/lexer_functions.h $(LEXER_FUNCTIONS_H_DEPS)	\
	$(PRG_INCLUDE)/reader.h $(READER_H_DEPS)			\
	$(PRG_INCLUDE)/strings.h $(STRINGS_H_DEPS)			\
	$(TC_INCLUDES)

LITERAL_DEPS			= \
	$(PRG_INCLUDE)/literal.h $(LITERAL_H_DEPS)

MAIN_DEPS			= \
	$(PRG_INCLUDE)/driver.h $(DRIVER_H_DEPS)			\
	$(PRG_INCLUDE)/error_handling.h $(ERROR_HANDLING_H_DEPS)	\
	$(PRG_INCLUDE)/info.h $(INFO_H_DEPS)				\
	$(PRG_INCLUDE)/settings.h $(SETTINGS_H_DEPS)

OPTIMIZE_FLAGS_DEPS		= \
	$(PRG_INCLUDE)/macros_slcc.h $(MACROS_SLCC_H_DEPS)		\
	$(PRG_INCLUDE)/optimize_flags.h $(OPTIMIZE_FLAGS_H_DEPS)

PARSE_TREE_DEPS			= \
	$(PRG_INCLUDE)/parse_tree.h $(PARSE_TREE_H_DEPS)		\
	$(PRG_INCLUDE)/source_object.h $(SOURCE_OBJECT_H_DEPS)		\
	$(TC_INCLUDES)

PARSER_DEPS			= \
	$(PRG_INCLUDE)/lexer.h $(LEXER_H_DEPS)				\
	$(PRG_INCLUDE)/parse_tree.h $(PARSE_TREE_H_DEPS)		\
	$(PRG_INCLUDE)/parser.h $(PARSER_H_DEPS)

PREPROCESSOR_DEPS		= \
	$(PRG_INCLUDE)/error_codes.h $(ERROR_CODES_H_DEPS)		\
	$(PRG_INCLUDE)/error_handling.h $(ERROR_HANDLING_H_DEPS)	\
	$(PRG_INCLUDE)/lexer.h $(LEXER_H_DEPS)				\
	$(PRG_INCLUDE)/preprocessor_symtab.h				\
		 $(PREPROCESSOR_SYMTAB_H_DEPS)				\
	$(PRG_INCLUDE)/preprocessor.h $(PREPROCESS_H_DEPS)		\
	$(PRG_INCLUDE)/reader.h $(READER_H_DEPS)			\
	$(PRG_INCLUDE)/strings.h $(STRINGS_H_DEPS)			\
	$(TC_INCLUDES)

PREPROCESSOR_SYMTAB_DEPS	= \
	$(PRG_INCLUDE)/error_codes.h $(ERROR_CODES_H_DEPS)		\
	$(PRG_INCLUDE)/error_handling.h $(ERROR_HANDLING_H_DEPS)	\
	$(PRG_INCLUDE)/preprocessor_symtab.h 				\
		$(PREPROCESSOR_SYMTAB_H_DEPS)				\
	$(PRG_INCLUDE)/symbol_table.h $(SYMBOL_TABLE_H_DEPS)

PREPROCESSOR_SYMTAB_BUILT_IN_DEPS	=\
	$(PRG_INCLUDE)/config_slcc.h $(CONFIG_SLCC_H_DEPS)		\
	$(PRG_INCLUDE)/preprocessor_symtab.h 				\
		$(PREPROCESSOR_SYMTAB_H_DEPS)				\
	$(PRG_INCLUDE)/settings.h $(SETTINGS_H_DEPS)			\
	$(PRG_INCLUDE)/source_position.h $(SOURCE_POSITION_H_DEPS)	\
	$(PRG_INCLUDE)/symbol_table.h $(SYMBOL_TABLE_H_DEPS)		\
	$(PRG_INCLUDE)/version_slcc.h $(VERSION_SLCC_H_DEPS)		\
	$(CONFIG_C_INCLUDES)						\
	$(TC_INCLUDES)

READER_DEPS			= \
	$(PRG_INCLUDE)/reader.h $(READER_H_DEPS)			\
	$(PRG_INCLUDE)/settings.h $(SETTINGS_H_DEPS)			\
	$(PRG_INCLUDE)/source_position.h $(SOURCE_POSITION_H_DEPS)	\
	$(TC_INCLUDES)

SETTINGS_DEPS			= \
	$(PRG_INCLUDE)/error_codes.h $(ERROR_CODES_H_DEPS)		\
	$(PRG_INCLUDE)/error_handling.h $(ERROR_HANDLING_H_DEPS)	\
	$(PRG_INCLUDE)/settings.h $(SETTINGS_H_DEPS)			\
	$(PRG_INCLUDE)/string_array.h $(STRING_ARRAY_H_DEPS)		\
	$(TC_INCLUDES)

SOURCE_FILE_DEPS		= \
	$(PRG_INCLUDE)/source_file.h $(SOURCE_FILE_H_DEPS)

SOURCE_OBJECT_ARRAY_DEPS		= \
	$(PRG_INCLUDE)/source_object_f.h $(SOURCE_OBJECT_F_H_DEPS)	\
	$(PRG_INCLUDE)/source_object_array.h 				\
		$(SOURCE_OBJECT_ARRAY_H_DEPS)				\
	$(TC_INCLUDES)

SOURCE_POSITION_DEPS		= \
	$(PRG_INCLUDE)/source_file.h $(SOURCE_FILE_H_DEPS)		\
	$(PRG_INCLUDE)/source_position.h $(SOURCE_POSITION_H_DEPS)	\
	$(PRG_INCLUDE)/source_string.h $(SOURCE_STRING_H_DEPS)

SOURCE_STRING_DEPS		= \
	$(PRG_INCLUDE)/source_string.h $(SOURCE_STRING_H_DEPS)

SPECIFIERS_DEPS			= \
	$(PRG_INCLUDE)/specifiers.h $(SPECIFIERS_H_DEPS)		\
	$(PRG_INCLUDE)/types.h $(TYPES_H_DEPS)

STRING_ARRAY_DEPS		= \
	$(PRG_INCLUDE)/string_array.h $(STRING_ARRAY_H_DEPS)		\
	$(TC_INCLUDES)

STRINGS_DEPS			= \
	$(PRG_INCLUDE)/strings.h $(STRINGS_H_DEPS)			\
	$(PRG_INCLUDE)/types.h $(TYPES_H_DEPS)				\
	$(TC_INCLUDES)

SYMBOL_TABLE_DEPS		= \
	$(PRG_INCLUDE)/definitions.h $(DEFINITIONS_H_DEPS)		\
	$(PRG_INCLUDE)/error_codes.h $(ERROR_CODES_H_DEPS)		\
	$(PRG_INCLUDE)/error_handling.h $(ERROR_HANDLING_H_DEPS)	\
	$(PRG_INCLUDE)/hash_function.h $(HASH_FUNCTION_H_DEPS)		\
	$(PRG_INCLUDE)/symbol_table.h $(SYMBOL_TABLE_H_DEPS)		\
	$(PRG_INCLUDE)/types.h $(TYPES_H_DEPS)

TOKEN_DEPS			= \
	$(PRG_INCLUDE)/token.h $(TOKEN_H_DEPS)

TOKEN_FUNCTIONS_DEPS		= \
	$(PRG_INCLUDE)/source_position.h $(SOURCE_POSITION_H_DEPS)	\
	$(PRG_INCLUDE)/strings.h $(STRINGS_H_DEPS)			\
	$(PRG_INCLUDE)/token.h $(TOKEN_H_DEPS)				\
	$(TC_INCLUDES)

TYPES_DEPS			= \
	$(PRG_INCLUDE)/types.h $(TYPES_H_DEPS)

VERSION_SLCC_DEPS		= \
	$(PRG_INCLUDE)/config_slcc.h $(CONFIG_SLCC_H_DEPS)		\
	$(PRG_INCLUDE)/version_slcc.h $(VERSION_SLCC_H_DEPS)		\
	$(CONFIG_C_INCLUDES)

WARNINGS_DEPS			= \
	$(PRG_INCLUDE)/macros_slcc.h (MACROS_SLCC_H_DEPS)		\
	$(PRG_INCLUDE)/warnings.h $(WARNINGS_H_DEPS)			

#-------------------------------------------------------------------------------
#<EOF>

