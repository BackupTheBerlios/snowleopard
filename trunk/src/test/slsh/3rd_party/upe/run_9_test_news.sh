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
# run_9_test_news.sh
#-------------------------------------------------------------------------------
# Test script for news.sh. Check if news.sh works the same way on the shell as 
# on sh.
#-------------------------------------------------------------------------------

result_file=$1

echo '==> Running news.sh test script'

# Set news directory
HOME=$TST_3P_PATH

#-------------------------------------------------------------------------------
# TEST 1 - Test tools are where they are supposed to be.
#

#-------------------------------------------------------------------------------
# TEST 2 - Test script correctly uses the path.
#

#-------------------------------------------------------------------------------
# If result_file doesn't exist create it as successful.
#
if test ! -e $result_file
then
    echo 'TEST_SUCCESS' > $result_file
fi

echo '<== Finished news.sh test script'

#-------------------------------------------------------------------------------
#-<EOF>
