#===============================================================================
# Snow Leopard Project
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
# Makefile
#-------------------------------------------------------------------------------
# Makefile for building and installing all components in the Snow Leopard 
# project.
#-------------------------------------------------------------------------------

#-------------------------------------------------------------------------------
# Variables
#
DIRS = bin include lib src share

#-------------------------------------------------------------------------------
# Rules
#
all: src

install: bin include share src

bin: src lib
	(cd bin ; ${MAKE} all);	 

include: src lib
	(cd include ; ${MAKE} all);	 

lib: src
	(cd lib ; ${MAKE} all);	 

share: src
	(cd share ; ${MAKE} all);

src:
	(cd src ; ${MAKE} all);	 

www: src
	(cd www ; ${MAKE} all);

clean:
	for dir in $(DIRS); do     		\
		(cd $$dir ; ${MAKE} clean); 	\
	done

#-------------------------------------------------------------------------------
#-<EOF>
