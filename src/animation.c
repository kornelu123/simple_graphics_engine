#include "animation.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <xcb/xcb.h>
#include <xcb/xproto.h>
#include "vectors.h"

void clean_win(window *wind){
	xcb_clear_area(wind->con, 1, wind->win, 0, 0, wind->width,wind->height);
	xcb_flush(wind->con);
}


void set_floating_window(window wind){
	xcb_intern_atom_cookie_t cookie, cookie1;
	xcb_intern_atom_reply_t *reply, *reply1;
	
	cookie = xcb_intern_atom(wind.con, 1, strlen("_NET_WM_WINDOW_TYPE"), "_NET_WM_WINDOW_TYPE");
	reply = xcb_intern_atom_reply(wind.con, cookie, 0);
	
	cookie1 = xcb_intern_atom(wind.con, 0, strlen("_NET_WM_WINDOW_TYPE_SPLASH"),"_NET_WM_WINDOW_TYPE_SPLASH");
	reply1 = xcb_intern_atom_reply(wind.con, cookie1, 0);

	xcb_change_property(wind.con, XCB_PROP_MODE_REPLACE, wind.win, reply->atom, 4 , 32 , 1, &reply1->atom);
}

void init_window(window *wind){
	wind->width = 1024;
	wind->height = 1024;
	wind->con = xcb_connect(NULL,NULL);
	
  //Get the first screen
  	wind->screen = xcb_setup_roots_iterator(xcb_get_setup(wind->con)).data;
	wind->win = wind->screen->root;
  
  	wind->b_foreground = xcb_generate_id(wind->con);
  	wind->mask = XCB_GC_FOREGROUND | XCB_GC_GRAPHICS_EXPOSURES;
  	wind->values[0] =wind->screen->black_pixel;
  	wind->values[1] = 0;
  	xcb_create_gc(wind->con, wind->b_foreground, wind->win, wind->mask, wind->values);
  //Ask for window's id 
 	 wind->win = xcb_generate_id(wind->con);
  
  //Create a window
  	wind->mask = XCB_CW_BACK_PIXEL | XCB_CW_EVENT_MASK;
 	wind->values[0] = wind->screen->white_pixel;
  	wind->values[1] = XCB_EVENT_MASK_EXPOSURE;
 	xcb_create_window(wind->con ,
                    XCB_COPY_FROM_PARENT , 
                    wind->win , 
                    wind->screen->root , 
                    0, 0, 
		    wind->width,wind->height, 
                    10, 
                    XCB_WINDOW_CLASS_INPUT_OUTPUT, 
                    wind->screen->root_visual, 
                    wind->mask , wind->values);

}
