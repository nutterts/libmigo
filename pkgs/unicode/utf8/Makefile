all:
	$(GO) $(GOPS) -o ../../unicode_utf8.o -c utf8.go -fgo-pkgpath=unicode/utf8
	mkdir -p ../../../include/unicode
	$(ARMGNU)-objcopy -j .go_export ../../unicode_utf8.o ../../../include/unicode/utf8.gox