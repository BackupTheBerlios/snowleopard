#===============================================================================
# Snow Leopard Test Suite
#
# Copyright (C) 2011, 2012 Roel Sergeant
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
# run_2_test_which.sh
#-------------------------------------------------------------------------------
# Test script for which.sh. Check if which.sh works the same way on the shell as 
# on sh.
#-------------------------------------------------------------------------------

result_file=$1

echo '==> Running which.sh test script'

echo 'TEST_SUCCESS' > $result_file

echo '<== Finished which.sh test script'

#-------------------------------------------------------------------------------
#-<EOF>
