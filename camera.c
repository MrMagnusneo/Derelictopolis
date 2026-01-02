#include "camera.h"
#include "window.h"

static Camera2D camera;

void init_camera()
{
    camera.offset = (Vector2){WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2};
    camera.target = (Vector2){0, 0};
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;
}

void camera_move(Vector2 offset)
{
    camera.target.x += offset.x;
    camera.target.y += offset.y;
}

void camera_set_pos(Vector2 pos)
{
    camera.target = pos;
}

void camera_set_rot(float rot)
{
    camera.rotation = rot;
}

void camera_set_zoom(float zoom)
{
    camera.zoom = zoom;
}

Camera2D *get_camera()
{
    return &camera;
}