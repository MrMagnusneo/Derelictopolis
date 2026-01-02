#pragma once

#include <raylib.h>

typedef enum CollisionType
{
    COLLISIONTYPE_TILE,
    COLLISIONTYPE_ENTITY
} CollisionType;

typedef struct Collision
{
    CollisionType coll_type;
    Rectangle intersection;
} Collision;