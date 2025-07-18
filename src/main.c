#include "headers.h"

void main(void) {
    SHOW_BKG;
    SHOW_SPRITES;
    DISPLAY_ON;
    uint8_t x = main_menu();

    switch ( x ) {
        case 1 : 
            
            stage_1();
            x = 0;
            break;
    }
}