#include <knightos/system.h>
#include "globals.h"
#include "sprites.h"
#include "update.h"
#include "input.h"

void update() {
	do_input();
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
	ksleep(10);
}
