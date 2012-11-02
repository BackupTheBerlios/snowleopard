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
# get.sh
#-------------------------------------------------------------------------------
# get script from De UNIX Programmeer Omgeving. Get a file from the history.
#-------------------------------------------------------------------------------

# Set path
PATH=/bin:/usr/bin

VERSION=0

while test "$1" != ""
do
    case "$1" in
	-i)     INPUT=$2 ; shift ;;
	-o)     OUTPUT=$2 ; shift ;;
	-[0-9]) VERSION=$1 ;;
	-*)     echo "get: unknown argument $1" 1>&2 ; exit 1 ;;
	*)      case "$OUTPUT" in
	            "") OUTPUT=$1 ;;
	            *)  INPUT=$1.H ;;
                esac
    esac
    shift
done

OUTPUT=${OUTPUT?"usage: get [-o outfile] [-i file.H] file"}
INPUT=${INPUT-$OUTPUT.H}

test -r $INPUT || { echo "get: no file $INPUT" 1>&2 ; exit 1 ; }
trap 'rm -f /tmp/get.[ab]$$ ; exit 1' 1 2 15

# Splits in current version
sed $INPUT -n '1,/^@@@/w /tmp/get.a'$$'
               /^@@@/,$w /tmp/get.b'$$

# Edit work
awk </tmp/get.b$$ '/^@@@/ { count++ }
                   !/^@@@/ && count > 0 && count <= - '$VERSION'
                   END { print "$d" ; print "w", "'$output'" }
' | ed - /tmp/get.a$$

# Cleanup
rm -f /tmp/get.[ab]$$

#-------------------------------------------------------------------------------
#-<EOF>
