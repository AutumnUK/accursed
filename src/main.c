#include    "../Tools/GBDK/include/gb/gb.h"
#include    "title.h"
#include    "game.h"

void main(void) {
    SHOW_BKG;
    SHOW_SPRITES;
    DISPLAY_ON;
    uint8_t state = 0;
    while (state == 0) { state = main_menu();   }
    while (state == 1) { state = game();        }
}