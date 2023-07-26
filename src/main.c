#include <stdio.h>
#include <stdlib.h>
#include <xcb/xcb.h>
#include <unistd.h>
#include <string.h>
#include <xcb/xproto.h>
#include "vectors.h"
#include "animation.h"

int main(){
	window wind;
	init_window(&wind);
  //Map window on the screen 
  	set_floating_window(wind);
  	xcb_map_window(wind.con, wind.win);
  	xcb_flush(wind.con);
  	xcb_generic_event_t *e;
	vector vec = {90,60,30};
	vector vec_pos[2] = {{100,0,500},{-100,-40,800}};
	rectangle new_rect[2] = {create_rect(vec,vec_pos[0]),create_rect(vec,vec_pos[1])};
	xcb_point_t polyline[2][48];
	vector work_vec[2][48];
	uint32_t count = 0;
  	while((e = xcb_wait_for_event(wind.con))){
    		switch (e->response_type & ~0x80){
      		case XCB_EXPOSE:
		for(int k=0;k<3600;k++){
			for(int i=0;i<12;i++){
				for(int j=0; j<4; j++){
					for(int m=0;m<2;m++){
					work_vec[m][4*i + j] = new_rect[m].tri[i].vec[j];
					work_vec[m][4*i + j] = rotate(work_vec[m][4*i +j],k,m+1);
					polyline[m][4*i + j] = vector_to_polyline(work_vec[m][4*i + j],wind.height,wind.width,vec_pos[m]);
					}
				}	
			}
			xcb_poly_line(wind.con, XCB_COORD_MODE_ORIGIN,wind.win ,wind.b_foreground, 48, polyline[0]);
			
			xcb_poly_line(wind.con, XCB_COORD_MODE_ORIGIN,wind.win ,wind.b_foreground, 48, polyline[1]);
			xcb_flush(wind.con);
			usleep(400);
			clean_win(&wind);
			}
   			break;
      		default:
			break;
  	} 
  	free(e);
	}
  	sleep(3);
	return 0;
}
