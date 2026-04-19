#include "camera.h"
#include "screen_buffer.h"
#include "renderer.h"
#include "scene.h"
#include <stdbool.h>
#include <stdio.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 40

struct timespec ts;

int main() {

    printf(">> Torus Renderer !\n");

    ScreenBuffer_t *screen = screen_buffer_create(WIDTH, HEIGHT);

    ts.tv_sec = 2;
    ts.tv_nsec = (int)1e7; // 0.1 seconds

    int x = 0;
    int y = 0;

    Camera_t camera = camera_create_default(WIDTH, HEIGHT);
    camera.position.z = 19;

    Scene_t scene = scene_create();

    Sphere_t sp1 = { .center = { 0, 0, 0 }, .radius = 10 };
    Sphere_t sp2 = { .center = { 14, 0, 0 }, .radius = 5 };
    Sphere_t sp3 = { .center = { -50, 40, -80 }, .radius = 50 };
    Sphere_t sp4 = { .center = { -10, -5, -20 }, .radius = 10 };
    Shape_t shape1 = { .data = &sp1, .sdf = sphere_sdf };
    Shape_t shape2 = { .data = &sp2, .sdf = sphere_sdf };
    Shape_t shape3 = { .data = &sp3, .sdf = sphere_sdf };
    Shape_t shape4 = { .data = &sp4, .sdf = sphere_sdf };
    //scene_add_object(&scene, shape1);
    scene_add_object(&scene, shape2);
    scene_add_object(&scene, shape3);
    scene_add_object(&scene, shape4);

    printf("Scene Object Count: %zu\n", scene.object_count);

    while (true) {
        render_scene(screen, scene, camera);

        screen_buffer_show(screen);

        nanosleep(&ts, NULL);
    }

    screen_buffer_free(screen);

    return 0;
}
