#===============================================================================
# Snow Leopard Standard C Library
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
# dependencies.mk
#-------------------------------------------------------------------------------
# Generated file containing a list of all include file dependencies that are 
# specific to the standard C library.
#-------------------------------------------------------------------------------

#-------------------------------------------------------------------------------
# Header file dependencies
#
ASSERT_H_DEPS			= \
	$(LIB_PRIVATE_INCLUDE)/shared_types.h				\
	$(LIB_STDC_INCLUDE)/config_stdc.h				\
	$(LIB_STDC_INCLUDE)/assert.h					\
	$(CONFIG_C_INCLUDES)

STDDEF_H_DEPS			= \
	$(LIB_PRIVATE_INCLUDE)/shared_types.h				\
	$(LIB_STDC_INCLUDE)/config_stdc.h				\
	$(LIB_STDC_INCLUDE)/stddef.h					\
	$(CONFIG_C_INCLUDES)

STDIO_H_DEPS			=

VERSION_STDC_H_DEPS	= \
	$(LIB_STDC_INCLUDE)/config_stdc.h				\
	$(CONFIG_C_INCLUDES)						\
	$(VERSION_C_INCLUDES)

#-------------------------------------------------------------------------------
# Source file dependencies
#
ASSERT_DEPS			= \
	$(LIB_INCLUDE)/assert.h $(ASSERT_H_DEPS)			\
	$(LIB_INCLUDE)/stddef.h	$(STDDEF_H_DEPS)			\
	$(LIB_INCLUDE)/stdio.h $(STDIO_H_DEPS)

VERSION_STDC_DEPS		= \
	$(LIB_STDC_INCLUDE)/config_stdc.h $(CONFIG_STDC_H_DEPS)		\
	$(LIB_STDC_INCLUDE)/version_stdc.h $(VERSION_STDC_H_DEPS)	\
	$(CONFIG_C_INCLUDES)						\
	$(VERSION_C_INCLUDES)

#-------------------------------------------------------------------------------
#<EOF>
