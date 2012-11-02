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
# put.sh
#-------------------------------------------------------------------------------
# put script from De UNIX Programmeer Omgeving. Put a file in the history.
#-------------------------------------------------------------------------------

# Set path
PATH=/bin:/usr/bin

# Process arguments
case $# in
    1) HIST=$1.H ;;
    *) echo 'usage: put file' 1>&2 ; exit 1 ;;
esac

if test ! -r $1
then
    echo "put: can't open $1" 1>&2 ; exit 1
fi

trap 'rm -f /tmp/put.[ab]$$ ; exit 1' 1 2 15
echo -n 'Summary: '
read summary

if get -o /tmp/put.a$$ $1
then
    cp $1 /tmp/put.b$$
    echo "@@@ $USER `date` $summary" >>/tmp/put.b$$
    diff -e $1 /tmp/put.a$$ >>/tmp/put.b$$
    sed -n '/^@@@/,$p' <$HIST >>/tmp/put.b$$
    overwrite $HIST cat /tmp/put.b$$
else
    echo "put: creating $HIST"
    cp $1 $HIST
    echo "@@@ $USER `data` $summary" >>$HIST
fi

rm -f /tmp/put.[ab]$$

#-------------------------------------------------------------------------------
#-<EOF>
