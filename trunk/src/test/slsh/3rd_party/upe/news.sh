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
# news.sh
#-------------------------------------------------------------------------------
# news script from De UNIX Programmeer Omgeving. Print the news.
#-------------------------------------------------------------------------------

# Set path
PATH=/bin:/usr/bin
IFS='
'

# User news
cd /usr/news

# Select argument given
for i in `ls -t * $HOME/.news_time 2>&1`
do
    IFS=' '
    case $i in
	*' not found') ;;
	*/.news_time)  break ;;
	*)             set X`ls -l $i`
	               echo "
$i: ($3) $5 $6 $7
"
		       cat $i
    esac
done
touch $HOME/.news_time

#-------------------------------------------------------------------------------
#-<EOF>
