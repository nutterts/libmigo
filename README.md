# libmigo - A libgo replacement for Go programs compiled with gccgo 5.3

Work in process and lots of language features like go routines or a working garbage collector are not yet implemented. But feel free to play around with it just don't complain if it blows up in your face or steals your lunch.

To use it you'll need a working gccgo cross compiler for the i686-elf target. I recommend a (virtual) machine with Ubuntu Mate for compiling the runtime and packages as thats what I'm using myself.

In the main directory type: make

This will compile everything into "runtime.o" and create a multiboot compatible testing kernel named "migo.krn". You can run the testing kernel with qemu by typing: qemu-system-i386 -kernel migo.krn

Alternativly you can select which packages should be compiled to reduce the resulting program size. If for example you want to compile in the packages errors & unicode/utf8 you'd type: make pkg="errors unicode/utf8"

By default it'll use a 32KiB stack and a 8MiB heap. You can change this by adding a "heap" and/or "stack" option to make. The heap size is specified in MiB and the stack size in KiB. If you'd want a 128MiB heap and a 64KiB stack and only want to compile in the errors package you'd type: make heap=128 stack=64 pkg=errors

If you only want to recompile the testing kernel (migo.krn) without recompiling the entire runtime you'd type: make migo

In the folder "migokrn" you'll find the source and Makefile for the testing kernel (migo.krn) which will show you how to use this runtime.

Enjoy and stay tuned!
