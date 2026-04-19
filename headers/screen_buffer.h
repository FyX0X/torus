#ifndef SCREEN_BUFFER_H
#define SCREEN_BUFFER_H

#include <stdlib.h>

typedef struct {
    size_t width;
    size_t height;
    char buffer[];
} ScreenBuffer_t;

ScreenBuffer_t *screen_buffer_create(size_t width, size_t height);

void screen_buffer_free(ScreenBuffer_t *screen);

void screen_buffer_show(const ScreenBuffer_t *screen);

void screen_buffer_clear(ScreenBuffer_t *screen);

void screen_buffer_set_pixel(ScreenBuffer_t *screen, size_t x, size_t y, char c);

#endif // SCREEN_BUFFER_H
