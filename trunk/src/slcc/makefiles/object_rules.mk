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
$(PRG_BUILD_PATH)/driver.o  		: src/driver.c
	$(CC) -c $(CFLAGS) src/driver.c -o $(.TARGET)

$(PRG_BUILD_PATH)/error_array.o		: src/error_array.c
	$(CC) -c $(CFLAGS) src/error_array.c -o $(.TARGET)

$(PRG_BUILD_PATH)/error_codes.o		: src/error_codes.c
	$(CC) -c $(CFLAGS) src/error_codes.c -o $(.TARGET)

$(PRG_BUILD_PATH)/error_handling.o	: src/error_handling.c
	$(CC) -c $(CFLAGS) src/error_handling.c -o $(.TARGET)

$(PRG_BUILD_PATH)/info.o		: src/info.c
	$(CC) -c $(CFLAGS) src/info.c -o $(.TARGET)

$(PRG_BUILD_PATH)/main.o		: src/main.c
	$(CC) -c $(CFLAGS) src/main.c -o $(.TARGET)

$(PRG_BUILD_PATH)/settings.o		: src/settings.c
	$(CC) -c $(CFLAGS) src/settings.c -o $(.TARGET)

$(PRG_BUILD_PATH)/string_array.o	: src/string_array.c
	$(CC) -c $(CFLAGS) src/string_array.c -o $(.TARGET)

$(PRG_BUILD_PATH)/string_functions.o	: src/string_functions.c
	$(CC) -c $(CFLAGS) src/string_functions.c -o $(.TARGET)

$(PRG_BUILD_PATH)/types.o		: src/types.c
	$(CC) -c $(CFLAGS) src/types.c -o $(.TARGET)

$(PRG_BUILD_PATH)/version_slcc.o	: src/version_slcc.c
	$(CC) -c $(CFLAGS) src/version_slcc.c -o $(.TARGET)

#-------------------------------------------------------------------------------
#<EOF>
