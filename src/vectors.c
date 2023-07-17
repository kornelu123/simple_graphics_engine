#include "vectors.h"
#include <xcb/xcb.h>
#include <math.h>

#define SCALE_RATIO 500

xcb_point_t vector_to_polyline(vector vec, uint32_t width, uint32_t height){
	xcb_point_t point = { width/2 + (SCALE_RATIO* vec.x)/(SCALE_RATIO +  vec.z), height/2 + (SCALE_RATIO * vec.y)/(SCALE_RATIO +  vec.z)};
	return point; 
}	

cube create_cube(vector vec){
	cube new_cube ;
        vector vec_n[17];
	vec_n[0].x = -vec.x ;
        vec_n[0].y = -vec.y;
        vec_n[0].z = -vec.z;
	vec_n[1].x = -vec.x;
	vec_n[1].y = vec.y;
	vec_n[1].z = -vec.z;
	vec_n[2].x = -vec.x;
        vec_n[2].y = vec.y;
        vec_n[2].z = vec.z;
	vec_n[3].x = -vec.x;
	vec_n[3].y = -vec.y;
	vec_n[3].z = vec.z;
	vec_n[4].x = -vec.x;
	vec_n[4].y = -vec.y;
	vec_n[4].z = -vec.z;
	vec_n[5].x = vec.x;
	vec_n[5].y = -vec.y;
	vec_n[5].z = -vec.z;
	vec_n[6].x = vec.x;
	vec_n[6].y = vec.y;
	vec_n[6].z = -vec.z;
	vec_n[7].x = -vec.x;
	vec_n[7].y = vec.y;
	vec_n[7].z = -vec.z; 
	vec_n[8].x = -vec.x;
	vec_n[8].y = vec.y;
	vec_n[8].z = vec.z;
	vec_n[9].x = vec.x;
	vec_n[9].y = vec.y;
	vec_n[9].z = vec.z;
	vec_n[10].x = vec.x;
	vec_n[10].y = vec.y;
	vec_n[10].z = -vec.z;
	vec_n[11].x = vec.x;
	vec_n[11].y = -vec.y;
	vec_n[11].z = -vec.z;
	vec_n[12].x = vec.x;
	vec_n[12].y = -vec.y;
	vec_n[12].z = vec.z;
	vec_n[13].x = vec.x;
	vec_n[13].y = vec.y;
	vec_n[13].z = vec.z;
	vec_n[14].x = vec.x;
	vec_n[14].y = -vec.y;
	vec_n[14].z = vec.z;
	vec_n[15].x = -vec.x;
	vec_n[15].y = -vec.y;
	vec_n[15].z = vec.z;
	for(int i=0;i<15;i++){
		new_cube.vec[i] = vec_n[i];
	}
	return new_cube;
}

vector rotate_x(int deg, vector vec){
	double rad = (deg/1800.0)*M_PI;
	vector new_vec ;
	double cos_t = cos(rad);
	double sin_t = sin(rad);
	double new_y = cos_t*vec.y - sin_t*vec.z; 
	double new_z = sin_t*vec.y + cos_t*vec.z;
	new_vec.x = vec.x;
	new_vec.y = (int) new_y;
	new_vec.z = (int) new_z;
	return new_vec;	
}

vector rotate_y(int deg, vector vec){
	double rad = (deg/1800.0)*M_PI;
	vector new_vec ;
	double cos_t = cos(rad);
	double sin_t = sin(rad);
	double new_x = cos_t*vec.x + sin_t*vec.z; 
	double new_z = cos_t*vec.z - sin_t*vec.x;
	new_vec.x = (int) new_x;
	new_vec.y = vec.y;
	new_vec.z = (int) new_z;
	return new_vec;
}

vector rotate_z(int deg, vector vec){
	double rad = (deg/1800.0)*M_PI;
	vector new_vec ;
	double cos_t = cos(rad);
	double sin_t = sin(rad);
	double new_x = cos_t*vec.x - sin_t*vec.y; 
	double new_y = sin_t*vec.x + sin_t*vec.y;
	new_vec.x = (int) new_x;
	new_vec.y = (int) new_y;
	new_vec.z = vec.z;
}
