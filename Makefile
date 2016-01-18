# Libmigo - Bare metal runtime for Go
# Version: 0.1 Alfa
# License: BSD
# By: Gert Nutterts

# i686-elf is the only supported target at this time
TARGET := i686-elf

# Compilers, linker & assembler
GCC = $(TARGET)-gcc
GO = $(TARGET)-gccgo
LD = $(TARGET)-ld 
AS = $(TARGET)-as

# Options for the various tools
AOPS = --warn --fatal-warnings
COPS = -Wall -ffreestanding -O2 -nostdlib
GOPS = -static -Werror -nostdlib -nostartfiles -nodefaultlibs

# Find crtbegin.o & crtend.o
CRTBEGIN = $(shell $(GCC) $(COPS) -print-file-name=crtbegin.o)
CRTEND = $(shell $(GCC) $(COPS) -print-file-name=crtend.o)

# C source files
C_OBJS = $(shell ls runtime/c/*.c | xargs | sed 's/\.c/\.c\.o/g')

# Assembler source filesls
ASM_OBJS = $(shell ls runtime/asm/*.s | xargs | sed 's/\.s/\.s\.o/g')

# Remember current path
LIBMIGO_PATH = $(shell pwd)

# Heap size
ifndef heap
	MEMSIZE = 8388608 # 8MiB - default size
else
	MEMSIZE = $(shell echo $$(($(heap)*1024*1024)))
endif 

# Stack size
ifndef stack
	STACKSIZE = 16384
else
	STACKSIZE = $(shell echo $$(($(stack)*1024)))
endif 

# If no packages are specified, link them all
PKGS = errors \
		unicode unicode/utf8 unicode/utf16 \
		runtime/textmode

# Default rule
all: clean runtime packages migo

runtime: $(C_OBJS) $(ASM_OBJS)
	cat runtime/asm/rt.template | sed 's/%MEMSIZE%/$(MEMSIZE)/g' | sed 's/%STACKSIZE%/$(STACKSIZE)/g' > runtime/asm/rt.asm
	$(AS) $(AOPS) -o runtime/asm/rt.o -c runtime/asm/rt.asm
	$(LD) -r $(C_OBJS) runtime/asm/rt.o -o runtime/runtime.o
	mv runtime/asm/crti.s.o crti.o
	mv runtime/asm/crtn.s.o crtn.o
	rm -rf runtime/asm/rt.o
	rm -rf $(C_OBJS)

packages: runtime
ifdef pkg
	$(foreach pkg-name, $(pkg), cd pkgs/$(pkg-name) && make GO=$(GO) GCC=$(GCC) AS=$(AS) GOPS="$(GOPS)" COPS="$(GOPS)" AOPS="$(GOPS)" && cd $(LIBMIGO_PATH);)
else
	$(foreach pkg-name, $(PKGS), cd pkgs/$(pkg-name) && make GO=$(GO) GCC=$(GCC) AS=$(AS) GOPS="$(GOPS)" COPS="$(GOPS)" AOPS="$(GOPS)" && cd $(LIBMIGO_PATH);)
endif
	$(LD) -r runtime/runtime.o pkgs/*.o -o runtime.o

migo: 
	cd migokrn && $(MAKE)

# Compile rules
%.c.o: %.c  
	$(GCC) $(COPS) -o $@ -c $< -Iruntime/c
%.s.o: %.s 
	$(AS) $(AOPS) -o $@ -c $<

# Full cleanup
clean:
	rm -rf runtime/*.o runtime/c/*.o runtime/asm/*.o runtime/asm/rt.asm *.o pkgs/*.o include/* migo.krn

# Run qemu (if availible)
qemu:
	qemu-system-i386 -kernel migo.krn
