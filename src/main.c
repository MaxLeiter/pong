#include <knightos/display.h>
#include <knightos/system.h>
#include <stdint.h>
#include "globals.h"
#include "draw.h"
#include "update.h"

void main() {
	get_lcd_lock();
	get_keypad_lock();
	screen = screen_allocate();
	while (1) {
		draw();
		update();
	}
}
