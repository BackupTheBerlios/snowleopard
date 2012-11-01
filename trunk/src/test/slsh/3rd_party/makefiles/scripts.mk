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
# scripts.mk
#-------------------------------------------------------------------------------
# Generated file containing a list of all includes files that are specific to
# the shell
#-------------------------------------------------------------------------------

#-------------------------------------------------------------------------------
# De UNIX Programmeer Omgeving Variables
#
UPE_PATH		= 3rd_party/upe

UPE_SCRIPTS		= \
	$(UPE_PATH)/cal.sh						\
	$(UPE_PATH)/which.sh

UPE_RUN_1_SCRIPT	= $(UPE_PATH)/run_1_test_cal.sh
UPE_RUN_2_SCRIPT 	= $(UPE_PATH)/run_2_test_which.sh

UPE_TEST_SCRIPTS	= \
	$(UPE_RUN_1_SCRIPT)						\
	$(UPE_RUN_2_SCRIPT)

UPE_RUN_1_RESULT	= $(TST_3P_PATH)/run_1.result
UPE_RUN_2_RESULT	= $(TST_3P_PATH)/run_2.result

UPE_TEST_RESULTS	= \
	$(UPE_RUN_1_RESULT)						\
	$(UPE_RUN_2_RESULT)

#-------------------------------------------------------------------------------
# 3rd Party Variables
#
3P_TEST_SCRIPTS		= \
	$(UPE_TEST_SCRIPTS)

3P_TEST_RESULTS		= \
	$(UPE_TEST_RESULTS)

#-------------------------------------------------------------------------------
# De UNIX Programmeer Omgeving Rules
#
$(UPE_RUN_1_RESULT)	: 
	$(UPE_RUN_1_SCRIPT) $(UPE_RUN_1_RESULT)

$(UPE_RUN_2_RESULT)	: $(TST_3P_PATH)/test
	PATH=$(TST_3P_PATH):$(PATH)					\
	$(UPE_RUN_2_SCRIPT) $(UPE_RUN_2_RESULT)

$(TST_3P_PATH)/test	:
	echo echo mytest > $(TST_3P_PATH)/test ;			\
	chmod uga+x $(TST_3P_PATH)/test

#-------------------------------------------------------------------------------
#<EOF>
