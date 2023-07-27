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
	vector vec = {50,50,50};
	vector vec_pos = {0,0,500};
	uint32_t count = 0;
	rectangle new_rect = create_rect(vec,vec_pos);
  	while((e = xcb_wait_for_event(wind.con))){
		switch(e->response_type & ~0x80){
      		case XCB_EXPOSE:
			draw_cuboid(rot_rect(new_rect,ROT_Y ,count), wind.con, wind.win, wind.b_foreground, vec_pos,wind.width, wind.height);		
			usleep(5000);
			clean_win(&wind);
			count++;
   			break;
      		default:
			break;
  	} 
  	free(e);
	}
  	sleep(3);
	return 0;
}
