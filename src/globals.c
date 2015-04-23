#include "globals.h"
#include "sprites.h"
#include <knightos/display.h>
#include <stdint.h>

SCREEN *screen;

uint8_t left_score = 0, right_score = 0;

coordinates_t left_paddle = {
	2,
	64 / 2 - (paddle_left_height / 2)
};

coordinates_t right_paddle = {
	96 - (paddle_right_width + 1),
	64 / 2 - (paddle_right_height / 2)
};

coordinates_t ball = {
	96 / 2 - (ball_width / 2),
	64 / 2 - (ball_height / 2)
};

velocity_t ball_motion = { 1, 1 };
