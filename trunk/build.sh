#!/bin/sh

#===============================================================================
# Snow Leopard Compiler Project
#
# Copyright (C) 2008, 2009, 2010, 2011, 2012 Roel Sergeant
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
# build.sh
#-------------------------------------------------------------------------------
# Build script for the compiler project. It is used to configure and build all
# components that are part of the project.
#------------------------------------------------------------------------------
# Command line arguments
#   --prefix=<path>  : Path used as prefix for installation of all components.
#   --configure_only : Configure and exit.
#   --reconfigure    : Reconfigure using the same setup.
#-------------------------------------------------------------------------------

#-<EOF>
