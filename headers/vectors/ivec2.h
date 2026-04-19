#ifndef IVEC2_H
#define IVEC2_H

#include <math.h>

typedef struct {
    int x;
    int y;
} ivec2;

static inline ivec2 ivec2_add(ivec2 u, ivec2 v) {
    return (ivec2) {
        .x = u.x + v.x,
        .y = u.y + v.y,
    };
}

static inline ivec2 ivec2_sub(ivec2 u, ivec2 v) {
    return (ivec2){
        u.x - v.x, 
        u.y - v.y,
    };
}

static inline ivec2 ivec2_scale(ivec2 u, int s) {
    return (ivec2){
        u.x * s, 
        u.y * s,
    };
}


#endif // IVEC2_H