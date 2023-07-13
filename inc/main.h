#include "vectors.h"

void set_floating_window(xcb_connection *con, xcb_drawable_t win);
int handle_move(xcb_point_t polyline[],uint32_t count,uint32_t width);
void clean_win(xcb_connection_t *con, xcb_drawable_t win,uint32_t width, uint32_t height);
