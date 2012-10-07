#===============================================================================
# Snow Leopard Standard C++ Library
#
# Copyright (C) 2008-2012 Roel Sergeant
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
# Makefile for building the Snow Leopard standard C++ library
#-------------------------------------------------------------------------------

#-------------------------------------------------------------------------------
# Include files.
include ../../../scripts/makefiles/config.mk
#-------------------------------------------------------------------------------

#-------------------------------------------------------------------------------
# Variables
SL_INCLUDE = ../../../include
SL_C_INCLUDE = ../../../include/sl
SL_CXX_INCLUDE = ../../../include/sl
STDC_IMPL_INCLUDE = ../../../include/sl/stdc
STDCXX_IMPL_INCLUDE = ../../../include/sl/stdcpp

SLSTDCXX_BUILD_DIR = $(BUILD_ROOT_DIR)/lib/libstdcpp

STATIC_LIBRARY = libslstdcpp.a
STATIC_OUT_LIBRARY = $(addprefix $(SLSTDCXX_BUILD_DIR)/,$(STATIC_LIBRARY))

SHARED_LIBRARY = libslstdcpp.so.
SHARED_OUT_LIBRARY = \
	$(addsuffix $(SHARED_LIB_FVERSION),$(addprefix $(SLSTDCXX_BUILD_DIR)/,$(SHARED_LIBRARY)))
SHARED_SO_NAME = $(addsuffix $(SHARED_LIB_MVERSION),$(SHARED_LIBRARY))

STDCXX_CONFIG_HEADERS = $(addprefix $(SL_INCLUDE)/,$(CONFIG_CXX_HEADERS))
#-------------------------------------------------------------------------------

#-------------------------------------------------------------------------------
# All objects
ALL_SOURCES = \
	csignal.cpp cstdio.cpp cstdlib.cpp cstring.cpp exception.cpp \
	new.cpp stdexcept.cpp system_error.cpp typeinfo.cpp

#
# Excluded because not buildable yet: iostream.cpp
#

ALL_OUT_OBJECTS = $(addprefix $(SLSTDCXX_BUILD_DIR)/,$(ALL_SOURCES:.cpp=.o))
ALL_DEPENDENCY_OBJECTS = \
	$(addprefix $(SLSTDCXX_BUILD_DIR)/,$(ALL_SOURCES:.cpp=.d))
#-------------------------------------------------------------------------------
all: $(STATIC_OUT_LIBRARY) $(SHARED_OUT_LIBRARY)

$(STATIC_OUT_LIBRARY): $(ALL_OUT_OBJECTS)
	$(AR) rcs $(STATIC_OUT_LIBRARY) $(ALL_OUT_OBJECTS)

$(SHARED_OUT_LIBRARY): $(ALL_OUT_OBJECTS)
	$(CXX) -shared -Wl,-soname,$(SHARED_SO_NAME) -o $(SHARED_OUT_LIBRARY) $(ALL_OUT_OBJECTS)

$(SLSTDCXX_BUILD_DIR)/%.d: %.cpp | create_build_directory
	$(CXX) -M -MT $(addprefix $(SLSTDCXX_BUILD_DIR)/,$(<:.cpp=.o)) $(CXXFLAGS) -I$(SL_INCLUDE) $< > $@

$(SLSTDCXX_BUILD_DIR)/%.o: %.cpp | create_build_directory
	$(CXX) -c $(CXXFLAGS) $(CXXFLAGS_STATIC_LIB) $(CXXFLAGS_SHARED_LIB) -I$(SL_INCLUDE) $< -o $@

-include $(ALL_DEPENDENCY_OBJECTS)

#-------------------------------------------------------------------------------

#-------------------------------------------------------------------------------
# Create Directory
create_build_directory:
	mkdir -p $(SLSTDCXX_BUILD_DIR) 
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
	rm -f $(SLSTDCXX_BUILD_DIR)/*.core
#-------------------------------------------------------------------------------

#-<EOF>
