#pragma once

#include <raylib.h>

#define ENTITIES_MAX 1024

typedef struct Entity_VTbl Entity_VTbl;
typedef struct Entity_Class Entity_Class;
typedef struct Entity Entity;
typedef struct Entity_Vars Entity_Vars;
typedef struct Entity_Var Entity_Var;

typedef unsigned ent_id_t;

struct Entity_VTbl
{
    void (*init)(Entity *self);
    void (*update)(Entity *self);
};

struct Entity_Class
{
    char *classname;
    Entity_VTbl *vtbl;
};

struct Entity_Var
{
    char *name;
    void *value_ptr;
    Entity_Var *next_var;
    Entity_Var *prev_var;
};

struct Entity_Vars
{
    unsigned count;
    Entity_Var *first_var;
};

struct Entity
{
    bool valid;
    Vector2 pos;
    Entity_Vars vars;
    Entity_Class *entclass;
};

void init_ent_list();

Entity *ent_create_by_classname(char *classname);
Entity *ent_create(Entity_Class *entclass);

Entity_Class *ent_class_by_name(char *classname);

void ent_update(Entity *ent);