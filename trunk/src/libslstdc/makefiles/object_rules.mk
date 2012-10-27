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
$(LIB_BUILD_PATH)/assert.o  		: \
		src/assert.c $(ASSERT_DEPS)
	$(CC) -c $(CFLAGS) src/assert.c -o $(.TARGET)

$(LIB_BUILD_PATH)/version_stdc.o  	: \
		src/version_stdc.c $(VERSION_STDC_DEPS)
	$(CC) -c $(CFLAGS) src/version_stdc.c -o $(.TARGET)

#-------------------------------------------------------------------------------
#<EOF>
