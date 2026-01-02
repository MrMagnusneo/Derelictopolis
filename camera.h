#pragma once

#include <raylib.h>

void init_camera();

void camera_set_pos(Vector2 pos);
void camera_move(Vector2 offset);
void camera_set_rot(float rot);
void camera_set_zoom(float zoom);

Camera2D *get_camera();