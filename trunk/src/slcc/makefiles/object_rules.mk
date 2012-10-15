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
# object_rules.mk
#-------------------------------------------------------------------------------
# Generated file containing the object file rules used for the compiler front 
# end.
#-------------------------------------------------------------------------------

#-------------------------------------------------------------------------------
# Rules
#
$(PRG_BUILD_PATH)/codegen.o  		: \
		src/codegen.c $(CODEGEN_DEPS)
	$(CC) -c $(CFLAGS) src/codegen.c -o $(.TARGET)

$(PRG_BUILD_PATH)/driver.o  		: \
		src/driver.c $(DRIVER_DEPS)
	$(CC) -c $(CFLAGS) src/driver.c -o $(.TARGET)

$(PRG_BUILD_PATH)/error_array.o		: \
		src/error_array.c $(ERROR_ARRAY_DEPS)
	$(CC) -c $(CFLAGS) src/error_array.c -o $(.TARGET)

$(PRG_BUILD_PATH)/error_codes.o		: \
		src/error_codes.c $(ERROR_CODES_DEPS)
	$(CC) -c $(CFLAGS) src/error_codes.c -o $(.TARGET)

$(PRG_BUILD_PATH)/error_handling.o	: \
		src/error_handling.c $(ERROR_HANDLING_DEPS)
	$(CC) -c $(CFLAGS) src/error_handling.c -o $(.TARGET)

$(PRG_BUILD_PATH)/hash_function.o	: \
		src/hash_function.c $(HASH_FUNCTION_DEPS)
	$(CC) -c $(CFLAGS) src/hash_function.c -o $(.TARGET)

$(PRG_BUILD_PATH)/info.o		: \
		src/info.c $(INFO_DEPS)
	$(CC) -c $(CFLAGS) src/info.c -o $(.TARGET)

$(PRG_BUILD_PATH)/literal.o		: \
		src/literal.c $(LITERAL_DEPS)
	$(CC) -c $(CFLAGS) src/literal.c -o $(.TARGET)

$(PRG_BUILD_PATH)/main.o		: \
		src/main.c $(MAIN_DEPS)
	$(CC) -c $(CFLAGS) src/main.c -o $(.TARGET)

$(PRG_BUILD_PATH)/parse_tree.o  	: \
		src/parse_tree.c $(PARSE_TREE_DEPS)
	$(CC) -c $(CFLAGS) src/parse_tree.c -o $(.TARGET)

$(PRG_BUILD_PATH)/parser.o  		: \
		src/parser.c $(PARSER_DEPS)
	$(CC) -c $(CFLAGS) src/parser.c -o $(.TARGET)

$(PRG_BUILD_PATH)/settings.o		: \
		src/settings.c $(SETTINGS_DEPS)
	$(CC) -c $(CFLAGS) src/settings.c -o $(.TARGET)

$(PRG_BUILD_PATH)/source_file.o		: \
		src/source_file.c $(SOURCE_FILE_DEPS)
	$(CC) -c $(CFLAGS) src/source_file.c -o $(.TARGET)

$(PRG_BUILD_PATH)/source_position.o	: \
		src/source_position.c $(SOURCE_POSITION_DEPS)
	$(CC) -c $(CFLAGS) src/source_position.c -o $(.TARGET)

$(PRG_BUILD_PATH)/source_string.o		: \
		src/source_string.c $(SOURCE_STRING_DEPS)
	$(CC) -c $(CFLAGS) src/source_string.c -o $(.TARGET)

$(PRG_BUILD_PATH)/string_array.o	: \
		src/string_array.c $(STRING_ARRAY_DEPS)
	$(CC) -c $(CFLAGS) src/string_array.c -o $(.TARGET)

$(PRG_BUILD_PATH)/strings.o		: \
		src/strings.c $(STRINGS_DEPS)
	$(CC) -c $(CFLAGS) src/strings.c -o $(.TARGET)

$(PRG_BUILD_PATH)/token.o		: \
		src/token.c $(TOKEN_DEPS)
	$(CC) -c $(CFLAGS) src/token.c -o $(.TARGET)

$(PRG_BUILD_PATH)/types.o		: \
		src/types.c $(TYPES_DEPS)
	$(CC) -c $(CFLAGS) src/types.c -o $(.TARGET)

$(PRG_BUILD_PATH)/version_slcc.o	: \
		src/version_slcc.c $(VERSION_SLCC_DEPS)
	$(CC) -c $(CFLAGS) src/version_slcc.c -o $(.TARGET)

#-------------------------------------------------------------------------------
#<EOF>
