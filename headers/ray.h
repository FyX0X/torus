#ifndef RAY_H
#define RAY_H

#include "vector.h"

typedef struct {
    vec3 position;
    vec3 direction;
} Ray_t;


static inline vec3 ray_sample_pos(Ray_t ray, float t) {
    return vec3_add(ray.position, vec3_scale(ray.direction, t));
}

#endif // RAY_H
