#===============================================================================
# Snow Leopard Project
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
# Makefile
#-------------------------------------------------------------------------------
# Makefile for copying all libraries to the correct location.
#
# The correct locations are:
#   - libslstdc   -> PREFIX/lib/sl/stdc
#   - libslstdcpp -> Multiple locations
#       - .a / .so -> PREFIX/lib/sl/stdcpp
#       - .ecppl   -> PREFIX/lib/sl/ecppl  (ecppl are exported C++ libraries)
#
# This Makefile also fixes symbolic links in PREFIX/lib so the compiler and
# other tools can find them.
#
# Registration of libraries is also done where required.
#-------------------------------------------------------------------------------

#-<EOF>
