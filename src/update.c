#include <knightos/system.h>
#include <knightos/display.h>
#include <stdbool.h>
#include "globals.h"
#include "draw.h"
#include "sprites.h"
#include "update.h"
#include "input.h"

void score(bool player) {
	if (player) {
		left_score++;
	} else {
		right_score++;
	}

	ball_motion.x = -ball_motion.x;

	if (ball_motion.y > 1) {
		ball_motion.y = 1;
	} else if (ball_motion.y < -1) {
		ball_motion.y = -1;
	}

	ball.x = DISPLAY_WIDTH / 2 - (ball_width / 2);
	ball.y = DISPLAY_HEIGHT / 2 - (ball_height / 2);

	if (game_running) {
		screen_clear(screen);
		draw_actors();
		draw_score();
		draw_string(screen, 40, 10, "SCORE");
		screen_draw(screen);
		ksleep(1000);
	}
}

void randomize_ball() {
	unsigned char random;
	if (!game_running) {
		/* Don't want to spoil the surprise during the menu screen */
		return;
	}
	random = get_random() % 2 + 1;
	if (ball_motion.y < 0) {
		random = -random;
	}
	ball_motion.y = random;
}

void update_ball() {
	ball.x += ball_motion.x;
	ball.y += ball_motion.y;
	/* Test paddles */
	if (ball_motion.x < 0
			&& ball.x <= (uint8_t)(left_paddle.x + paddle_left_width)
			&& (uint8_t)(ball.y + ball_height) >= left_paddle.y
			&& ball.y <= (uint8_t)(left_paddle.y + paddle_left_height)) {
		ball_motion.x = -ball_motion.x;
		randomize_ball();
		return;
	}
	if (ball_motion.x > 0
			&& (uint8_t)(ball.x + ball_width) >= right_paddle.x
			&& (uint8_t)(ball.y + ball_height) >= right_paddle.y
			&& ball.y <= (uint8_t)(right_paddle.y + paddle_right_height)) {
		ball_motion.x = -ball_motion.x;
		randomize_ball();
		return;
	}
	/* Test walls */
	if (ball.x >= DISPLAY_WIDTH - ball_width) {
		score(true);
	}
	if (ball.x <= 0) {
		score(false);
	}
	if (ball_motion.y > 0 && ball.y >= DISPLAY_HEIGHT - ball_height) {
		ball_motion.y = -ball_motion.y;
	}
	if (ball_motion.y < 0 && (ball.y == 0 || ball.y > 128)) {
		ball_motion.y = -ball_motion.y;
	}
}

bool ai_frame = false;

void update_ai(coordinates_t *paddle) {
	/* Note: signed comparison not working? */
	bool coming_this_way = (unsigned char)ball_motion.x < 128;
	if (paddle->x < 32) {
		coming_this_way = !coming_this_way;
	}
	if (coming_this_way) {
		if (ball.y > (uint8_t)(paddle->y + (paddle_right_height / 2))
			&& (uint8_t)(paddle->y + paddle_right_height) < DISPLAY_HEIGHT) {
			paddle->y++;
		} else if (ball.y < (uint8_t)(paddle->y + (paddle_right_height / 2))
			&& paddle->y > 0) {
			paddle->y--;
		}
	} else {
		const int target = DISPLAY_HEIGHT / 2 - paddle_right_height / 2;
		if (paddle->y < target) {
			paddle->y++;
		}
		if (paddle->y > target) {
			paddle->y--;
		}
	}
}

void update() {
	do_input();
	ai_frame = !ai_frame;
	if (ai_frame) {
		update_ball();
		update_ai(&right_paddle);
	}
	ksleep(5);
}
