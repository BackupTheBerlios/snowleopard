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
$(PRG_BUILD_PATH)/driver.o		: \
		src/driver.c $(DRIVER_DEPS)
	$(CC) -c $(CFLAGS) src/driver.c -o $(.TARGET)

$(PRG_BUILD_PATH)/info.o		: \
		src/info.c $(INFO_DEPS)
	$(CC) -c $(CFLAGS) src/info.c -o $(.TARGET)

$(PRG_BUILD_PATH)/file_functions.o	: \
		src/file_functions.c $(FILE_FUNCTIONS_DEPS)
	$(CC) -c $(CFLAGS) src/file_functions.c -o $(.TARGET)

$(PRG_BUILD_PATH)/ldformat_driver.o  	: \
		src/ldformat_driver.c $(LDFORMAT_DRIVER_DEPS)
	$(CC) -c $(CFLAGS) src/ldformat_driver.c -o $(.TARGET)

$(PRG_BUILD_PATH)/leqn_driver.o  	: \
		src/leqn_driver.c $(LEQN_DRIVER_DEPS)
	$(CC) -c $(CFLAGS) src/leqn_driver.c -o $(.TARGET)

$(PRG_BUILD_PATH)/lgm_driver.o  	: \
		src/lgm_driver.c $(LGM_DRIVER_DEPS)
	$(CC) -c $(CFLAGS) src/lgm_driver.c -o $(.TARGET)

$(PRG_BUILD_PATH)/lgrap_driver.o  	: \
		src/lgrap_driver.c $(LGRAP_DRIVER_DEPS)
	$(CC) -c $(CFLAGS) src/lgrap_driver.c -o $(.TARGET)

$(PRG_BUILD_PATH)/lideal_driver.o  	: \
		src/lideal_driver.c $(LIDEAL_DRIVER_DEPS)
	$(CC) -c $(CFLAGS) src/lideal_driver.c -o $(.TARGET)

$(PRG_BUILD_PATH)/lpic_driver.o  	: \
		src/lpic_driver.c $(LPIC_DRIVER_DEPS)
	$(CC) -c $(CFLAGS) src/lpic_driver.c -o $(.TARGET)

$(PRG_BUILD_PATH)/lrefer_driver.o  	: \
		src/lrefer_driver.c $(LREFER_DRIVER_DEPS)
	$(CC) -c $(CFLAGS) src/lrefer_driver.c -o $(.TARGET)

$(PRG_BUILD_PATH)/lroff_driver.o  	: \
		src/lroff_driver.c $(LROFF_DRIVER_DEPS)
	$(CC) -c $(CFLAGS) src/lroff_driver.c -o $(.TARGET)

$(PRG_BUILD_PATH)/lsoelim_driver.o  	: \
		src/lsoelim_driver.c $(LSOELIM_DRIVER_DEPS)
	$(CC) -c $(CFLAGS) src/lsoelim_driver.c -o $(.TARGET)

$(PRG_BUILD_PATH)/ltbl_driver.o  	: \
		src/ltbl_driver.c $(LTBL_DRIVER_DEPS)
	$(CC) -c $(CFLAGS) src/ltbl_driver.c -o $(.TARGET)

$(PRG_BUILD_PATH)/lynx_driver.o  	: \
		src/lynx_driver.c $(LYNX_DRIVER_DEPS)
	$(CC) -c $(CFLAGS) src/lynx_driver.c -o $(.TARGET)

$(PRG_BUILD_PATH)/main.o		: \
		src/main.c $(MAIN_DEPS)
	$(CC) -c $(CFLAGS) src/main.c -o $(.TARGET)

$(PRG_BUILD_PATH)/settings.o		: \
		src/settings.c $(SETTINGS_DEPS)
	$(CC) -c $(CFLAGS) src/settings.c -o $(.TARGET)

$(PRG_BUILD_PATH)/string_array.o	: \
		src/string_array.c $(STRING_ARRAY_DEPS)
	$(CC) -c $(CFLAGS) src/string_array.c -o $(.TARGET)

$(PRG_BUILD_PATH)/version_lynx.o	: \
		src/version_lynx.c $(VERSION_LYNX_DEPS)
	$(CC) -c $(CFLAGS) src/version_lynx.c -o $(.TARGET)

#-------------------------------------------------------------------------------
#<EOF>
