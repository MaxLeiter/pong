#include <knightos/display.h>
#include <knightos/system.h>
#include <knightos/keys.h>
#include <corelib.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include "globals.h"
#include "draw.h"
#include "update.h"

void draw_highscores() {
	int i;
	set_left_margin(28);
	draw_string(screen, 28, 30, "High Scores");
	for (i = 36; i < 36 + (3 * 6); i += 6) {
		draw_string(screen, 28, i, "TODO......0");
	}
}

void main_menu() {
	/* Play a simulated game in the background */
	unsigned char _;
	initialize();
	while (1) {
		unsigned char key;

		screen_clear(screen);
		draw_actors();
		draw_string(screen, 28, 0, "-- Pong --");
		draw_string(screen, 8, 10, "Press ENTER to begin");
		draw_highscores();
		screen_draw(screen);
		update_ai(&left_paddle);
		update_ai(&right_paddle);
		update_ball();

		key = app_get_key(&_);
		switch (key) {
		case KEY_ENTER:
			return;
		case KEY_MODE:
			exit(0);
			break;
		}
		
		ksleep(5);
	}
}

void main() {
	load_library("/lib/core");
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
