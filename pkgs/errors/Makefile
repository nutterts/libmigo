all:
	$(GO) $(GOPS) -o ../errors.o -c errors.go
	$(ARMGNU)-objcopy -j .go_export ../errors.o ../../include/errors.gox