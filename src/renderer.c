#include "renderer.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>

ScreenBuffer_t *screen_buffer_create(size_t width, size_t height) {
    ScreenBuffer_t *screen = malloc(sizeof(ScreenBuffer_t) + width * height * sizeof(char));
    screen->width = width,
    screen->height = height,
    screen_buffer_clear(screen);
    return screen;
}

void screen_buffer_free(ScreenBuffer_t *screen) {
    assert(screen);
    free(screen);
}

void screen_buffer_render(const ScreenBuffer_t *screen) {
    assert(screen);
    puts("\n>> Screen:\n");
    size_t size = (screen->width + 1) * screen->height * sizeof(char);
    char *text = malloc(size);
    size_t text_offset = 0;
    size_t buffer_offset = 0;
    for (size_t y = 0; y < screen->height; y++)
    {
        memcpy(&text[text_offset], &screen->buffer[buffer_offset], screen->width);
        text_offset += screen->width;
        buffer_offset += screen->width;
        text[text_offset++] = '\n';
    }
    fwrite(text, 1, size , stdout);

    // printf("raw buffer:%s", screen->buffer);
}

void screen_buffer_clear(ScreenBuffer_t *screen) {
    assert(screen);

    memset(&screen->buffer, '.', screen->width * screen->height);
}

void screen_buffer_set_pixel(ScreenBuffer_t *screen, size_t x, size_t y, char c) {
    assert(screen);
    screen->buffer[x + screen->width * y] = c;
}