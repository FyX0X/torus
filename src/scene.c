#include "scene.h"

#define DEFAULT_ARRAY_CAPACITY 4

Scene_t scene_create() {
    return (Scene_t) {
        .shapes = NULL,
        .object_count = 0,
        .capacity = 0,
    };
}

int scene_add_object(Scene_t scene, Shape_t shape) {
    // realloc if needed.
    if (scene.object_count == scene.capacity) {
        Shape_t *temp = realloc(scene.shapes, scene.capacity ? scene.capacity * 2 : DEFAULT_ARRAY_CAPACITY * sizeof(Shape_t));
        if (!temp) {
            free(scene.shapes);
            scene.capacity = 0;
            scene.object_count = 0;
            scene.shapes = NULL;
            return -1;
        }
        scene.shapes = temp;
    }

    scene.shapes[scene.object_count++] = shape;
    return 0;
}

float scene_sdf_min(Scene_t scene, vec3 point) {
    float dist = INFINITY;
    for (size_t i = 0; i < scene.object_count; i++) {
        dist = fminf(dist, scene.shapes[i].sdf(point, scene.shapes[i].data));
    }
    return dist;
}
