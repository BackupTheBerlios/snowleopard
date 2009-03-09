#-
# Copyright (c) 2009 Roel Sergeant.
# All rights reserved.
#
# This code is derived from software contributed to the Snow Leopard 
# project.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
# 1. Redistributions of source code must retain the above copyright
#    notice, this list of conditions and the following disclaimer.
# 2. Redistributions in binary form must reproduce the above copyright
#    notice, this list of conditions and the following disclaimer in the
#    documentation and/or other materials provided with the distribution.
#
# THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND ANY 
# EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED 
# WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE 
# DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS BE LIABLE FOR 
# ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL 
# DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR 
# SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER 
# CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, 
# OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
# OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#/

#-
# File: /src/test/3rd_party/Makefile
#
# Makefile for 3rd party libraries/programs used for real-world tests. 
#
# This Makefile has the following main targets (see configure --help-test for
# more information):
#   all        -> Builds nothing (3rd party tests take very long to build)
#   all-tests  -> Builds all LATEST_RELEASE versions
#   all-trunk  -> Builds all TRUNK versions
#   really-all -> Builds all LATEST_RELEASE and TRUNK
#
# The build process for these 3rd party libraries/programs is as follows: 
# TRUNK version
#   1) get trunk version from source repository.
#   2) check if the build system is supported (CMake, make) or included.
#   3) configure source tree (as slcc if supported or as gcc if slcc is not 
#                             supported by the build system).
#   4) build release.
#   5) check if test system is supported or included.
#   6) build tests.
#
# LATEST_RELEASE version
#   1) get latest released version from source repository.
#   2) check if the build system is supported (CMake, make) or included.
#   3) configure source tree (as slcc if supported or as gcc if slcc is not 
#                             supported by the build system).
#   4) build release.
#   5) check if test system is supported or included.
#   6) build tests.
#
# 3rd party list:
#   Apache HTTPD
#   Boost C++ Libraries
#   Firefox
#   GCC
#   Gnome
#   GNU Emacs
#   KDE
#   Linux
#   LLVM/Clang
#   NetBSD
#   Open Office
#   Thunderbird
#/

#
# All 3rd party.
#
ALL_3RD_PARTY = apache boost emacs firefox gcc gnome kde linux llvm netbsd \
		openoffice thunderbird

#
# Versions.
#
APACHE_SOURCE_CONTROL = 
APACHE_TRUNK_URL = 
APACHE_RELEASE_URL = 

BOOST_SOURCE_CONTROL = 
BOOST_TRUNK_URL = 
BOOST_RELEASE_URL = 

EMACS_SOURCE_CONTROL = 
EMACS_TRUNK_URL = 
EMACS_RELEASE_URL = 

FIREFOX_SOURCE_CONTROL = 
FIREFOX_TRUNK_URL = 
FIREFOX_RELEASE_URL = 

GCC_SOURCE_CONTROL = svn
GCC_TRUNK_URL = 
GCC_RELEASE_URL = 

GNOME_SOURCE_CONTROL = 
GNOME_TRUNK_URL = 
GNOME_RELEASE_URL = 

KDE_SOURCE_CONTROL = 
KDE_TRUNK_URL = 
KDE_RELEASE_URL = 

LINUX_SOURCE_CONTROL = 
LINUX_TRUNK_URL = 
LINUX_RELEASE_URL = 

LLVM_SOURCE_CONTROL = 
LLVM_TRUNK_URL = 
LLVM_RELEASE_URL = 

NETBSD_SOURCE_CONTROL = cvs
NETBSD_TRUNK_URL = 
NETBSD_RELEASE_URL = 

OPENOFFICE_SOURCE_CONTROL =
OPENOFFICE_TRUNK_URL =
OPENOFFICE_RELEASE_URL = 

THUNDERBIRD_SOURCE_CONTROL =
THUNDERBIRD_TRUNK_URL =
THUNDERBIRD_RELEASE_URL =

#
# Main targets.
#
all:
	echo Nothing to do for 3rd party

really-all: all-tests all-trunk

all-tests: latest-release $(ALL_3RD_PARTY)

all-trunk: trunk $(ALL_3RD_PARTY)

latest-release:
	echo Building latest release for 3rd party

trunk: 
	echo Building trunk version for 3rd party

apache: 

boost:

emacs:

firefox:

gcc:

gnome:

kde:

linux:

llvm:

netbsd:

openoffice:

thunderbird:

#
# Clean rule.
#
clean:
	rm -rf $(ALL_3RD_PARTY)

#>- EOF
