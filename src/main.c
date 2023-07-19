#include <gb/gb.h>
#include "title.c"
#include "player.c"
#include "stage_controller.c"
#include "score.c"
#include "game.c"

uint8_t state;

void startup() {
    SHOW_BKG;
    SHOW_SPRITES;
    DISPLAY_ON;	
    set_sprite_data ( 0, 128, sprites);
}


void main() {
    startup();
    mainMenu();
}