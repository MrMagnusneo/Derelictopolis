#include <raylib.h>
#include <stdlib.h>

#include "chunk.h"
#include "entity.h"
#include "camera.h"
#include "gui.h"
#include "window.h"

int main()
{
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Derelictopolis");

    init_camera();
    init_chunk_arr();
    init_ent_list();

    Camera2D *cam_ptr = get_camera();

    Chunk *test_chunk = chunk_create((Vector2i){0, 0}, (Vector2i){10, 10});
    test_chunk->tiles[5][5].type = TILETYPE_CONCRETE;

    while (!WindowShouldClose())
    {
        float move_speed = GetFrameTime() * 500;
        Vector2 move = (Vector2){0, 0};

        if (IsKeyDown(KEY_RIGHT)) move.x += move_speed;
        if (IsKeyDown(KEY_LEFT)) move.x -= move_speed;
        if (IsKeyDown(KEY_DOWN)) move.y += move_speed;
        if (IsKeyDown(KEY_UP)) move.y -= move_speed;

        if (IsKeyPressed(KEY_D) && test_chunk->valid)
        {
            chunk_destroy(test_chunk);
        }

        camera_move(move);

        BeginDrawing();
        
        ClearBackground(RAYWHITE);

        BeginMode2D(*cam_ptr);
        //DrawCircle(0, 0, 100.0f, RED);
        if (test_chunk->valid)
        {
            chunk_drawtilesdebug(test_chunk);
            chunk_drawdebug(test_chunk);
        }
        EndMode2D();

        gui_draw_ply_hud(cam_ptr);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}