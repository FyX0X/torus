#include "camera.h"
#include "renderer.h"
#include "scene.h"
#include <stdbool.h>
#include <stdio.h>
#include <time.h>

#define WIDTH 76
#define HEIGHT 50

struct timespec ts;

int main() {

    printf(">> Torus Renderer !\n");

    ScreenBuffer_t *screen = screen_buffer_create(WIDTH, HEIGHT);

    ts.tv_sec = 0;
    ts.tv_nsec = (int)1e7; // 0.1 seconds

    int x = 0;
    int y = 0;

    Camera_t camera = camera_create_default(WIDTH, HEIGHT);
    camera.position.z = 3;

    Scene_t scene = scene_create();

    Sphere_t sp1 = { .center = { 0, 0, 0 }, .radius = 1 };
    Sphere_t sp2 = { .center = { 1.4, 0, 0 }, .radius = 0.5 };
    Shape_t shape1 = { .data = &sp1, .sdf = sphere_sdf };
    Shape_t shape2 = { .data = &sp2, .sdf = sphere_sdf };
    scene_add_object(scene, shape1);
    scene_add_object(scene, shape2);

    while (true) {
        screen_buffer_render(screen);

        screen_buffer_set_pixel(screen, x++, y++, '@');
        x %= WIDTH;
        y %= HEIGHT;

        nanosleep(&ts, NULL);
    }

    screen_buffer_free(screen);

    return 0;
}
