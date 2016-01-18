all:
	$(GO) $(GOPS) -o ../../runtime_textmode.o -c scrn.go -fgo-pkgpath=runtime/textmode
	mkdir -p ../../../include/runtime
	$(ARMGNU)-objcopy -j .go_export ../../runtime_textmode.o ../../../include/runtime/textmode.gox