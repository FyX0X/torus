#ifndef SCENE_H
#define SCENE_H

#include <stdlib.h>
#include "vector.h"

typedef float (*sdf_t)(vec3 point);


typedef struct {
    sdf_t *objects_sdf;

    size_t object_count;
    size_t capacity;
} Scene_t;


Scene_t scene_create();

int scene_add_object(Scene_t scene, sdf_t object_sdf);

float scene_sdf_min(Scene_t scene, vec3 point);


#endif // SCENE_H