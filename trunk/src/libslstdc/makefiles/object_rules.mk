#===============================================================================
# Snow Leopard Standard C Library
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
# Generated file containing the object file rules used for the standard C 
# library.
#-------------------------------------------------------------------------------

#-------------------------------------------------------------------------------
# Rules
#
$(LIB_BUILD_PATH)/isalnum.o  	: \
		src/isalnum.c $(ISALNUM_DEPS)
	$(CC) -c $(CFLAGS) src/isalnum.c -o $(.TARGET)

$(LIB_BUILD_PATH)/isalpha.o  	: \
		src/isalpha.c $(ISALPHA_DEPS)
	$(CC) -c $(CFLAGS) src/isalpha.c -o $(.TARGET)

$(LIB_BUILD_PATH)/isblank.o  	: \
		src/isblank.c $(ISBLANK_DEPS)
	$(CC) -c $(CFLAGS) src/isblank.c -o $(.TARGET)

$(LIB_BUILD_PATH)/version_stdc.o  	: \
		src/version_stdc.c $(VERSION_STDC_DEPS)
	$(CC) -c $(CFLAGS) src/version_stdc.c -o $(.TARGET)

#-------------------------------------------------------------------------------
# Rules for private functions
#
$(LIB_BUILD_PATH)/xassert.o  		: \
		src/xassert.c $(XASSERT_DEPS)
	$(CC) -c $(CFLAGS) src/xassert.c -o $(.TARGET)

#-------------------------------------------------------------------------------
#<EOF>
