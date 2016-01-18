#!/bin/bash

# Go compiler
GO = i686-elf-gccgo
GOPS = -static -Werror -nostdlib -nostartfiles -nodefaultlibs

# Find crtbegin.o & crtend.o
CRTBEGIN = $(shell $(GO) $(GOPS) -print-file-name=crtbegin.o)
CRTEND = $(shell $(GO) $(GOPS) -print-file-name=crtend.o)

# Source files
OBJS = main.o 

all: $(OBJS)
	$(GO) -T ../linker.ld -o ../migo.krn $(GOPS) ../crti.o $(CRTBEGIN) ../runtime.o $(OBJS) $(CRTEND) ../crtn.o -lgcc
	rm *.o

%.o: %.go
	$(GO) $(GOPS) -o $@ -c $< -I../include
