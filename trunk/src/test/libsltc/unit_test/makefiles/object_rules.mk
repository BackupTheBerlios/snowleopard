#===============================================================================
# Snow Leopard Test Suite
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
# library test suite.
#-------------------------------------------------------------------------------

#-------------------------------------------------------------------------------
# Rules
#
$(UT_RUN_1_PROGRAM)					: $(UT_RUN_1_OBJS)
	$(CC) $(.ALLSRC) -o $(.TARGET)

$(TST_UT_PATH)/run_1_private_linked_list_1.o		: 		\
		unit_test/run_1/run_1_private_linked_list_1.c
	$(CC) -c $(CFLAGS) 						\
		unit_test/run_1/run_1_private_linked_list_1.c		\
		-o $(.TARGET)

$(TST_UT_PATH)/run_1_private_linked_list_1_main.o	: 		\
		unit_test/run_1/run_1_private_linked_list_1_main.c
	$(CC) -c $(CFLAGS) 						\
		unit_test/run_1/run_1_private_linked_list_1_main.c	\
		-o $(.TARGET)

$(UT_RUN_2_PROGRAM)					: $(UT_RUN_2_OBJS)
	$(CC) $(.ALLSRC) -o $(.TARGET)

$(TST_UT_PATH)/run_2_private_array_1.o		: 			\
		unit_test/run_2/run_2_private_array_1.c
	$(CC) -c $(CFLAGS) 						\
		unit_test/run_2/run_2_private_array_1.c			\
		-o $(.TARGET)

$(TST_UT_PATH)/run_2_private_array_1_main.o	: 			\
		unit_test/run_2/run_2_private_array_1_main.c
	$(CC) -c $(CFLAGS) 						\
		unit_test/run_2/run_2_private_array_1_main.c		\
		-o $(.TARGET)

#-------------------------------------------------------------------------------
#<EOF>
