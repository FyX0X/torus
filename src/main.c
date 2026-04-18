#include <stdio.h>
#include "renderer.h"
#include <time.h>
#include <stdbool.h>

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