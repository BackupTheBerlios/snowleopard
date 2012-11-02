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
# overwrite.sh
#-------------------------------------------------------------------------------
# overwrite script from De UNIX Programmeer Omgeving. This script can be used in
# utilities that would otherwise screw up the source file.
#-------------------------------------------------------------------------------

# Set path
path=$PATH
PATH=/bin:/usr/bin

# Process arguments
case $# in
    0 | 1) echo 'usage: overwrite file command [arguments]' 1>&2 ; exit 2
esac

# Setup variables
file=$1
shift

new=/tmp/overwr1.$$
old=/tmp/overwr2.$$

trap 'rm -rf $new $old ; exit 1' 1 2 15

# Process file
if PATH=$path "$@" >$new
then
    cp $file $old
    trap '' 1 2 15
    cp $new $file
else
    echo "overwrite: $1 ending in failure, $file was not changed" 1>&2
    exit 1
fi

rm -f $new $old

#-------------------------------------------------------------------------------
#-<EOF>
