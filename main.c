#include <stdio.h>
#include <stdlib.h>
#include <xcb/xcb.h>
#include <unistd.h>

int main(){
	xcb_connection_t    *con;
	xcb_screen_t	      *screen;
	xcb_drawable_t      win;
  xcb_gcontext_t      b_foreground;
  xcb_gcontext_t      w_foreground;
  uint32_t            mask = 0;
  uint32_t            values[2];

 
  xcb_point_t polyline[1];

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
	

  //create white foreground graphic context
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
                    1920,1200, 
                    10, 
                    XCB_WINDOW_CLASS_INPUT_OUTPUT, 
                    screen->root_visual, 
                    mask , values);
  
  //Map window on the screen 
  xcb_map_window(con, win);
  for(int i=0;i<1200;i++){
    polyline[0].y  = i;
    for(int j=0;j<1920;j+=2){
      polyline[0].x = j;
      xcb_poly_point(con,XCB_COORD_MODE_ORIGIN,win,b_foreground,1,polyline);
      xcb_flush(con);
    }
  }
  //Flush the request
  xcb_flush(con);
  return 0;
}
