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
# sources.mk
#-------------------------------------------------------------------------------
# Generated file containing the source file rules used for the compiler front 
# end.
#-------------------------------------------------------------------------------

#-------------------------------------------------------------------------------
# Rules
#
driver.o  	: src/driver.c
	cc -c $(COMPILER_OPTS) src/driver.c

main.o		: src/main.c
	cc -c $(COMPILER_OPTS) src/main.c

settings.o	: src/settings.c
	cc -c $(COMPILER_OPTS) src/settings.c

types.o		: src/types.c
	cc -c $(COMPILER_OPTS) src/types.c

version_slcc.o	: src/version_slcc.c
	cc -c $(COMPILER_OPTS) src/version_slcc.c

#-------------------------------------------------------------------------------
#<EOF>
