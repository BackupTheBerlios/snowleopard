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
# Makefile for building all components in the Snow Leopard project.
#-------------------------------------------------------------------------------

#-------------------------------------------------------------------------------
# Variables
#
MODULES = \
	libsh libslstdc libslstdcpp libsltc libsltst lynx puma slbld slcc slsh \
	sltst 

#-------------------------------------------------------------------------------
# Rules
#
all		: $(MODULES)

libsh		:
	(cd libsh ; ${MAKE} all);

libslstdc	:
	(cd libslstdc ; ${MAKE} all);	 

libslstdcpp	:
	(cd libslstdcpp ; ${MAKE} all);	 

libsltc		:
	(cd libsltc ; ${MAKE} all);

libsltst	:
	(cd libsltst ; ${MAKE} all);

lynx		:
	(cd lynx ; ${MAKE} all);	 

puma		:
	(cd puma ; ${MAKE} all);

slbld		:
	(cd slbld ; ${MAKE} all);

slcc		:
	(cd slcc ; ${MAKE} all);	 

slsh		:
	(cd slsh ; ${MAKE} all);

sltst		:
	(cd sltst ; ${MAKE} all);

#-------------------------------------------------------------------------------
# Special rules
#
clean		:
	for dir in $(MODULES); do     		\
		(cd $$dir ; ${MAKE} clean); 	\
	done

distclean	:
	for dir in $(MODULES); do		\
		(cd $$dir ; ${MAKE} distclean); \
	done

test		:
	for dir in $(MODULES); do		\
		(cd $$dir ; ${MAKE} test);	\
	done

#-------------------------------------------------------------------------------
#-<EOF>
