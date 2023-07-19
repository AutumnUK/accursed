#include <gb/gb.h>
#include "tilemaps/titleScreen.c"
#include "tilesets/titleSprites.c"
#include "tilesets/sprites.c"

uint8_t mainMenu() {

    uint8_t selection;

    selection = 1;

    set_bkg_tiles   ( 0,   0, 20, 18 , titleScreen);
    set_bkg_data    ( 0, 127, titleSprites);
    set_sprite_data ( 0, 2,sprites);
    set_sprite_tile ( 0, 1);

    while(1) {
        if (joypad() & J_DOWN)  { selection ++; }
        if (joypad() & J_UP)    { selection --; }
        if (selection == 0)     { selection = 1;}
        if (selection == 4)     { selection = 3;}

        // Start the game.
        if (selection == 1) { 
            move_sprite (0, 100, 112);
            if (joypad() & J_A) {
                return 3;
                break;
            } 
        }

        // Highscore (currently options).
        if (selection == 2) { 
            move_sprite (0, 100, 128);
        }

        // Highscore (currently options).
        if (selection == 3) { 
            move_sprite (0, 100, 144);
        }

        delay(200);
    }
}
