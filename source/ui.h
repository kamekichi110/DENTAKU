#ifndef UI_H
#define UI_H

void ui_init();
void ui_exit();
void ui_draw_keyboard();
void ui_clear_screen();
void ui_get_input(char *input);
void ui_handle_input(char input[256]);

#endif // UI_H
