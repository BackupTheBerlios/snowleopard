#===============================================================================
# Snow Leopard C++ Compiler Front End
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
# includes.mk
#-------------------------------------------------------------------------------
# Generated file containing a list of all includes files that are specific to
# the compiler front end.
#-------------------------------------------------------------------------------

#-------------------------------------------------------------------------------
# Variables
#
INCLUDES 	= \
	$(PRG_INCLUDE)/config_slcc.h 					\
	$(PRG_INCLUDE)/driver.h 					\
	$(PRG_INCLUDE)/error_codes.h					\
	$(PRG_INCLUDE)/error_handling.h					\
	$(PRG_INCLUDE)/info.h						\
	$(PRG_INCLUDE)/settings.h 					\
	$(PRG_INCLUDE)/types.h 						\
	$(PRG_INCLUDE)/version_slcc.h

LSLC_INCLUDES	= \
	$(PRG_INCLUDE)/tree.c.h						\
	$(PRG_INCLUDE)/tree.h						\
	$(PRG_INCLUDE)/vector.h

#-------------------------------------------------------------------------------
#<EOF>
