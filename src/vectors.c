#include "vectors.h"
#include <xcb/xcb.h>

xcb_point_t vector_to_polyline(vector vec, uint32_t width, uint32_t height){
	xcb_point_t point = { width/2 + ((100*vec.x )/ vec.z), height/2 + ((100*vec.y) / vec.z)};
	return point; 
}	
