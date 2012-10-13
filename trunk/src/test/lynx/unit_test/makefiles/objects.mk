#===============================================================================
# Lynx Test Suite
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
# Generated file containing the object files used for the lynx typesetting
# system test suite.
#-------------------------------------------------------------------------------

UT_RUN_1_PROGRAM	= $(TST_UT_PATH)/run_1_private_linked_list
UT_RUN_1_OBJS 		= \
	$(TST_UT_PATH)/run_1_private_linked_list_1.o		\
	$(TST_UT_PATH)/run_1_private_linked_list_1_main.o

UT_RUN_2_PROGRAM	= $(TST_UT_PATH)/run_2_private_array
UT_RUN_2_OBJS 		= \
	$(TST_UT_PATH)/run_2_private_array_1.o			\
	$(TST_UT_PATH)/run_2_private_array_1_main.o

UT_PROGRAMS		= \
	$(UT_RUN_1_PROGRAM) $(UT_RUN_2_PROGRAM)

UT_OBJS 		= \
	$(UT_RUN_1_OBJS) $(UT_RUN_2_OBJS)

#-------------------------------------------------------------------------------
#<EOF>
