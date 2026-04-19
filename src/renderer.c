#include "renderer.h"
#include <stdio.h>
#define MAX_DIST 100.f
#define SCREEN_CHARACTERS "@%#*+=-:. "
#define NUM_CHARS sizeof(SCREEN_CHARACTERS) - 1
#define MAX_DEPTH 300
#define EPSILON 1e-3

static inline float ray_marching(Ray_t ray, Scene_t scene) {
    float t = 0;
    vec3 point = { 0 };
    for (int depth = 0; depth < MAX_DEPTH; depth++)
    {    
        point = ray_sample_pos(ray, t);
        float step = scene_sdf_min(scene, point);
        if (step <= EPSILON) {
            return t;
        }
        t += step;

        if (t >= MAX_DIST) {
            break;
        }
    }
    return INFINITY;
}

static inline char distance_to_char(float distance) {
    if (distance >= MAX_DIST)
        return ' ';

    float t = distance / MAX_DIST;
    int index = (int)((t) * (NUM_CHARS - 1));

    return SCREEN_CHARACTERS[index];
    return SCREEN_CHARACTERS[index];
}

void render_scene(ScreenBuffer_t *screen, Scene_t scene, Camera_t camera) {
    for (int y = 0; y < screen->height; y++)
    {
        for (int x = 0; x < screen->width; x++)
        {
            Ray_t ray = camera_get_ray_from_pixel_coord(camera, ivec2_create(x, y));
            
            float dist = ray_marching(ray, scene);
            char c = distance_to_char(dist);
            screen_buffer_set_pixel(screen, x, y, c);
        }
        
    }
    
}