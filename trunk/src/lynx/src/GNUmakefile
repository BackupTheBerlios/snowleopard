#===============================================================================
# Lynx Typesetting System
#
# Copyright (C) 2010-2012 Roel Sergeant
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
# Makefile for building the Lynx typesetting system.
#-------------------------------------------------------------------------------

#-------------------------------------------------------------------------------
# Include files.
include ../../scripts/makefiles/config.mk
#-------------------------------------------------------------------------------

#-------------------------------------------------------------------------------
# Variables.
LYNX_INCLUDE = ../../include/lynx

LYNX_CONFIG_INCLUDE = ../../include/sl

LYNX_BUILD_DIR = $(BUILD_ROOT_DIR)/tools/lynx
LYNX = lynx
OUT_LYNX = $(addprefix $(LYNX_BUILD_DIR)/,$(LYNX))
LROFF = lroff
OUT_LROFF = $(addprefix $(LYNX_BUILD_DIR)/,$(LROFF))
LEQN = leqn
OUT_LEQN = $(addprefix $(LYNX_BUILD_DIR)/,$(LEQN))
LPIC = lpic
OUT_LPIC = $(addprefix $(LYNX_BUILD_DIR)/,$(LPIC))
LREFER = lrefer
OUT_LREFER = $(addprefix $(LYNX_BUILD_DIR)/,$(LREFER))
LTBL = ltbl
OUT_LTBL = $(addprefix $(LYNX_BUILD_DIR)/,$(LTBL))
LSOELIM = lsoelim
OUT_LSOELIM = $(addprefix $(LYNX_BUILD_DIR)/,$(LSOELIM))
ALL_PROGRAMS = $(LYNX) $(LROFF) $(LEQN) $(LPIC) $(LREFER) $(LTBL) $(LSOELIM)
ALL_OUT_PROGRAMS = $(addprefix $(LYNX_BUILD_DIR)/,$(ALL_PROGRAMS))
#-------------------------------------------------------------------------------

#-------------------------------------------------------------------------------
# All objects
ALL_SOURCES = \
	driver.cpp info.cpp leqn_main.cpp lpic_main.cpp lrefer_main.cpp \
	lroff_main.cpp lsoelim_main.cpp ltbl_main.cpp lynx_main.cpp version.cpp

ALL_LYNX_SOURCES = \
	driver.cpp info.cpp lynx_main.cpp version.cpp

ALL_LROFF_SOURCES = \
	driver.cpp info.cpp lroff_main.cpp version.cpp

ALL_LEQN_SOURCES = \
	driver.cpp info.cpp leqn_main.cpp version.cpp

ALL_LPIC_SOURCES = \
	driver.cpp info.cpp lpic_main.cpp version.cpp

ALL_LREFER_SOURCES = \
	driver.cpp info.cpp lrefer_main.cpp version.cpp

ALL_LTBL_SOURCES = \
	driver.cpp info.cpp ltbl_main.cpp version.cpp

ALL_LSOELIM_SOURCES = \
	driver.cpp info.cpp lsoelim_main.cpp version.cpp

ALL_OUT_OBJECTS = $(addprefix $(LYNX_BUILD_DIR)/,$(ALL_SOURCES:.cpp=.o))
ALL_DEPENDENCY_OBJECTS = \
	$(addprefix $(LYNX_BUILD_DIR)/,$(ALL_SOURCES:.cpp=.d))

ALL_LYNX_OBJECTS = $(addprefix $(LYNX_BUILD_DIR)/,$(ALL_LYNX_SOURCES:.cpp=.o))
ALL_LROFF_OBJECTS = $(addprefix $(LYNX_BUILD_DIR)/,$(ALL_LROFF_SOURCES:.cpp=.o))
ALL_LEQN_OBJECTS = $(addprefix $(LYNX_BUILD_DIR)/,$(ALL_LEQN_SOURCES:.cpp=.o))
ALL_LPIC_OBJECTS = $(addprefix $(LYNX_BUILD_DIR)/,$(ALL_LPIC_SOURCES:.cpp=.o))
ALL_LREFER_OBJECTS = $(addprefix $(LYNX_BUILD_DIR)/,$(ALL_LREFER_SOURCES:.cpp=.o))
ALL_LTBL_OBJECTS = $(addprefix $(LYNX_BUILD_DIR)/,$(ALL_LTBL_SOURCES:.cpp=.o))
ALL_LSOELIM_OBJECTS = $(addprefix $(LYNX_BUILD_DIR)/,$(ALL_LSOELIM_SOURCES:.cpp=.o))
#-------------------------------------------------------------------------------

#-------------------------------------------------------------------------------
# Main targets
all: $(ALL_OUT_PROGRAMS)

$(OUT_LYNX): $(ALL_LYNX_OBJECTS)
	$(LYNX_CXX) $(LYNX_CXXFLAGS) $(LYNX_DEBUG) -o $(OUT_LYNX) $(ALL_LYNX_OBJECTS)

$(OUT_LROFF): $(ALL_LROFF_OBJECTS)
	$(LYNX_CXX) $(LYNX_CXXFLAGS) $(LYNX_DEBUG) -o $(OUT_LROFF) $(ALL_LROFF_OBJECTS)

$(OUT_LEQN): $(ALL_LEQN_OBJECTS)
	$(LYNX_CXX) $(LYNX_CXXFLAGS) $(LYNX_DEBUG) -o $(OUT_LEQN) $(ALL_LEQN_OBJECTS)

$(OUT_LPIC): $(ALL_LPIC_OBJECTS)
	$(LYNX_CXX) $(LYNX_CXXFLAGS) $(LYNX_DEBUG) -o $(OUT_LPIC) $(ALL_LPIC_OBJECTS)

$(OUT_LREFER): $(ALL_LREFER_OBJECTS)
	$(LYNX_CXX) $(LYNX_CXXFLAGS) $(LYNX_DEBUG) -o $(OUT_REFER) $(ALL_LREFER_OBJECTS)

$(OUT_LTBL): $(ALL_LTBL_OBJECTS)
	$(LYNX_CXX) $(LYNX_CXXFLAGS) $(LYNX_DEBUG) -o $(OUT_LTBL) $(ALL_LTBL_OBJECTS)

$(OUT_LSOELIM): $(ALL_LSOELIM_OBJECTS)
	$(LYNX_CXX) $(LYNX_CXXFLAGS) $(LYNX_DEBUG) -o $(OUT_LSOELIM) $(ALL_LSOELIM_OBJECTS)

$(LYNX_BUILD_DIR)/%.d: %.cpp | create_build_dirs
	$(LYNX_CXX) -M -MT $(addprefix $(LYNX_BUILD_DIR)/,$(<:.cpp=.o)) $(LYNX_CXXFLAGS) -I$(LYNX_INCLUDE) -I$(LYNX_CONFIG_INCLUDE) $< > $@

$(LYNX_BUILD_DIR)/%.o: %.cpp | create_build_dirs
	$(LYNX_CXX) -c $(LYNX_CXXFLAGS) $(LYNX_DEBUG) -I$(LYNX_INCLUDE) -I$(LYNX_CONFIG_INCLUDE) $< -o $@

-include $(ALL_DEPENDENCY_OBJECTS)
#-------------------------------------------------------------------------------

#-------------------------------------------------------------------------------
# Create directory
create_build_dirs:
	mkdir -p $(LYNX_BUILD_DIR) 
#-------------------------------------------------------------------------------

#-------------------------------------------------------------------------------
# Clean depends
clean_depends:
	rm -f $(ALL_DEPENDENCY_OBJECTS)
#-------------------------------------------------------------------------------

#-------------------------------------------------------------------------------
# Clean rule
clean:
	rm -rf $(ALL_OUT_PROGRAMS) ;			\
	rm -rf $(addsuffix .exe,$(ALL_OUT_PROGRAMS)) ;	\
	rm -rf $(ALL_OUT_OBJECTS) ;			\
	rm -rf $(ALL_DEPENDENCY_OBJECTS) ;		\
	rm -rf $(LYNX_BUILD_DIR)/*.core ;		\
	rm -rf $(LYNX_BUILD_DIR)
#-------------------------------------------------------------------------------

#-<EOF>
