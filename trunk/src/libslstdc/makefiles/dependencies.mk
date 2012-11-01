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
# dependencies.mk
#-------------------------------------------------------------------------------
# Generated file containing a list of all include file dependencies that are 
# specific to the standard C library.
#-------------------------------------------------------------------------------

#-------------------------------------------------------------------------------
# Header file dependencies
#
ASSERT_H_DEPS			= \
	$(LIB_STDC_INCLUDE)/config_stdc.h				\
	$(LIB_STDC_INCLUDE)/assert.h					\
	$(CONFIG_C_INCLUDES)

COMPLEX_H_DEPS			= \
	$(LIB_STDC_INCLUDE)/config_stdc.h				\
	$(LIB_STDC_INCLUDE)/complex.h					\
	$(CONFIG_C_INCLUDES)

CONFIG_STDC_H_DEPS		= \
	$(CONFIG_C_INCLUDES)

CTYPE_H_DEPS			= \
	$(LIB_STDC_INCLUDE)/config_stdc.h				\
	$(CONFIG_C_INCLUDES)

ERRNO_H_DEPS			= \
	$(LIB_PRIVATE_INCLUDE)/shared_types.h				\
	$(LIB_STDC_INCLUDE)/config_stdc.h				\
	$(CONFIG_C_INCLUDES)

FLOAT_H_DEPS			= \
	$(LIB_STDC_INCLUDE)/config_stdc.h				\
	$(CONFIG_C_INCLUDES)

INTTYPES_H_DEPS			= \
	$(LIB_PRIVATE_INCLUDE)/shared_types.h				\
	$(LIB_STDC_INCLUDE)/config_stdc.h				\
	$(LIB_STDC_INCLUDE)/inttypes.h					\
	$(CONFIG_C_INCLUDES)

ISO646_H_DEPS			= \
	$(LIB_STDC_INCLUDE)/config_stdc.h				\
	$(LIB_STDC_INCLUDE)/iso646.h					\
	$(CONFIG_C_INCLUDES)

LIMITS_H_DEPS			= \
	$(LIB_STDC_INCLUDE)/config_stdc.h				\
	$(LIB_STDC_INCLUDE)/limits.h					\
	$(CONFIG_C_INCLUDES)

LOCALE_H_DEPS			= \
	$(LIB_STDC_INCLUDE)/config_stdc.h				\
	$(LIB_STDC_INCLUDE)/locale.h					\
	$(CONFIG_C_INCLUDES)

STDARG_H_DEPS			= \
	$(LIB_PRIVATE_INCLUDE)/shared_types.h				\
	$(LIB_STDC_INCLUDE)/config_stdc.h				\
	$(LIB_STDC_INCLUDE)/stdarg.h					\
	$(CONFIG_C_INCLUDES)

STDBOOL_H_DEPS			= \
	$(LIB_STDC_INCLUDE)/config_stdc.h				\
	$(LIB_STDC_INCLUDE)/stdbool.h					\
	$(CONFIG_C_INCLUDES)

STDDEF_H_DEPS			= \
	$(LIB_PRIVATE_INCLUDE)/shared_macros.h				\
	$(LIB_PRIVATE_INCLUDE)/shared_types.h				\
	$(LIB_STDC_INCLUDE)/config_stdc.h				\
	$(LIB_STDC_INCLUDE)/stddef.h					\
	$(CONFIG_C_INCLUDES)

STDIO_H_DEPS			= \
	$(LIB_PRIVATE_INCLUDE)/shared_macros.h				\
	$(LIB_PRIVATE_INCLUDE)/shared_types.h				\
	$(LIB_PRIVATE_INCLUDE)/stdio_private.h				\
	$(LIB_STDC_INCLUDE)/config_stdc.h				\
	$(LIB_STDC_INCLUDE)/stdio.h					\
	$(LIB_STDC_INCLUDE)/stdio_types.h				\
	$(CONFIG_C_INCLUDES)

STDLIB_H_DEPS			=

VERSION_STDC_H_DEPS		= \
	$(LIB_STDC_INCLUDE)/config_stdc.h				\
	$(CONFIG_C_INCLUDES)						\
	$(VERSION_C_INCLUDES)

#-------------------------------------------------------------------------------
# Private header dependencies
#
P_LL_OPEN_FILES_H_DEPS		= \
	$(LIB_STDC_INCLUDE)/config_stdc.h				\
	$(LIB_STDC_INCLUDE)/stdio_types.h				\
	$(CONFIG_C_INCLUDES)						\
	$(TC_INCLUDES)

P_PROGRAM_GLOBALS_H_DEPS	= \
	$(LIB_PRIVATE_INCLUDE)/ll_open_files.h				\
	$(LIB_STDC_INCLUDE)/config_stdc.h				\
	$(LIB_STDC_INCLUDE)/stdio_types.h

P_STDIO_PRIVATE_H_DEPS		= \
	$(LIB_PRIVATE_INCLUDE)/shared_types.h				\
	$(LIB_STDC_INCLUDE)/config_stdc.h				\
	$(LIB_STDC_INCLUDE)/stdio_types.h

#-------------------------------------------------------------------------------
# Source file dependencies
#
ERRNO_DEPS			= \
	$(LIB_INCLUDE)/errno.h $(ERRNO_H_DEPS)

FOPEN_DEPS			= \
	$(LIB_INCLUDE)/stddef.h $(STDDEF_H_DEPS)			\
	$(LIB_INCLUDE)/stdio.h $(STDIO_H_DEPS)				\
	$(LIB_INCLUDE)/stdlib.h $(STDLIB_H_DEPS)			\
	$(LIB_PRIVATE_INCLUDE)/ll_open_files.h				\
		$(P_LL_OPEN_FILES_H_DEPS)				\
	$(LIB_PRIVATE_INCLUDE)/program_globals.h			\
		$(P_PROGRAM_GLOBALS_H_DEPS)				\
	$(LIB_PRIVATE_INCLUDE)/stdio_private.h 				\
		$(P_STDIO_PRIVATE_H_DEPS)

ISALNUM_DEPS			= \
	$(LIB_INCLUDE)/ctype.h $(CTYPE_H_DEPS)

ISALPHA_DEPS			= \
	$(LIB_INCLUDE)/ctype.h $(CTYPE_H_DEPS)

ISBLANK_DEPS			= \
	$(LIB_INCLUDE)/ctype.h $(CTYPE_H_DEPS)

ISCNTRL_DEPS			= \
	$(LIB_INCLUDE)/ctype.h $(CTYPE_H_DEPS)

ISDIGIT_DEPS			= \
	$(LIB_INCLUDE)/ctype.h $(CTYPE_H_DEPS)

ISGRAPH_DEPS			= \
	$(LIB_INCLUDE)/ctype.h $(CTYPE_H_DEPS)

ISLOWER_DEPS			= \
	$(LIB_INCLUDE)/ctype.h $(CTYPE_H_DEPS)

ISPRINT_DEPS			= \
	$(LIB_INCLUDE)/ctype.h $(CTYPE_H_DEPS)

ISPUNCT_DEPS			= \
	$(LIB_INCLUDE)/ctype.h $(CTYPE_H_DEPS)

ISSPACE_DEPS			= \
	$(LIB_INCLUDE)/ctype.h $(CTYPE_H_DEPS)

ISUPPER_DEPS			= \
	$(LIB_INCLUDE)/ctype.h $(CTYPE_H_DEPS)

ISXDIGIT_DEPS			= \
	$(LIB_INCLUDE)/ctype.h $(CTYPE_H_DEPS)

TOLOWER_DEPS			= \
	$(LIB_INCLUDE)/ctype.h $(CTYPE_H_DEPS)

TOUPPER_DEPS			= \
	$(LIB_INCLUDE)/ctype.h $(CTYPE_H_DEPS)

VERSION_STDC_DEPS		= \
	$(LIB_STDC_INCLUDE)/config_stdc.h $(CONFIG_STDC_H_DEPS)		\
	$(LIB_STDC_INCLUDE)/version_stdc.h $(VERSION_STDC_H_DEPS)	\
	$(CONFIG_C_INCLUDES)						\
	$(VERSION_C_INCLUDES)

XASSERT_DEPS			= \
	$(LIB_INCLUDE)/assert.h $(ASSERT_H_DEPS)			\
	$(LIB_INCLUDE)/stdio.h $(STDIO_H_DEPS)				\
	$(LIB_INCLUDE)/stdlib.h $(STDLIB_H_DEPS)

XCTYPE_DEPS			= \
	$(LIB_INCLUDE)/ctype.h $(CTYPE_H_DEPS)				\
	$(LIB_INCLUDE)/limits.h $(LIMITS_H_DEPS)			\
	$(LIB_INCLUDE)/stdio.h $(STDIO_H_DEPS)

XTOLOWER_DEPS			= \
	$(LIB_INCLUDE)/ctype.h $(CTYPE_H_DEPS)				\
	$(LIB_INCLUDE)/limits.h $(LIMITS_H_DEPS)			\
	$(LIB_INCLUDE)/stdio.h $(STDIO_H_DEPS)

XTOUPPER_DEPS			= \
	$(LIB_INCLUDE)/ctype.h $(CTYPE_H_DEPS)				\
	$(LIB_INCLUDE)/limits.h $(LIMITS_H_DEPS)			\
	$(LIB_INCLUDE)/stdio.h $(STDIO_H_DEPS)

#-------------------------------------------------------------------------------
#<EOF>
