#include "draw.h"
#include <knightos/display.h>
#include "globals.h"
#include "sprites.h"

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
	unsigned char right = 4;
	if (right_score >= 10) right += 4;
	if (right_score >= 100) right += 4;

	draw_char(screen, 30, 0, left_score);
	draw_char(screen, DISPLAY_WIDTH - 30 - right, 0, right_score);
}

void draw() {
	screen_clear(screen);
	draw_actors();
	draw_score();
	screen_draw(screen);
}
