#include <knightos/system.h>
#include <knightos/display.h>
#include <stdbool.h>
#include "globals.h"
#include "sprites.h"
#include "update.h"
#include "input.h"

void update_ball() {
	ball.x += ball_motion.x;
	ball.y += ball_motion.y;
	if (ball.x >= 96 - ball_width) {
		left_score++;
		ball_motion.x = -ball_motion.x;
	}
	if (ball.x <= 0) {
		right_score++;
		ball_motion.x = -ball_motion.x;
	}
	if (ball.y >= 64 - ball_height || ball.y <= 0) {
		ball_motion.y = -ball_motion.y;
	}
}

bool ai_frame = false;

void update_ai() {
	ai_frame = !ai_frame;
	if (!ai_frame) {
		return;
	}
	/* Note: signed comparison not working? */
	if ((unsigned char)ball_motion.x < 128) {
		if (ball.y > right_paddle.y) {
			right_paddle.y++;
		} else if (ball.y < right_paddle.y) {
			right_paddle.y--;
		}
	} else {
		const int target = DISPLAY_HEIGHT / 2 - paddle_right_height / 2;
		if (right_paddle.y < target) {
			right_paddle.y++;
		}
		if (right_paddle.y > target) {
			right_paddle.y--;
		}
	}
}

void update() {
	do_input();
	update_ball();
	update_ai();
	ksleep(10);
}
