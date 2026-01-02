#pragma once

#include "window.h"
#include <raylib.h>

#define GUIELEMENTS_MAX 128

typedef struct GUI_TextInputField
{
    unsigned char *text;
} GUI_TextInputField;

union GUIElement
{
    GUI_TextInputField *textinput;
};

int get_gui_scale();
int gui_scale(int value);
void gui_draw_ply_hud(Camera2D *cam_ptr);
