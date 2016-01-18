package textmode

/* scrn.c */

func _cls () __asm__("cls")
func _putch (rune) __asm__("putch")
//func _settextcolor (uint8, uint8) __asm__("settextcolor")

/* Exported functions */

func PrintRune(c rune) {
	_putch(c)
}

func Print(s string) {
	for _, c := range s {
    	_putch(c)
    }
}

func Println(s string) {
	for _, c := range s {
    	_putch(c)
    }
	_putch(10)	
}

func Clear() {
	_cls()
}

