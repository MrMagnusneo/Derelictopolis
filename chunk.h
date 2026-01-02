#pragma once

#include <raylib.h>
#include "vecutil.h"
#include "tile.h"

#define CHUNK_SIZE 40
#define CHUNKS_MAX 256

typedef unsigned chunk_id_t;

typedef struct Chunk
{
    bool valid;
    chunk_id_t id;
    Vector2i pos;
    Vector2i size;
    Tile **tiles;
} Chunk;

void init_chunk_arr();
Chunk *chunk_create(Vector2i pos, Vector2i size);
void chunk_destroy(Chunk *chunk);
void chunk_drawdebug(Chunk *chunk);
void chunk_drawtilesdebug(Chunk *chunk);
Chunk *chunk_get_by_id(unsigned id);