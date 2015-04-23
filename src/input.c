#include <knightos/display.h>
#include <knightos/keys.h>
#include <stdlib.h>
#include "globals.h"
#include "sprites.h"
#include "input.h"

void do_input() {
	unsigned char key = get_key();
	switch (key) {
	case KEY_UP:
		if (left_paddle.y > 0) {
			left_paddle.y--;
		}
		break;
	case KEY_DOWN:
		if (left_paddle.y < DISPLAY_HEIGHT - paddle_left_height) {
			left_paddle.y++;
		}
		break;
	case KEY_MODE:
		exit(0);
		break;
	}
}

