all:
	$(GO) $(GOPS) -o ../../unicode_utf16.o -c utf16.go -fgo-pkgpath=unicode/utf16
	mkdir -p ../../../include/unicode
	$(ARMGNU)-objcopy -j .go_export ../../unicode_utf16.o ../../../include/unicode/utf16.gox