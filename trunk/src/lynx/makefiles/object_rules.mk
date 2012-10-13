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
$(PRG_BUILD_PATH)/driver.o  		: \
		src/driver.c $(DRIVER_DEPS)
	$(CC) -c $(CFLAGS) src/driver.c -o $(.TARGET)

$(PRG_BUILD_PATH)/info.o		: \
		src/info.c $(INFO_DEPS)
	$(CC) -c $(CFLAGS) src/info.c -o $(.TARGET)

$(PRG_BUILD_PATH)/ldformat_main.o	: \
		src/ldformat_main.c $(LDFORMAT_MAIN_DEPS)
	$(CC) -c $(CFLAGS) src/ldformat_main.c -o $(.TARGET)

$(PRG_BUILD_PATH)/leqn_main.o		: \
		src/leqn_main.c $(LEQN_MAIN_DEPS)
	$(CC) -c $(CFLAGS) src/leqn_main.c -o $(.TARGET)

$(PRG_BUILD_PATH)/lgm_main.o		: \
		src/lgm_main.c $(LGM_MAIN_DEPS)
	$(CC) -c $(CFLAGS) src/lgm_main.c -o $(.TARGET)

$(PRG_BUILD_PATH)/lgrap_main.o		: \
		src/lgrap_main.c $(LGRAP_MAIN_DEPS)
	$(CC) -c $(CFLAGS) src/lgrap_main.c -o $(.TARGET)

$(PRG_BUILD_PATH)/lideal_main.o		: \
		src/lideal_main.c $(LIDEAL_MAIN_DEPS)
	$(CC) -c $(CFLAGS) src/lideal_main.c -o $(.TARGET)

$(PRG_BUILD_PATH)/lpic_main.o		: \
		src/lpic_main.c $(LPIC_MAIN_DEPS)
	$(CC) -c $(CFLAGS) src/lpic_main.c -o $(.TARGET)

$(PRG_BUILD_PATH)/lrefer_main.o		: \
		src/lrefer_main.c $(LREFER_MAIN_DEPS)
	$(CC) -c $(CFLAGS) src/lrefer_main.c -o $(.TARGET)

$(PRG_BUILD_PATH)/lroff_main.o		: \
		src/lroff_main.c $(LROFF_MAIN_DEPS)
	$(CC) -c $(CFLAGS) src/lroff_main.c -o $(.TARGET)

$(PRG_BUILD_PATH)/lsoelim_main.o	: \
		src/lsoelim_main.c $(LSOELIM_MAIN_DEPS)
	$(CC) -c $(CFLAGS) src/lsoelim_main.c -o $(.TARGET)

$(PRG_BUILD_PATH)/ltbl_main.o		: \
		src/ltbl_main.c $(LTBL_MAIN_DEPS)
	$(CC) -c $(CFLAGS) src/ltbl_main.c -o $(.TARGET)

$(PRG_BUILD_PATH)/lynx_main.o		: \
		src/lynx_main.c $(LYNX_MAIN_DEPS)
	$(CC) -c $(CFLAGS) src/lynx_main.c -o $(.TARGET)

$(PRG_BUILD_PATH)/version_lynx.o	: \
		src/version_lynx.c $(VERSION_LYNX_DEPS)
	$(CC) -c $(CFLAGS) src/version_lynx.c -o $(.TARGET)

#-------------------------------------------------------------------------------
#<EOF>
