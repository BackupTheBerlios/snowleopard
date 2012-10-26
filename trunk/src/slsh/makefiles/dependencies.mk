#===============================================================================
# Snow Leopard Shell
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
# specific to the shell.
#-------------------------------------------------------------------------------

#-------------------------------------------------------------------------------
# Header file dependencies
#
CONFIG_SLSH_H_DEPS		= \
	$(CONFIG_C_INCLUDES)

MAIN_H_DEPS			= \
	$(PRG_INCLUDE)/config_slsh.h					\
	$(CONFIG_C_INCLUDES)

VERSION_SLSH_H_DEPS		= \
	$(CONFIG_C_INCLUDES)

#-------------------------------------------------------------------------------
# Source file dependencies
#
VERSION_SLSH_DEPS		= \
	$(PRG_INCLUDE)/config_slsh.h $(CONFIG_SLSH_H_DEPS)		\
	$(PRG_INCLUDE)/version_slsh.h $(VERSION_SLSH_H_DEPS)		\
	$(CONFIG_C_INCLUDES)

MAIN_DEPS			= \
	$(PRG_INCLUDE)/main.h $(MAIN_H_DEPS)

#-------------------------------------------------------------------------------
#<EOF>
