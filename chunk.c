#include "chunk.h"
#include "gui.h"
#include <raylib.h>
#include <stdlib.h>

static Chunk chunk_arr[CHUNKS_MAX];
static chunk_id_t chunk_next_id = 0;

void init_chunk_arr()
{
    for (unsigned i = 0; i < CHUNKS_MAX; i++)
    {
        chunk_arr[i] = (Chunk){false};
    }
}

Chunk *chunk_create(Vector2i pos, Vector2i size)
{
    Chunk *new_chunk = &chunk_arr[chunk_next_id];

    *new_chunk = (Chunk){
        .valid = true,
        .id = chunk_next_id,
        .pos = pos,
        .size = size,
        .tiles = malloc(sizeof(Tile*) * size.y)
    };
    
    for (unsigned i = 0; i < size.y; i++)
    {
        new_chunk->tiles[i] = malloc(sizeof(Tile) * size.x);
        
        for (unsigned j = 0; j < size.x; j++)
            new_chunk->tiles[i][j] = (Tile){TILETYPE_AIR, 0};
    }
    
    do
    {
        chunk_next_id++;
    }
    while (chunk_arr[chunk_next_id].valid);

    return new_chunk;
}

void chunk_destroy(Chunk *chunk)
{
    for (unsigned i = 0; i < chunk->size.y; i++)
        free(chunk->tiles[i]);
    
    free(chunk->tiles);
    chunk->valid = false;
    chunk_next_id = chunk->id;
}

void chunk_drawdebug(Chunk *chunk)
{

    DrawRectangleLines(gui_scale(chunk->pos.x), gui_scale(chunk->pos.y), gui_scale(chunk->size.x), gui_scale(chunk->size.y), RED);

    const char *debugtext = TextFormat("id: %d", chunk->id);

    DrawText(debugtext, gui_scale(chunk->pos.x), gui_scale(chunk->pos.y - 1), gui_scale(1), RED);
}

void chunk_drawtilesdebug(Chunk *chunk)
{
    int gui_scale = get_gui_scale();

    for (int x = 0; x < chunk->size.x; x++)
    {
        int drawx = chunk->pos.x + x * gui_scale;

        for (int y = 0; y < chunk->size.y; y++)
        {
            int drawy = chunk->pos.y + y * gui_scale;

            switch (chunk->tiles[x][y].type)
            {
            case TILETYPE_AIR:
                DrawRectangleLines(drawx, drawy, gui_scale, gui_scale, BLUE);
                break;
            case TILETYPE_GROUND:
                DrawRectangle(drawx, drawy, gui_scale, gui_scale, DARKBROWN);
                break;
            case TILETYPE_CONCRETE:
                DrawRectangle(drawx, drawy, gui_scale, gui_scale, GRAY);
                break;
            }
        }
    }
}

Chunk *chunk_get_by_id(unsigned id)
{
    return &chunk_arr[id];
}