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
# lookout.sh
#-------------------------------------------------------------------------------
# lookout script from De UNIX Programmeer Omgeving. The script checks every 60
# seconds if the user given as parameter is logged in.
#-------------------------------------------------------------------------------

# Set path
PATH=/bin:/usr/bin

# Process arguments
case $# in
    0) echo 'lookout: username missing' 1>&2; exit 1
esac

# Check if the user is logged in, and if not found wait 60 seconds
until who | grep "$1"
do
    sleep 60
done

#-------------------------------------------------------------------------------
#-<EOF>
