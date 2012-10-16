#===============================================================================
# Snow Leopard Typed Component Library
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
# Generated file containing the object file rules used for the typed component  
# library.
#-------------------------------------------------------------------------------

#-------------------------------------------------------------------------------
# Rules
#
$(LIB_BUILD_PATH)/char_functions.o	: \
		src/char_functions.c $(CHAR_FUNCTIONS_DEPS)
	$(CC) -c $(CFLAGS) src/char_functions.c -o $(.TARGET)

$(LIB_BUILD_PATH)/file_functions.o	: \
		src/file_functions.c $(FILE_FUNCTIONS_DEPS)
	$(CC) -c $(CFLAGS) src/file_functions.c -o $(.TARGET)

$(LIB_BUILD_PATH)/integer_functions.o	: \
		src/integer_functions.c $(INTEGER_FUNCTIONS_DEPS)
	$(CC) -c $(CFLAGS) src/integer_functions.c -o $(.TARGET)

$(LIB_BUILD_PATH)/string_functions.o	: \
		src/string_functions.c $(STRING_FUNCTIONS_DEPS)
	$(CC) -c $(CFLAGS) src/string_functions.c -o $(.TARGET)

$(LIB_BUILD_PATH)/version_tc.o		: \
		src/version_tc.c $(VERSION_TC_DEPS)
	$(CC) -c $(CFLAGS) src/version_tc.c -o $(.TARGET)

#-------------------------------------------------------------------------------
#<EOF>
