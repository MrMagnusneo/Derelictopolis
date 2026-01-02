#pragma once

#include "chunk.h"

typedef enum TileType
{
    TILETYPE_AIR,
    TILETYPE_GROUND,
    TILETYPE_CONCRETE
} TileType;

typedef struct Tile
{
    TileType type;
    unsigned damage;
} Tile;