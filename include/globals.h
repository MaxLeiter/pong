#ifndef __PONG_GLOBALS_H
#define __PONG_GLOBALS_H

#include <knightos/display.h>
#include <stdint.h>
#include <stdbool.h>

typedef struct {
	uint8_t x, y;
} coordinates_t;

typedef struct {
	int8_t x, y;
} velocity_t;

extern SCREEN *screen;

extern uint8_t left_score, right_score;

extern coordinates_t left_paddle;
extern coordinates_t right_paddle;
extern coordinates_t ball;

extern velocity_t ball_motion;

extern bool game_running;

void initialize();

#endif
