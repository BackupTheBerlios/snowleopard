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
# objects.mk
#-------------------------------------------------------------------------------
# Generated file containing the object files used for the compiler front end.
#-------------------------------------------------------------------------------

OBJS 		= \
	$(PRG_BUILD_PATH)/driver.o 					\
	$(PRG_BUILD_PATH)/error_array.o					\
	$(PRG_BUILD_PATH)/error_codes.o					\
	$(PRG_BUILD_PATH)/error_handling.o				\
	$(PRG_BUILD_PATH)/info.o					\
	$(PRG_BUILD_PATH)/main.o 					\
	$(PRG_BUILD_PATH)/settings.o 					\
	$(PRG_BUILD_PATH)/string_array.o				\
	$(PRG_BUILD_PATH)/string_functions.o				\
	$(PRG_BUILD_PATH)/types.o 					\
	$(PRG_BUILD_PATH)/version_slcc.o				\
	$(TC_BUILD_PATH)/libsltc.a

#-------------------------------------------------------------------------------
#<EOF>
