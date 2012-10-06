#!/bin/sh

#===============================================================================
# Snow Leopard Compiler Project
#
# Copyright (C) 2012 Roel Sergeant
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
# common.sh
#-------------------------------------------------------------------------------
# Common functions used in shell scripts.
#
# Functions are:
#   substring (str, start, [count])
#-------------------------------------------------------------------------------

#-------------------------------------------------------------------------------
# substring function
#
# This function uses AWK to get the substring of the given string. The third
# argument is optional. It writes the new string to standard output.
#
substring () {
    if [ $# = 3 ]
    then
	echo `awk -v t=$1 -v s=$2 -v l=$3 'BEGIN{print substr(t,s,l)}'`
    elif [ $# = 2 ]
    then
	echo `awk -v t=$1 -v s=$2 'BEGIN{print substr(t,s)}'`
    else
	echo ""
    fi
}
#-------------------------------------------------------------------------------

#===============================================================================
# export functions
export substring
#===============================================================================

#-<EOF>
