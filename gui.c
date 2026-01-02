#include "gui.h"
#include "window.h"

int get_gui_scale()
{
    return WINDOW_HEIGHT / 32;
}

int gui_scale(int value)
{
    return value * get_gui_scale();
}

void gui_draw_ply_hud(Camera2D *cam_ptr)
{
    DrawText(TextFormat("Camera position: %f  %f", cam_ptr->target.x, cam_ptr->target.y), 0, 0, get_gui_scale(), BLACK);
}