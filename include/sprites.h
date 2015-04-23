#ifndef __PONG_SPRITES_H
#define __PONG_SPRITES_H

/* These are defined in object files that are created on the fly from the
 * contents of the img directory. */

extern const void *ball_sprite_start;
#define ball_sprite ball_sprite_start
#define ball_width 5
#define ball_height 5

extern const void *paddle_left_sprite_start;
#define paddle_left_sprite paddle_left_sprite_start
#define paddle_left_width 3
#define paddle_left_height 8

extern const void *paddle_right_sprite_start;
#define paddle_right_sprite paddle_right_sprite_start
#define paddle_right_width 3
#define paddle_right_height 8

#endif
