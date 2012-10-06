#===============================================================================
# Snow Leopard Compiler Project
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
# config.mk
#-------------------------------------------------------------------------------
# Configuration include for all Makefiles
#-------------------------------------------------------------------------------

#-------------------------------------------------------------------------------
# SLCI specific config
SLCI_CC = pcc

SLCI_CFLAGS = -std=gnu99 -D__SL_SLCI_NO_SL_STDLIB -Wall -Wextra -Werror -Wno-unused-function -Wno-unused-parameter
SLCI_DEBUG = -D__SLCI_DEBUG -D__SLCI_NO_DEBUG_SETTINGS -D__SLCI_DEBUG_SYMBOL_TABLES -g
#-------------------------------------------------------------------------------

#-------------------------------------------------------------------------------
# SLSH specific config
SLSH_CC = gcc

SLSH_CFLAGS = -std=gnu99 -D__SL_SLSH_NO_SL_STDLIB -Wall -Wextra -Werror -Wno-unused-function -Wno-unused-parameter
SLSH_DEBUG = -D__SLSH_DEBUG -D__SLSH_NO_DEBUG_SETTINGS -D__SLSH_DEBUG_SYMBOL_TABLES -g
#-------------------------------------------------------------------------------

#-------------------------------------------------------------------------------
# LYNX specific config
LYNX_CXX = /home/rsergeant/root/bin/g++

LYNX_CXXFLAGS = -std=c++11 -D__LYNX_NO_SL_STDLIB -Wall -Wextra -Werror -Wno-unused-function -Wno-unknown-pragmas
LYNX_DEBUG = -D__LYNX_DEBUG -gdwarf-2
#-------------------------------------------------------------------------------

#-------------------------------------------------------------------------------
# C config
CC = /home/rsergeant/root/bin/gcc

CFLAGS = -std=gnu11 -fno-builtin -D __STDC_WANT_LIB_EXT1__=1 -Wall -Werror -Wno-unused-function -Wno-unknown-pragmas -m64

CFLAGS_STATIC_LIB = 
CFLAGS_SHARED_LIB = -fPIC
SHARED_LIB_FVERSION = 0.0.1
SHARED_LIB_MVERSION = 0
AR_FLAGS =

DEBUG_CFLAGS = -g

CONFIG_C_HEADERS = sl/config/config.h
#-------------------------------------------------------------------------------

#-------------------------------------------------------------------------------
# C++ config
CXX = /home/rsergeant/root/bin/g++

CXXFLAGS = -std=c++11 -fno-builtin -D __STDC_WANT_LIB_EXT1__=1 -Wall -Werror -Wno-unused-function -Wno-unknown-pragmas -m64

CXXFLAGS_STATIC_LIB = 
CXXFLAGS_SHARED_LIB = -fPIC
SHARED_LIB_FVERSION = 0.0.1
SHARED_LIB_MVERSION = 0
AR_FLAGS =

DEBUG_CFLAGS = -g

CONFIG_CXX_HEADERS = sl/config/config.hpp
#-------------------------------------------------------------------------------

#-------------------------------------------------------------------------------
# <NetBSD>
BUILD_ROOT_DIR = /home/rsergeant/projects/build/snowleopard
#-------------------------------------------------------------------------------

#-<EOF>

