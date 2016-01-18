all:
	$(GO) $(GOPS) -o ../unicode.o -c casetables.go digit.go graphic.go letter.go tables.go
	$(ARMGNU)-objcopy -j .go_export ../unicode.o ../../include/unicode.gox