#include "camera.h"

#include "vector.h"
#include <math.h>


static inline vec2 pixel_to_ndc(Camera_t camera, ivec2 pixel_coord) {
    return (vec2) {
        (2.0f * pixel_coord.x / camera.screen_width) - 1.0f,
        (2.0f * pixel_coord.y / camera.screen_height) - 1.0f,
    };
}


Camera_t camera_create_default(uint32_t width, uint32_t height) {
    return (Camera_t) {
        .position = {0, 0, 0},
        .forward = {0, 0, -1},
        .right = {1, 0, 0},
        .up = {0, 1, 0},

        .screen_width = width,
        .screen_height = height,
    };
}


Ray_t camera_get_ray_from_pixel_coord(Camera_t camera, ivec2 pixel_coord) {

    vec2 ndc = pixel_to_ndc(camera, pixel_coord);

    ndc.x *= camera.screen_width / camera.screen_height;

    vec3 dir = vec3_add(
        vec3_add(
            vec3_scale(camera.right, ndc.x),
            vec3_scale(camera.up, ndc.y)
        ),
        camera.forward
    );

    dir = vec3_normalize(dir);


    Ray_t ray = {
        .position = camera.position,
        .direction = dir
    };

    return ray;
}