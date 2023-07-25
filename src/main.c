#include <stdio.h>
#include <stdlib.h>
#include <xcb/xcb.h>
#include <unistd.h>
#include <string.h>
#include <xcb/xproto.h>
#include "vectors.h"
#include "animation.h"

int main(){

	printf("%d %d %d",ROT_X, ROT_Y, ROT_Z);
	window wind;
	init_window(&wind);
  //Map window on the screen 
  	set_floating_window(wind);
  	xcb_map_window(wind.con, wind.win);
  	xcb_flush(wind.con);
  	xcb_generic_event_t *e;
	vector vec = {90,60,30};
	vector vec_pos = {0,0,0};
	rectangle new_rect = create_rect(vec,vec_pos);
	xcb_point_t polyline[48];
	vector work_vec[48];
	uint32_t count = 0;
  	while((e = xcb_wait_for_event(wind.con))){
    		switch (e->response_type & ~0x80){
      		case XCB_EXPOSE:
		for(int k=0;k<3600;k++){
			for(int i=0;i<12;i++){
				for(int j=0; j<4; j++){
					work_vec[4*i + j] = new_rect.tri[i].vec[j];
					work_vec[4*i + j] = rotate(work_vec[4*i +j],k,ROT_Z );
					polyline[4*i + j] = vector_to_polyline(work_vec[4*i + j], wind.width, wind.height);
				}	
			}
			xcb_poly_line(wind.con, XCB_COORD_MODE_ORIGIN,wind.win ,wind.b_foreground, 48, polyline);
			xcb_flush(wind.con);
			usleep(10000);
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
