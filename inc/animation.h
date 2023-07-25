#ifndef ANIMATION_H_
#define ANIMATION_H_
#include <xcb/xcb.h>
#include <xcb/xproto.h>
#include "vectors.h"

typedef struct {
	uint32_t 		width;
	uint32_t 		height;
	xcb_connection_t	*con;
	xcb_screen_t		*screen;
	xcb_drawable_t      	win;
	xcb_gcontext_t     	b_foreground; 
 	uint32_t           	mask; 
  	uint32_t           	values[2];
}window;

void clean_win(window* wind);

void set_floating_window(window wind);

void init_window(window* wind);
#endif
