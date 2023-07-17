#include <stdio.h>
#include <stdlib.h>
#include <xcb/xcb.h>
#include <unistd.h>
#include <string.h>
#include <xcb/xproto.h>
#include "vectors.h"


void set_floating_window(xcb_connection_t *con, xcb_drawable_t win ){
	xcb_intern_atom_cookie_t cookie, cookie1;
	xcb_intern_atom_reply_t *reply, *reply1;
	
	cookie = xcb_intern_atom(con, 1, strlen("_NET_WM_WINDOW_TYPE"), "_NET_WM_WINDOW_TYPE");
	reply = xcb_intern_atom_reply(con, cookie, 0);
	
	cookie1 = xcb_intern_atom(con, 0, strlen("_NET_WM_WINDOW_TYPE_SPLASH"),"_NET_WM_WINDOW_TYPE_SPLASH");
	reply1 = xcb_intern_atom_reply(con, cookie1, 0);

	xcb_change_property(con, XCB_PROP_MODE_REPLACE, win, reply->atom, 4 , 32 , 1, &reply1->atom);
}

int handle_move(xcb_point_t polyline[],uint32_t count,uint32_t width){
	if(count < width/3*2){
		polyline[0].x = count;
	}
	if(count > width/3*2){
		polyline[0].x = (width/3*4)-count;	
	}
	if(count == width/3*4){
		count = 0;	
	}
	count++;
	return count;
}

void clean_win(xcb_connection_t *con, xcb_drawable_t win,uint32_t width, uint32_t height){
	xcb_clear_area(con, 1, win, 0, 0, width,height);
	xcb_flush(con);
}

void move_further(vector* vec){
	for(int i=0;i<5;i++){
		vec[i].z ++;
	}
}

int main(){
	uint32_t		width = 1024;
	uint32_t		height = 1024;	
	xcb_connection_t	*con;
	xcb_screen_t		*screen;
	xcb_drawable_t      	win;
	xcb_gcontext_t     	b_foreground; 
 	uint32_t           	mask = 0;
  	uint32_t           	values[2];


  //opening connection to X server
	con = xcb_connect(NULL,NULL);
	
  //Get the first screen
  	screen = xcb_setup_roots_iterator(xcb_get_setup(con)).data;
  
  //create black foregorund graphic context 
	win = screen->root;
  
  	b_foreground = xcb_generate_id(con);
  	mask = XCB_GC_FOREGROUND | XCB_GC_GRAPHICS_EXPOSURES;
  	values[0] = screen->black_pixel;
  	values[1] = 0;
  	xcb_create_gc(con, b_foreground, win, mask, values);

  //Ask for window's id 
 	 win = xcb_generate_id(con);
  
  //Create a window
  	mask = XCB_CW_BACK_PIXEL | XCB_CW_EVENT_MASK;
 	values[0] = screen->white_pixel;
  	values[1] = XCB_EVENT_MASK_EXPOSURE;
 	xcb_create_window(con ,
                    XCB_COPY_FROM_PARENT , 
                    win , 
                    screen->root , 
                    0, 0, 
		    width,height, 
                    10, 
                    XCB_WINDOW_CLASS_INPUT_OUTPUT, 
                    screen->root_visual, 
                    mask , values);
  
  //Map window on the screen 
  	set_floating_window(con,win);
  	xcb_map_window(con, win);
  	xcb_flush(con);
  	xcb_generic_event_t *e;
	vector vec = {90,90,90};
	cube new_cube = create_cube(vec);
	xcb_point_t polyline[17];
	vector work_vec[17];
	uint32_t count = 0;
  	while((e = xcb_wait_for_event(con))){
    		switch (e->response_type & ~0x80){
      		case XCB_EXPOSE:
			for(int j=0;j<3600;j++){
			for(int i=0;i<16;i++){
				work_vec[i] = rotate_y(j,new_cube.vec[i]);
				polyline[i] = vector_to_polyline(work_vec[i], width, height);
			}
			xcb_poly_line(con, XCB_COORD_MODE_ORIGIN,win ,b_foreground, 16, polyline);
			xcb_flush(con);
			sleep(30);
			usleep(5000);
			clean_win(con,win,width,height);
			}
   			break;
      		default:
			break;
  	} 
  	free(e);
	}
  	xcb_flush(con); 
  	sleep(3);
	return 0;
}
