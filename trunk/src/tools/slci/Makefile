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
# File: /src/tools/slci/Makefile
#
# Makefile for building the Snow Leopard C++ interpreter.
#/

#
# Variables.
#
PROGRAM = slci

CFLAGS = -Wall -g

DEBUG_CFLAGS = -g

SLCI_INCLUDE = ../../include/sl/slci

SL_INCLUDE = ../../include

#
# All objects.
#
ALL_OBJECTS = binary_search.o driver.o error_codes.o error_handling.o \
	      hash_function.o info.o lexer.o lexer_functions.o main.o parser.o \
	      reader.o settings.o source_file.o source_position.o string.o \
	      symbol_table.o token.o version.o

BINARY_SEARCH_DEPENDS = $(SLCI_INCLUDE)/binary_search.h

DRIVER_DEPENDS = $(SLCI_INCLUDE)/driver.h $(SLCI_INCLUDE)/parser.h \
		 $(SLCI_INCLUDE)/settings.h

ERROR_CODES_DEPENDS = $(SLCI_INCLUDE)/error_codes.h

ERROR_HANDLING_DEPENDS = $(SLCI_INCLUDE)/error_codes.h \
			 $(SLCI_INCLUDE)/error_handling.h \
                         $(SLCI_INCLUDE)/source_position.h \
			 $(SLCI_INCLUDE)/source_file.h

HASH_FUNCTION_DEPENDS = $(SLCI_INCLUDE)/hash_function.h

INFO_DEPENDS = $(SLCI_INCLUDE)/info.h $(SLCI_INCLUDE)/version.h

LEXER_DEPENDS = $(SLCI_INCLUDE)/binary_search.h $(SLCI_INCLUDE)/error_codes.h \
		$(SLCI_INCLUDE)/error_handling.h $(SLCI_INCLUDE)/lexer.h \
		$(SLCI_INCLUDE)/lexer_functions.h $(SLCI_INCLUDE)/literal.h \
		$(SLCI_INCLUDE)/preprocessor.h $(SLCI_INCLUDE)/reader.h \
		$(SLCI_INCLUDE)/source_file.h $(SLCI_INCLUDE)/source_position.h \
		$(SLCI_INCLUDE)/string.h $(SLCI_INCLUDE)/symbol_table.h \
		$(SLCI_INCLUDE)/token.h

LEXER_FUNCTIONS_DEPENDS = $(SLCI_INCLUDE)/lexer_functions.h

MAIN_DEPENDS = $(SLCI_INCLUDE)/driver.h $(SLCI_INCLUDE)/error_codes.h \
	       $(SLCI_INCLUDE)/error_handling.h $(SLCI_INCLUDE)/info.h \
	       $(SLCI_INCLUDE)/settings.h $(SLCI_INCLUDE)/source_file.h \
	       $(SLCI_INCLUDE)/source_position.h 

PARSER_DEPENDS = $(SLCI_INCLUDE)/lexer.h $(SLCI_INCLUDE)/literal.h \
		 $(SLCI_INCLUDE)/parser.h $(SLCI_INCLUDE)/reader.h  \
		 $(SLCI_INCLUDE)/source_file.h $(SLCI_INCLUDE)/source_position.h \
		 $(SLCI_INCLUDE)/string.h $(SLCI_INCLUDE)/token.h

READER_DEPENDS = $(SLCI_INCLUDE)/reader.h $(SLCI_INCLUDE)/source_file.h \
		 $(SLCI_INCLUDE)/source_position.h

SETTINGS_DEPENDS = $(SLCI_INCLUDE)/settings.h

SOURCE_FILE_DEPENS = $(SLCI_INCLUDE)/source_file.h

SOURCE_POSITION_DEPENDS = $(SLCI_INCLUDE)/source_position.h \
			  $(SLCI_INCLUDE)/source_file.h

STRING_DEPENDS = $(SLCI_INCLUDE)/string.h

SYMBOL_TABLE_DEPENDS = $(SLCI_INCLUDE)/literal.h $(SLCI_INCLUDE)/source_file.h \
		       $(SLCI_INCLUDE)/source_position.h $(SLCI_INCLUDE)/string.h \
		       $(SLCI_INCLUDE)/symbol_table.h $(SLCI_INCLUDE)/token.h

TOKEN_DEPENDS = $(SLCI_INCLUDE)/literal.h $(SLCI_INCLUDE)/source_file.h \
		$(SLCI_INCLUDE)/source_position.h $(SLCI_INCLUDE)/string.h \
		$(SLCI_INCLUDE)/token.h

VERSION_DEPENDS = $(SLCI_INCLUDE)/version.h

#
# Main targets
#
all: what $(PROGRAM)

$(PROGRAM) : $(ALL_OBJECTS)
	$(CC) $(CFLAGS) -I$(SL_INCLUDE) -o slci $(ALL_OBJECTS)

binary_search.o: binary_search.c $(BINARY_SEARCH_DEPENDS)
	$(CC) -c $(CFLAGS) -I$(SL_INCLUDE) -o $@ $<

driver.o: driver.c $(DRIVER_DEPENDS)
	$(CC) -c $(CFLAGS) -I$(SL_INCLUDE) -o $@ $<

error_codes.o: error_codes.c $(ERROR_CODES_DEPENDS)
	$(CC) -c $(CFLAGS) -I$(SL_INCLUDE) -o $@ $<

error_handling.o: error_handling.c $(ERROR_HANDLING_DEPENDS)
	$(CC) -c $(CFLAGS) -I$(SL_INCLUDE) -o $@ $<

hash_function.o: hash_function.c $(HASH_FUNCTION_DEPENDS)
	$(CC) -c $(CFLAGS) -I$(SL_INCLUDE) -o $@ $<

info.o: info.c $(INFO_DEPENDS)
	$(CC) -c $(CFLAGS) -I$(SL_INCLUDE) -o $@ $<

lexer.o: lexer.c $(LEXER_DEPENDS)
	$(CC) -c $(CFLAGS) -I$(SL_INCLUDE) -o $@ $<

lexer_functions.o: lexer_functions.c $(LEXER_FUNCTIONS_DEPENDS)
	$(CC) -c $(CFLAGS) -I$(SL_INCLUDE) -o $@ $<

main.o: main.c $(MAIN_DEPENDS)
	$(CC) -c $(CFLAGS) -I$(SL_INCLUDE) -o $@ $<

parser.o: parser.c $(PARSER_DEPENDS)
	$(CC) -c $(CFLAGS) -I$(SL_INCLUDE) -o $@ $<

reader.o: reader.c $(READER_DEPENDS)
	$(CC) -c $(CFLAGS) -I$(SL_INCLUDE) -o $@ $<

settings.o: settings.c $(SETTINGS_DEPENDS)
	$(CC) -c $(CFLAGS) -I$(SL_INCLUDE) -o $@ $<

source_file.o: source_file.c $(SOURCE_FILE_DEPENDS)
	$(CC) -c $(CFLAGS) -I$(SL_INCLUDE) -o $@ $<

source_position.o: source_position.c $(SOURCE_POSITION_DEPENDS)
	$(CC) -c $(CFLAGS) -I$(SL_INCLUDE) -o $@ $<

symbol_table.o: symbol_table.c $(SYMBOL_TABLE_DEPENDS)
	$(CC) -c $(CFLAGS) -I$(SL_INCLUDE) -o $@ $<

string.o: string.c $(STRING_DEPENDS)
	$(CC) -c $(CFLAGS) -I$(SL_INCLUDE) -o $@ $<

token.o: token.c $(TOKEN_DEPENDS)
	$(CC) -c $(CFLAGS) -I$(SL_INCLUDE) -o $@ $<

version.o: version.c $(VERSION_DEPENDS)
	$(CC) -c $(CFLAGS) -I$(SL_INCLUDE) -o $@ $<

what:
	(echo Building the Snow Leopard C++ Interpreter); 

#
# Clean rule
#
clean:
	rm -f $(PROGRAM) ;     \
	rm -f $(ALL_OBJECTS) ; \
	rm -f *.core

#>- EOF
