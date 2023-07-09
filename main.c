#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <xcb/xcb.h>
#include <inttypes.h>

int main(){
	int i, screenNum;
	xcb_connection_t *conn = xcb_connect(NULL, &screenNum);
	
	const xcb_setup_t *setup = xcb_get_setup(conn);
	xcb_screen_iterator_t iter = xcb_setup_roots_iterator(setup);
	
	for(i = 0; i < screenNum; i++){
		xcb_screen_next(&iter);
	}
	
	xcb_screen_t *screen = iter.data;

	printf("cwel");
	printf("Informations of screen %d:\n", screen->root);

	xcb_disconnect(conn);

	return 0;
}
