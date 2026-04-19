#ifndef SCENE_H
#define SCENE_H

#include <stdlib.h>
#include "vector.h"

typedef float (*sdf_func)(vec3 point, void* data);

typedef struct {
    sdf_func sdf;
    void *data;
} Shape_t;


typedef struct {
    Shape_t *shapes;

    size_t object_count;
    size_t capacity;
} Scene_t;


Scene_t scene_create();

int scene_add_object(Scene_t scene, Shape_t shape);

float scene_sdf_min(Scene_t scene, vec3 point);


// ------
// SHAPES
// ------

typedef struct {
    vec3 center;
    float radius;
} Sphere_t;

float sphere_sdf(vec3 p, void *data) {
    Sphere_t *s = data;
    vec3 d = vec3_sub(p, s->center);
    return vec3_length(d) - s->radius;
}

#endif // SCENE_H