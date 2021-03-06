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
	$(UPE_PATH)/checkmail.sh					\
	$(UPE_PATH)/get.sh						\
	$(UPE_PATH)/lookout.sh						\
	$(UPE_PATH)/lookwho.sh						\
	$(UPE_PATH)/news.sh						\
	$(UPE_PATH)/overwrite.sh					\
	$(UPE_PATH)/pick.sh						\
	$(UPE_PATH)/put.sh						\
	$(UPE_PATH)/which.sh						\
	$(UPE_PATH)/zap.sh

UPE_RUN_1_SCRIPT	= $(UPE_PATH)/run_1_test_cal.sh
UPE_RUN_2_SCRIPT 	= $(UPE_PATH)/run_2_test_which.sh
UPE_RUN_3_SCRIPT	= $(UPE_PATH)/run_3_test_lookout.sh
UPE_RUN_4_SCRIPT	= $(UPE_PATH)/run_4_test_lookwho.sh
UPE_RUN_5_SCRIPT	= $(UPE_PATH)/run_5_test_checkmail.sh
UPE_RUN_6_SCRIPT	= $(UPE_PATH)/run_6_test_overwrite.sh
UPE_RUN_7_SCRIPT	= $(UPE_PATH)/run_7_test_zap.sh
UPE_RUN_8_SCRIPT	= $(UPE_PATH)/run_8_test_pick.sh
UPE_RUN_9_SCRIPT	= $(UPE_PATH)/run_9_test_news.sh
UPE_RUN_10_SCRIPT	= $(UPE_PATH)/run_10_test_get_put.sh

UPE_TEST_SCRIPTS	= \
	$(UPE_RUN_1_SCRIPT)						\
	$(UPE_RUN_2_SCRIPT)						\
	$(UPE_RUN_3_SCRIPT)						\
	$(UPE_RUN_4_SCRIPT)						\
	$(UPE_RUN_5_SCRIPT)						\
	$(UPE_RUN_6_SCRIPT)						\
	$(UPE_RUN_7_SCRIPT)						\
	$(UPE_RUN_8_SCRIPT)						\
	$(UPE_RUN_9_SCRIPT)						\
	$(UPE_RUN_10_SCRIPT)

UPE_RUN_1_RESULT	= $(TST_3P_PATH)/run_1.result
UPE_RUN_2_RESULT	= $(TST_3P_PATH)/run_2.result
UPE_RUN_3_RESULT	= $(TST_3P_PATH)/run_3.result
UPE_RUN_4_RESULT	= $(TST_3P_PATH)/run_4.result
UPE_RUN_5_RESULT	= $(TST_3P_PATH)/run_5.result
UPE_RUN_6_RESULT	= $(TST_3P_PATH)/run_6.result
UPE_RUN_7_RESULT	= $(TST_3P_PATH)/run_7.result
UPE_RUN_8_RESULT	= $(TST_3P_PATH)/run_8.result
UPE_RUN_9_RESULT	= $(TST_3P_PATH)/run_9.result
UPE_RUN_10_RESULT	= $(TST_3P_PATH)/run_10.result

UPE_TEST_RESULTS	= \
	$(UPE_RUN_1_RESULT)						\
	$(UPE_RUN_2_RESULT)						\
	$(UPE_RUN_3_RESULT)						\
	$(UPE_RUN_4_RESULT)						\
	$(UPE_RUN_5_RESULT)						\
	$(UPE_RUN_6_RESULT)						\
	$(UPE_RUN_7_RESULT)						\
	$(UPE_RUN_8_RESULT)						\
	$(UPE_RUN_9_RESULT)						\
	$(UPE_RUN_10_RESULT)

#-------------------------------------------------------------------------------
# De UNIX Programmeer Omgeving Rules
#
$(UPE_RUN_1_RESULT)	: 
	sh $(UPE_RUN_1_SCRIPT) $(UPE_RUN_1_RESULT)

$(UPE_RUN_2_RESULT)	:
	sh $(UPE_RUN_2_SCRIPT) $(UPE_RUN_2_RESULT) $(TST_3P_PATH)

$(UPE_RUN_3_RESULT)	:
	sh $(UPE_RUN_3_SCRIPT) $(UPE_RUN_3_RESULT)

$(UPE_RUN_4_RESULT)	:
	sh $(UPE_RUN_4_SCRIPT) $(UPE_RUN_4_RESULT)

$(UPE_RUN_5_RESULT)	:
	sh $(UPE_RUN_5_SCRIPT) $(UPE_RUN_5_RESULT)

$(UPE_RUN_6_RESULT)	:
	sh $(UPE_RUN_6_SCRIPT) $(UPE_RUN_6_RESULT)

$(UPE_RUN_7_RESULT)	:
	sh $(UPE_RUN_7_SCRIPT) $(UPE_RUN_7_RESULT)

$(UPE_RUN_8_RESULT)	:
	sh $(UPE_RUN_8_SCRIPT) $(UPE_RUN_8_RESULT)

$(UPE_RUN_9_RESULT)	:
	sh $(UPE_RUN_9_SCRIPT) $(UPE_RUN_9_RESULT) $(TST_3P_PATH)

$(UPE_RUN_10_RESULT)	:
	sh $(UPE_RUN_10_SCRIPT) $(UPE_RUN_10_RESULT) $(TST_3P_PATH)

#-------------------------------------------------------------------------------
#<EOF>
