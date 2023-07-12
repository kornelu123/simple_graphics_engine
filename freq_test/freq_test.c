#include <stdio.h>
#include <stdlib.h>
#include <xcb/xcb.h>
#include <unistd.h>
#include <string.h>
#include <xcb/xproto.h>

void set_floating_atoms(xcb_connection_t *con, xcb_drawable_t win ){
	xcb_intern_atom_cookie_t cookie, cookie1;
	xcb_intern_atom_reply_t *reply, *reply1;
	
	cookie = xcb_intern_atom(con, 1, strlen("_NET_WM_WINDOW_TYPE"), "_NET_WM_WINDOW_TYPE");
	reply = xcb_intern_atom_reply(con, cookie, 0);
	
	cookie1 = xcb_intern_atom(con, 0, strlen("_NET_WM_WINDOW_TYPE_SPLASH"),"_NET_WM_WINDOW_TYPE_SPLASH");
	reply1 = xcb_intern_atom_reply(con, cookie1, 0);

	xcb_change_property(con, XCB_PROP_MODE_REPLACE, win, reply->atom, 4 , 32 , 1, &reply1->atom);
}

void go_right(xcb_point_t polyline[]){
	polyline[0].x++;
}

void go_left(xcb_point_t polyline[]){
	polyline[0].x--;
}

int handle_move(xcb_point_t polyline[],int count){
	if(count < 150){
		polyline[0].x = count;
	}
	if(count > 150){
		polyline[0].x = 300-count;	
	}
	if(count == 300){
		count = 0;	
	}
	count++;
	return count;
}

void clean_win(xcb_connection_t *con, xcb_drawable_t win){
	xcb_clear_area(con, 1, win, 0, 0, 200, 200);
	xcb_flush(con);
}

int main(){
	xcb_connection_t    *con;
	xcb_screen_t	      *screen;
	xcb_drawable_t      win;
  xcb_gcontext_t      b_foreground; 
  xcb_gcontext_t      w_foreground;
  uint32_t            mask = 0;
  uint32_t            values[2];

  xcb_point_t polyline[] = {
{0,75},
{50,0},
{0,50},
{-50,0}, 
{0,-50}};

xcb_rectangle_t rectangles[] = {
	{0,0,200,200}, //x,y,width,height
};

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
	
  w_foreground = xcb_generate_id(con);
  mask = XCB_GC_FOREGROUND | XCB_GC_GRAPHICS_EXPOSURES;
  values[0] = screen->white_pixel;
  values[1] = 0;
  xcb_create_gc(con, w_foreground, win, mask, values);

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
		    200,200, 
                    10, 
                    XCB_WINDOW_CLASS_INPUT_OUTPUT, 
                    screen->root_visual, 
                    mask , values);
  
  //Map window on the screen 
  set_floating_atoms(con,win);
  xcb_map_window(con, win);
  xcb_flush(con);
  xcb_generic_event_t *e;
  while(1){
	xcb_poly_fill_rectangle(con, win,b_foreground,1,rectangles);
	xcb_flush(con);
	usleep(20000);
   	clean_win(con,win);	
	xcb_flush(con);
	usleep(20000);
  }
  xcb_flush(con); 
  sleep(3);
return 0;
}
