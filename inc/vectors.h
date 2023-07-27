#ifndef VECTORS_H_
#define VECTORS_H_
#include <stdint.h>
#include <xcb/xcb.h>
#include "animation.h"

#define SCALE_RATIO 500
#define ROT_X 1
#define ROT_Y 2
#define ROT_Z 4

typedef struct {
	int32_t x;
       	int32_t y;
	int32_t z;	
}vector;

typedef struct{
	vector vec[4];
}triangle;

typedef struct {
	triangle tri[12];
	vector   pos;
}rectangle;

rectangle rot_rect(rectangle rect, uint8_t rot_dir, uint32_t deg);

vector rotate(vector vec, uint32_t deg, uint8_t rot_dir);

xcb_point_t vector_to_polyline(vector vec,uint32_t height, uint32_t width, vector offset);

void draw_cuboid(rectangle rect, xcb_connection_t *con, xcb_drawable_t win, xcb_gcontext_t b_foreground, vector vec_pos, uint32_t width, uint32_t height);

void draw_triangle(triangle tri, xcb_connection_t *con, xcb_drawable_t win, xcb_gcontext_t b_foreground,vector vec_pos,uint32_t height, uint32_t width);

vector rotate_x(int deg, vector vec,double rad);

vector rotate_y(int deg, vector vec,double rad);

vector rotate_z(int deg, vector vec,double rad);

rectangle create_rect(vector gen, vector pos);

#endif
