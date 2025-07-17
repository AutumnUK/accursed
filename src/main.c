#include <gb/gb.h>
#include <gb/drawing.h>
#include "menu/menu.h"

void main(void) {
    SHOW_BKG;
    SHOW_SPRITES;
    DISPLAY_ON;
    uint8_t x = main_menu();

}