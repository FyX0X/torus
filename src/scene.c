#include "scene.h"

#define DEFAULT_ARRAY_CAPACITY 4

Scene_t scene_create() {
    return (Scene_t) {
        .objects_sdf = NULL,
        .object_count = 0,
        .capacity = 0,
    };
}

int scene_add_object(Scene_t scene, sdf_t object_sdf) {
    // realloc if needed.
    if (scene.object_count == scene.capacity) {
        sdf_t *temp = realloc(scene.objects_sdf, scene.capacity ? scene.capacity * 2 : DEFAULT_ARRAY_CAPACITY);
        if (!temp) {
            free(scene.objects_sdf);
            scene.capacity = 0;
            scene.object_count = 0;
            scene.objects_sdf = NULL;
            return -1;
        }
        scene.objects_sdf = temp;
    }

    scene.objects_sdf[scene.object_count++] = object_sdf;
    return 0;
}

float scene_sdf_min(Scene_t scene, vec3 point) {
    float dist = INFINITY;
    for (size_t i = 0; i < scene.object_count; i++)
    {
        dist = fminf(dist, scene.objects_sdf[i](point));
    }
    return dist;
}