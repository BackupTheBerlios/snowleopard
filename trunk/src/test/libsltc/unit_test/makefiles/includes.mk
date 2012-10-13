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
# includes.mk
#-------------------------------------------------------------------------------
# Generated file containing a list of all includes files that are specific to
# the typed component library test suite.
#-------------------------------------------------------------------------------

#-------------------------------------------------------------------------------
# Variables
#
UT_RUN_1_INCLUDE	= unit_test/run_1
UT_RUN_1_INCLUDES 	= \
	$(UT_RUN_1_INCLUDE)/run_1_private_linked_list_1.h

UT_RUN_2_INCLUDE	= unit_test/run_2
UT_RUN_2_INCLUDES	= \
	$(UT_RUN_2_INCLUDE)/run_2_private_array_1.h

.include "../../libsltc/makefiles/includes.mk"

#-------------------------------------------------------------------------------
#<EOF>
