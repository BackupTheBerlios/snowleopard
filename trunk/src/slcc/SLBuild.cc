#===============================================================================
# Snow Leopard C++ Compiler Front End
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
# SLBuild.cc
#-------------------------------------------------------------------------------
# slbld configuration file for the compiler front end script.
#-------------------------------------------------------------------------------

#------------------------------------------------------------------------------
# slbld variables
#
SCRIPT			= cc

SLBLD_LIBS		= \
	libslsh		= [source]

SLBLD_FLAGS		= \
	[all]		= [strict]

COPYRIGHT_YEARS		= 2008, 2009, 2010, 2011, 2012
COPYRIGHT_OWNER		= Roel Sergeant
LICENSE			= GPLv3+

VERSION_MAJOR		= 0
VERSION_MINOR		= 0
VERSION_RELEASE		= 1
VERSION_BUILD		= 1
VERSION_NAME		= Pre-alpha

#------------------------------------------------------------------------------
#-<EOF>
