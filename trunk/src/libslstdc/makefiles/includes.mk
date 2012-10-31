#===============================================================================
# Snow Leopard Standard C Library
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
# includes.mk
#-------------------------------------------------------------------------------
# Generated file containing a list of all includes files that are specific to
# the standard C library.
#-------------------------------------------------------------------------------

#-------------------------------------------------------------------------------
# Variables
#
INCLUDES_ROOT		= \
	$(LIB_INCLUDE)/assert.h						\
	$(LIB_INCLUDE)/complex.h					\
	$(LIB_INCLUDE)/ctype.h						\
	$(LIB_INCLUDE)/errno.h						\
	$(LIB_INCLUDE)/float.h						\
	$(LIB_INCLUDE)/inttypes.h					\
	$(LIB_INCLUDE)/iso646.h						\
	$(LIB_INCLUDE)/limits.h						\
	$(LIB_INCLUDE)/stdarg.h						\
	$(LIB_INCLUDE)/stdbool.h					\
	$(LIB_INCLUDE)/stddef.h						\
	$(LIB_INCLUDE)/stdio.h						\
	$(LIB_INCLUDE)/stdlib.h

LIB_STDC_INCLUDE 	= $(LIB_INCLUDE)/stdc

INCLUDES_STDC		= \
	$(LIB_STDC_INCLUDE)/assert.h					\
	$(LIB_STDC_INCLUDE)/complex.h					\
	$(LIB_STDC_INCLUDE)/config_stdc.h				\
	$(LIB_STDC_INCLUDE)/ctype.h					\
	$(LIB_STDC_INCLUDE)/errno.h					\
	$(LIB_STDC_INCLUDE)/float.h					\
	$(LIB_STDC_INCLUDE)/inttypes.h					\
	$(LIB_STDC_INCLUDE)/iso646.h					\
	$(LIB_STDC_INCLUDE)/limits.h					\
	$(LIB_STDC_INCLUDE)/stdarg.h					\
	$(LIB_STDC_INCLUDE)/stdbool.h					\
	$(LIB_STDC_INCLUDE)/stddef.h					\
	$(LIB_STDC_INCLUDE)/stdio.h					\
	$(LIB_STDC_INCLUDE)/stdio_types.h				\
	$(LIB_STDC_INCLUDE)/stdlib.h					\
	$(LIB_STDC_INCLUDE)/version_stdc.h				

LIB_PRIVATE_INCLUDE	= $(LIB_STDC_INCLUDE)/private

INCLUDES_PRIVATE	= \
	$(LIB_PRIVATE_INCLUDE)/ll_open_files.h				\
	$(LIB_PRIVATE_INCLUDE)/program_globals.h			\
	$(LIB_PRIVATE_INCLUDE)/shared_macros.h				\
	$(LIB_PRIVATE_INCLUDE)/shared_types.h				\
	$(LIB_PRIVATE_INCLUDE)/stdio_private.h

INCLUDES 		= \
	$(INCLUDES_ROOT)						\
	$(INCLUDES_STDC)						\
	$(INCLUDES_PRIVATE)

.include "../../libsltc/makefiles/includes.mk"

#-------------------------------------------------------------------------------
#<EOF>
