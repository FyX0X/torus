#ifndef RENDERER_H
#define RENDERER_H

#include "scene.h"
#include "camera.h"
#include "screen_buffer.h"

void render_scene(ScreenBuffer_t *screen, Scene_t scene, Camera_t camera);

#endif // RENDERER_H