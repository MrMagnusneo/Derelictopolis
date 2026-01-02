#include "entity.h"
#include <stddef.h>

static Entity entity_list[ENTITIES_MAX];
static ent_id_t entity_next_id = 0;

void init_ent_list()
{
    for (unsigned i = 0; i < ENTITIES_MAX; i++)
        entity_list[i].valid = false;
}

Entity *ent_create_by_classname(char *classname)
{
    Entity_Class *clss = ent_class_by_name(classname);
    return ent_create(clss);
}

Entity *ent_create(Entity_Class *entclass)
{
    Entity *new_ent = &entity_list[entity_next_id];
    *new_ent = (Entity){
        .valid = true,
        .entclass = entclass,
        .vars.count = 0
    };

    do
    {
        entity_next_id++;
    }
    while (entity_list[entity_next_id].valid);

    return new_ent;
}

Entity_Class *ent_class_by_name(char *classname)
{
    // PLACEHOLDER
    return (Entity_Class*)NULL;
}