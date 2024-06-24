#include "graph.h"
#include <citro2d.h>
#include <stdio.h>
#include <math.h>

#define SCREEN_WIDTH 400
#define SCREEN_HEIGHT 240

static C2D_Image background_img;
static bool background_loaded = false;

void load_background() {
    if (!background_loaded) {
        FILE* file = fopen("gfx/background.bin", "rb");
        if (file) {
            fseek(file, 0, SEEK_END);
            long size = ftell(file);
            rewind(file);
            u8* buffer = (u8*)malloc(size);
            if (buffer) {
                fread(buffer, 1, size, file);
                C2D_PlainImageInit(&background_img, size, 200, GPU_RGBA8);
                C2D_SpriteFromMem(&background_img, buffer, GPU_RGBA8);
                free(buffer);
                background_loaded = true;
            }
            fclose(file);
        }
    }
}

void draw_graph(const char* function) {
    C2D_TargetClear(top, C2D_Color32(0x00, 0x00, 0x00, 0xFF));
    C2D_SceneBegin(top);

    // Load and draw background image
    load_background();
    C2D_DrawImageAt(&background_img, 0, 0, 0, NULL, 1.0f, 1.0f);

    // Draw graph
    C2D_DrawRectSolid(50, 50, 0, SCREEN_WIDTH - 100, SCREEN_HEIGHT - 100, C2D_Color32(0x00, 0xFF, 0x00, 0xFF));

    // Example: Plotting a simple function (sin wave)
    float x, y_prev, y_curr;
    y_prev = SCREEN_HEIGHT / 2 + sinf(-SCREEN_WIDTH / 2 * 0.1f) * (SCREEN_HEIGHT / 4);
    for (x = -SCREEN_WIDTH / 2 + 1; x < SCREEN_WIDTH / 2; x++) {
        y_curr = SCREEN_HEIGHT / 2 + sinf(x * 0.1f) * (SCREEN_HEIGHT / 4);
        C2D_DrawLine(x + SCREEN_WIDTH / 2, y_prev, x + 1 + SCREEN_WIDTH / 2, y_curr, C2D_Color32(0x00, 0xFF, 0x00, 0xFF), C2D_Color32(0x00, 0xFF, 0x00, 0xFF), 1.0f);
        y_prev = y_curr;
    }
}
