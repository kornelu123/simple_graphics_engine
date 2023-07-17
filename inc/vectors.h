#ifndef VECTORS_H_
#define VECTORS_H_
#include <stdint.h>
#include <xcb/xcb.h>
typedef struct {
	int32_t x;
       	int32_t y;
	int32_t z;	
}vector;

typedef struct {
	vector vec[16];
}cube;

xcb_point_t vector_to_polyline(vector vec, uint32_t width, uint32_t height);

vector rotate_x(int deg, vector vec);

vector rotate_y(int deg, vector vec);

vector rotate_z(int deg, vector vec);

cube create_cube(vector vec);

#endif
