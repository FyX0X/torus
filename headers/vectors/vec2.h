#ifndef VEC2_H
#define VEC2_H

#include <math.h>

typedef struct {
    float x;
    float y;
} vec2;

static inline vec2 vec3_create(float x, float y) {
    return (vec2) {x, y};
}

static inline vec2 vec2_add(vec2 u, vec2 v) {
    return (vec2) {
        .x = u.x + v.x,
        .y = u.y + v.y,
    };
}

static inline vec2 vec2_sub(vec2 u, vec2 v) {
    return (vec2){
        u.x - v.x, 
        u.y - v.y,
    };
}

static inline vec2 vec2_scale(vec2 u, float s) {
    return (vec2){
        u.x * s, 
        u.y * s,
    };
}

static inline float vec2_length(vec2 u) {
    return sqrtf(u.x*u.x + u.y*u.y);
}

static inline float vec2_dot(vec2 u, vec2 v) {
    return u.x*v.x + u.y*v.y;
}

static inline vec2 vec2_normalize(vec2 u) {
    return vec2_scale(u, vec2_length(u));
}


#endif // VEC2_H