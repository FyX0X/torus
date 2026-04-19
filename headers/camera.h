#ifndef CAMERA_H
#define CAMERA_H

#include "ray.h"
#include "vector.h"
#include <stdint.h>

typedef struct {
    vec3 position;
    vec3 forward;
    vec3 right;
    vec3 up;

    uint32_t screen_width;
    uint32_t screen_height;
} Camera_t;

Camera_t camera_create_default(uint32_t width, uint32_t height);

Ray_t camera_get_ray_from_pixel_coord(Camera_t camera, ivec2 pixel_coord);

#endif // CAMERA_H
