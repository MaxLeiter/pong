#include <knightos/display.h>
#include <knightos/system.h>
#include <knightos/keys.h>
#include <stdint.h>
#include <stdbool.h>
#include "globals.h"
#include "draw.h"
#include "update.h"

void main_menu() {
	/* Play a simulated game in the background */
	initialize();
	while (1) {
		unsigned char key;

		screen_clear(screen);
		draw_actors();
		draw_string(screen, 28, 0, "-- Pong --");
		draw_string(screen, 8, 10, "Press ENTER to begin");
		screen_draw(screen);
		update_ai(&left_paddle);
		update_ai(&right_paddle);
		update_ball();

		key = get_key();
		if (key == KEY_ENTER) {
			break;
		}
		
		ksleep(5);
	}
}

void main() {
	get_lcd_lock();
	get_keypad_lock();
	screen = screen_allocate();

	main_menu();

	initialize();
	game_running = true;

	while (1) {
		draw();
		update();
	}
}
