#include <stdio.h>
#include <string.h>
#include <3ds.h>
#include "ui.h"

// Key definitions
#define KEYBOARD_ROWS 4
#define KEYBOARD_COLS 5

char keyboard[KEYBOARD_ROWS][KEYBOARD_COLS] = {
    {'7', '8', '9', '+', '-'},
    {'4', '5', '6', '*', '/'},
    {'1', '2', '3', 'x', 'y'},
    {'0', '(', ')', '=', 'z'}
};

void draw_keypad() {
    gfxFlushBuffers();
    gfxSwapBuffers();
    gspWaitForVBlank();
}

void draw_text(const char *text) {
    printf("\x1b[24;1H%s", text);
}

void ui_init() {
    gfxInitDefault();
    consoleInit(GFX_BOTTOM, NULL);
}

void ui_exit() {
    gfxExit();
}

void ui_draw_keyboard() {
    printf("\x1b[0;0H");
    for (int i = 0; i < KEYBOARD_ROWS; ++i) {
        for (int j = 0; j < KEYBOARD_COLS; ++j) {
            printf("%c ", keyboard[i][j]);
        }
        printf("\n");
    }
    draw_keypad();
}

void ui_clear_screen() {
    consoleClear();
}

void ui_get_input(char *input) {
    printf("\x1b[24;0H> ");
    scanf("%s", input);
}

void ui_handle_input(char input[256]) {
    if (strlen(input) == 0) {
        return;
    }

    // Example: Handle '=' to indicate calculation start
    if (strcmp(input, "=") == 0) {
        // Perform calculation or equation solving here
        printf("計算を開始します...\n");
        // Example: Placeholder for actual calculation/solving function call
        printf("計算結果: ...\n");
    } else {
        // Handle other inputs as needed
        printf("入力された式: %s\n", input);
    }
}
