#ifndef VEC3_H
#define VEC3_H

#include <math.h>

typedef struct {
    float x;
    float y;
    float z;
} vec3;

static inline vec3 vec3_create(float x, float y, float z) {
    return (vec3) {x, y, z};
}

static inline vec3 vec3_add(vec3 u, vec3 v) {
    return (vec3) {
        .x = u.x + v.x,
        .y = u.y + v.y,
        .z = u.z + v.z,
    };
}

static inline vec3 vec3_sub(vec3 u, vec3 v) {
    return (vec3){
        u.x - v.x, 
        u.y - v.y, 
        u.z - v.z
    };
}

static inline vec3 vec3_scale(vec3 u, float s) {
    return (vec3){
        u.x * s, 
        u.y * s, 
        u.z * s
    };
}

static inline float vec3_length(vec3 u) {
    return sqrtf(u.x*u.x + u.y*u.y + u.z*u.z);
}

static inline float vec3_dot(vec3 u, vec3 v) {
    return u.x*v.x + u.y*v.y + u.z*v.z;
}

static inline vec3 vec3_normalize(vec3 u) {
    return vec3_scale(u, vec3_length(u));
}


#endif // VEC3_H