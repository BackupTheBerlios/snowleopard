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
# which.sh
#-------------------------------------------------------------------------------
# cal script from De UNIX Programmeer Omgeving. This program checks where in the
# path the program given as parameter resides.
#-------------------------------------------------------------------------------

# Save old path
path=$PATH
PATH=/bin:/usr/bin

# Process arguments
case $# in
    0) echo 'which: no parameter given' 1>&2 ; exit 2
esac

# Find the program
for i in `echo $path | sed 's/^:/.:/
                            s/::/:.:/g
                            s/:$/:./
                            s/:/ /g'`
do
    if test -f $i/$1
    then
	echo $i/$1
	exit 0
    fi
done

exit 1

#-------------------------------------------------------------------------------
#-<EOF>
