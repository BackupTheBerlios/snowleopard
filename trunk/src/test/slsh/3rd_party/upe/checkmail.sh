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
# checkmail.sh
#-------------------------------------------------------------------------------
# checkmail script from De UNIX Programmeer Omgeving. The script checks if the
# user has new email..
#-------------------------------------------------------------------------------

# Set path
PATH=/bin:/usr/bin
MAIL=${MAIL=/var/spool/mail/$USER}new

# Check mails and report if changed
t=${1-60}
x="`ls -l $MAIL`"

while :
do
    y="`ls -l $MAIL`"
    echo $x $y | awk '$4 < $12 { print "You have mail" }'
    x="$y"
    sleep $t
done

#-------------------------------------------------------------------------------
#-<EOF>
