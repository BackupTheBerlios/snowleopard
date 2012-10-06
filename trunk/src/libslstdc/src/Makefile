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
# Makefile
#-------------------------------------------------------------------------------
# Makefile for building the Snow Leopard standard C library
#-------------------------------------------------------------------------------

#-------------------------------------------------------------------------------
# Include files.
include ../../../scripts/makefiles/config.mk
#-------------------------------------------------------------------------------

#-------------------------------------------------------------------------------
# Variables
SL_INCLUDE = ../../../include
SL_STDC_INCLUDE = ../../../include/sl
SL_STDC_IMPL_INCLUDE = ../../../include/sl/stdc

SLSTDC_BUILD_DIR = $(BUILD_ROOT_DIR)/lib/libstdc

STATIC_LIBRARY = libslstdc.a
STATIC_OUT_LIBRARY = $(addprefix $(SLSTDC_BUILD_DIR)/,$(STATIC_LIBRARY))

SHARED_LIBRARY = libslstdc.so.
SHARED_OUT_LIBRARY = $(addsuffix $(SHARED_LIB_FVERSION),$(addprefix $(SLSTDC_BUILD_DIR)/,$(SHARED_LIBRARY)))
SHARED_SO_NAME = $(addsuffix $(SHARED_LIB_MVERSION),$(SHARED_LIBRARY))

STDC_CONFIG_HEADERS = $(addprefix $(SL_INCLUDE)/,$(CONFIG_C_HEADERS))
#-------------------------------------------------------------------------------

#-------------------------------------------------------------------------------
# All objects
ALL_SOURCES = \
	assert.c complex.c ctype.c errno.c locale.c math.c math_error_gamma.c \
	math_exp_log.c math_hyperbolic.c math_nearest_int.c math_pow_abs.c \
	math_remainder.c math_trigonometric.c program_startup.c signal.c \
	stdio_char_io.c stdio_file_access.c stdio_printf.c stdio_scanf.c \
	stdlib_env.c stdlib_memory.c string.c threads.c time.c wchar.c \
	private/ll_mm_blocks.c private/ll_mm_pages.c private/ll_open_files.c \
	private/memory_manager.c private/program_globals.c \
	private/stdio_private.c

ALL_OUT_OBJECTS = $(addprefix $(SLSTDC_BUILD_DIR)/,$(ALL_SOURCES:.c=.o))
ALL_DEPENDENCY_OBJECTS = \
	$(addprefix $(SLSTDC_BUILD_DIR)/,$(ALL_SOURCES:.c=.d))
#-------------------------------------------------------------------------------

#-------------------------------------------------------------------------------
# Targets
all: $(SHARED_OUT_LIBRARY) $(STATIC_OUT_LIBRARY)

$(STATIC_OUT_LIBRARY): $(ALL_OUT_OBJECTS)
	$(AR) rcs $(STATIC_OUT_LIBRARY) $(ALL_OUT_OBJECTS)

$(SHARED_OUT_LIBRARY): $(ALL_OUT_OBJECTS)
	$(CC) -shared -Wl,-soname,$(SHARED_SO_NAME) -o $(SHARED_OUT_LIBRARY) $(ALL_OUT_OBJECTS)

$(SLSTDC_BUILD_DIR)/%.d: %.c | create_build_directory
	$(CC) -M -MT $(addprefix $(SLSTDC_BUILD_DIR)/,$(<:.c=.o)) $(CFLAGS) -I$(SL_INCLUDE) $< > $@

$(SLSTDC_BUILD_DIR)/%.o: %.c | create_build_directory
	$(CC) -c $(CFLAGS) $(CFLAGS_STATIC_LIB) $(CFLAGS_SHARED_LIB) -I$(SL_INCLUDE) $< -o $@

-include $(ALL_DEPENDENCY_OBJECTS)

#-------------------------------------------------------------------------------

#-------------------------------------------------------------------------------
# Create Directory
create_build_directory:
	mkdir -p $(addsuffix /private, $(SLSTDC_BUILD_DIR)) 
#-------------------------------------------------------------------------------

#-------------------------------------------------------------------------------
# Clean depends
clean_depends:
	rm -f $(ALL_DEPENDENCY_OBJECTS)
#-------------------------------------------------------------------------------

#-------------------------------------------------------------------------------
# Clean rule
clean:
	rm -f $(SHARED_OUT_LIBRARY) $(STATIC_OUT_LIBRARY) ;     \
	rm -f $(ALL_OUT_OBJECTS) ;                   		\
	rm -f $(ALL_DEPENDENCY_OBJECTS) ;			\
	rm -f $(SLSTDC_BUILD_DIR)/*.core
#-------------------------------------------------------------------------------

#-<EOF>
