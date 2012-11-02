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
# zap.sh
#-------------------------------------------------------------------------------
# zap script from De UNIX Programmeer Omgeving. Kills all processes matching the
# pattern given as argument.
#-------------------------------------------------------------------------------

# Set path
PATH=/bin:/usr/bin

# Set variable
IFS='
'

# Process argument
case $1 in
    "") echo 'usage: zap [-2] pattern' 1>&2 ; exit 1 ;;
    -*) SIG=$1 ; shift
esac

echo '   PID TTY  TIME CMD'
kill $SIG `./pick \`ps -ag | egrep "$*"\` | awk '{ print $1 }'`

#-------------------------------------------------------------------------------
#-<EOF>
