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
# cal.sh
#-------------------------------------------------------------------------------
# cal script from De UNIX Programmeer Omgeving. This script wraps around the 
# Unix cal program.
#-------------------------------------------------------------------------------

# Process arguments
case $# in
    0) set `date` ; m=$2 ; j=$6 ;;
    1) m=$1 ; set `date` ; j=$6 ;;
    *) m=$1 ; j=$2 ;;
esac

case $m in
    jan* | Jan*)          m=1 ;;
    feb* | Feb*)          m=2 ;;
    mar* | Mar*)          m=3 ;;
    apr* | Apr*)          m=4 ;;
    may* | May*)          m=5 ;;
    jun* | Jun*)          m=6 ;;
    jul* | Jul*)          m=7 ;;
    aug* | Aug*)          m=8 ;;
    sep* | Sep*)          m=9 ;;
    oct* | Oct*)          m=10 ;;
    nov* | Nov*)          m=11 ;;
    dec* | Dec*)          m=12 ;;
    [1-9] | 10 | 11 | 12) ;;
    *)                    j=$m ; m="" ;;
esac

# Call cal with correct arguments
cal $m $j

#-------------------------------------------------------------------------------
#-<EOF>
