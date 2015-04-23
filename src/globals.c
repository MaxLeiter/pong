#include "globals.h"
#include "sprites.h"
#include <knightos/display.h>
#include <stdint.h>
#include <stdbool.h>

SCREEN *screen;

uint8_t left_score, right_score;

coordinates_t left_paddle, right_paddle, ball;

velocity_t ball_motion;

bool game_running;

void initialize() {
	left_paddle.x = 2;
	left_paddle.y = 64 / 2 - (paddle_left_height / 2);

	right_paddle.x = 96 - (paddle_right_width + 1);
	right_paddle.y = 64 / 2 - (paddle_right_height / 2);

	ball.x = 96 / 2 - (ball_width / 2);
	ball.y = 64 / 2 - (ball_height / 2);

	ball_motion.x = 1;
	ball_motion.y = 1;

	left_score = 0;
	right_score = 0;

	game_running = false;
}
