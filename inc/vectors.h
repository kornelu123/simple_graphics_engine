#ifndef VECTORS_H_
#define VECTORS_H_
#include <stdint.h>
#include <xcb/xcb.h>
typedef struct {
	int32_t x;
       	int32_t y;
	int32_t z;	
}vector;

xcb_point_t vector_to_polyline(vector vec, uint32_t width, uint32_t height);


#endif
