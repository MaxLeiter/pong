#include <knightos/display.h>
#include <knightos/system.h>
#include <stdint.h>
#include "sprites.h"
#include "main.h"

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

void draw_actors() {
	draw_sprite(screen,
		left_paddle.x, left_paddle.y,
		paddle_left_height, &paddle_left_sprite);

	draw_sprite(screen, right_paddle.x, right_paddle.y,
		paddle_right_height, &paddle_right_sprite);

	draw_sprite(screen, ball.x, ball.y,
		ball_height, &ball_sprite);
}

void draw_score() {
	draw_char(screen, 1, 0, left_score);
	draw_char(screen, 96 - (4 * 3), 0, right_score);
}

void draw() {
	screen_clear(screen);
	draw_actors();
	draw_score();
	screen_draw(screen);
}

void do_input() {
	// TODO
}

void update() {
	volatile unsigned char _;
	do_input();
	ball.x += ball_motion.x;
	ball.y += ball_motion.y;
	if (ball.x >= 96 || ball.x <= 0) {
		if (ball.x >= 96) {
			left_score++;
		} else {
			right_score++;
		}
		ball_motion.x = -ball_motion.x;
	}
	if (ball.y >= 64 || ball.y <= 0) {
		ball_motion.y = -ball_motion.y;
	}
	// Waste cycles TODO: do this better
	for (_ = 0; _ < 255; ++_);
	for (_ = 0; _ < 255; ++_);
	for (_ = 0; _ < 255; ++_);
}

void main() {
	get_lcd_lock();
	get_keypad_lock();
	screen = screen_allocate();
	while (1) {
		draw();
		update();
	}
}
