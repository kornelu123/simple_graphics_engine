#include <stdio.h>
#include <unistd.h>
#include <xcb/xcb.h>
#include <inttypes.h>

int main(){
	xcb_connection_t *con;
	xcb_screen_t	*screen;
	xcb_window_t	win;

	con = xcb_connect(NULL,NULL);
	screen = xcb_setup_roots_iterator(xcb_get_setup(con)).data;

	win = xcb_generate_id(con);
	
	xcb_create_window(con,		/*connection*/
		XCB_COPY_FROM_PARENT,	/*depth (same as root)*/
		win,			/*window id*/
		screen->root,		/*parent window*/
		0, 0,			/* x , y*/
		150,150,		/*width, height*/
		10,			/*border width*/
		XCB_WINDOW_CLASS_INPUT_OUTPUT, /*class*/
		screen->root_visual,	/*visual*/
		0,NULL);		/*masks*/
	
	xcb_map_window(con,win);
	
	xcb_flush(con);

	pause();

	return 0;
}
