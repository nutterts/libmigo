# Declare constants used for creating a multiboot header.
.set ALIGN,    1<<0             # align loaded modules on page boundaries
.set MEMINFO,  1<<1             # provide memory map
.set FLAGS,    ALIGN | MEMINFO  # this is the Multiboot 'flag' field
.set MAGIC,    0x1BADB002       # 'magic number' lets bootloader find the header
.set CHECKSUM, -(MAGIC + FLAGS) # checksum of above, to prove we are multiboot

# Declare a header as in the Multiboot Standard.
.section .multiboot
.align 4
.long MAGIC
.long FLAGS
.long CHECKSUM

# Declare an initial stack
.section .bootstrap_stack, "aw", @nobits
bootstrap_stack_bottom:
.skip 16384 # Subsituted with real value by Makefile
bootstrap_stack_top:

# Entry point
.section .text
.global _start
.type _start, @function
_start:
	mov $bootstrap_stack_top, %esp
	fninit 		# initialize FPU
	call _init 	# C initialization
	call main	# Call main()
	call _fini  # C finalization
	jmp abort
.size _start, . - _start

# Provide memory access in Go
.section .text
.global itop
.type itop, @function
itop:
	push %ebp
	mov %esp, %ebp
	mov 8(%ebp), %eax
	mov %ebp, %esp
	pop %ebp
	ret
.size itop, . - itop

# Abort execution - abort()
.section .text
.global abort
.type abort, @function
abort:
	cli
.reabort:
	hlt
	jmp .reabort
.size abort, . - abort

# Declare a memory area for the runtime allocator
.section .runtime_memory, "aw", @nobits

.global runtime_sbrk_size
runtime_sbrk_size:
.long 8388608  # Subsituted with real value by Makefile

.global runtime_sbrk_top
runtime_sbrk_top:

.skip 8388608  # Subsituted with real value by Makefile

.global runtime_sbrk_bottom
runtime_sbrk_bottom:
