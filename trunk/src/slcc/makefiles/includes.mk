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
	$(PRG_INCLUDE)/arguments.h					\
	$(PRG_INCLUDE)/binary_search.h					\
	$(PRG_INCLUDE)/built_in_identifiers.h				\
	$(PRG_INCLUDE)/built_in_types.h					\
	$(PRG_INCLUDE)/codegen.h					\
	$(PRG_INCLUDE)/config_slcc.h 					\
	$(PRG_INCLUDE)/constructs.h					\
	$(PRG_INCLUDE)/cpp_symtab.h					\
	$(PRG_INCLUDE)/debug.h						\
	$(PRG_INCLUDE)/debug_functions.h				\
	$(PRG_INCLUDE)/declarations.h					\
	$(PRG_INCLUDE)/definitions.h					\
	$(PRG_INCLUDE)/definitions_f.h					\
	$(PRG_INCLUDE)/driver.h 					\
	$(PRG_INCLUDE)/error.h						\
	$(PRG_INCLUDE)/error_array.h					\
	$(PRG_INCLUDE)/error_codes.h					\
	$(PRG_INCLUDE)/error_handling.h					\
	$(PRG_INCLUDE)/features.h					\
	$(PRG_INCLUDE)/hash_function.h					\
	$(PRG_INCLUDE)/info.h						\
	$(PRG_INCLUDE)/lexer.h						\
	$(PRG_INCLUDE)/lexer_functions.h				\
	$(PRG_INCLUDE)/macros_slcc.h					\
	$(PRG_INCLUDE)/optimize_flags.h					\
	$(PRG_INCLUDE)/parse_tree.h					\
	$(PRG_INCLUDE)/parser.h						\
	$(PRG_INCLUDE)/preprocessor.h					\
	$(PRG_INCLUDE)/preprocessor_symtab.h				\
	$(PRG_INCLUDE)/reader.h						\
	$(PRG_INCLUDE)/settings.h 					\
	$(PRG_INCLUDE)/source_file.h					\
	$(PRG_INCLUDE)/source_object.h					\
	$(PRG_INCLUDE)/source_object_array.h				\
	$(PRG_INCLUDE)/source_position.h				\
	$(PRG_INCLUDE)/source_string.h					\
	$(PRG_INCLUDE)/specifiers.h					\
	$(PRG_INCLUDE)/statements.h					\
	$(PRG_INCLUDE)/string_array.h					\
	$(PRG_INCLUDE)/strings.h					\
	$(PRG_INCLUDE)/symbol_table.h					\
	$(PRG_INCLUDE)/templates.h					\
	$(PRG_INCLUDE)/token.h						\
	$(PRG_INCLUDE)/types.h 						\
	$(PRG_INCLUDE)/version_slcc.h					\
	$(PRG_INCLUDE)/warnings.h

.include "../../libsltc/makefiles/includes.mk"

#-------------------------------------------------------------------------------
#<EOF>

