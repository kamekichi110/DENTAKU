#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <3ds.h>
#include "ui.h"
#include "calculator.h"
#include "graph.h"

#define MAX_INPUT_LENGTH 256

void process_input(char *input) {
    // Evaluate expression or solve equation based on input
    if (strstr(input, "x") != NULL || strstr(input, "y") != NULL || strstr(input, "z") != NULL) {
        // Graphing logic
        printf("グラフを描画します...\n");
        // Example: Placeholder for graphing function call
    } else {
        // Calculator logic
        parse_and_solve_equation(input);
    }
}

int main() {
    // Initialize 3DS services
    gfxInitDefault();
    consoleInit(GFX_TOP, NULL);

    // Main loop
    while (aptMainLoop()) {
        // Draw UI elements
        ui_clear_screen();
        ui_draw_keyboard();

        // Get user input
        char input[MAX_INPUT_LENGTH];
        ui_get_input(input);

        // Process input
        process_input(input);

        // Wait for user input to continue
        printf("Press START to exit.\n");

        // Check for user exit (START button)
        hidScanInput();
        u32 kDown = hidKeysDown();
        if (kDown & KEY_START) {
            break;
        }
    }

    // Exit
    ui_exit();
    gfxExit();
    return 0;
}
