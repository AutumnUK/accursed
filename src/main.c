#include <gb/gb.h>

#include "game.c"
#include "tilemaps/titleScreen.c"
#include "tilesets/titleSprites.c"
#include "tilesets/sprites.c"


uint8_t state,
        selection;

void main() {
    // Startup (general)
    SHOW_BKG;
    SHOW_SPRITES;
    DISPLAY_ON;	
    set_sprite_data ( 0, 128, sprites);
    scoreInit();

    // Startup (main menu)
    state       = 0;
    selection   = 1;
    set_bkg_tiles   ( 0 , 0, 20, 18 , titleScreen);
    set_bkg_data    ( 0 , 127, titleSprites);
    set_sprite_tile ( 0 , 1);

    // Main menu.
    while(state == 0) {

        /*
        *   This section needs to be updated.
        *   Current behaviour is that you can hold up/down.
        *   It should activate on release.
        */

        // Move selection up/down.
        if (joypad() & J_DOWN)  { selection ++; }
        if (joypad() & J_UP  )  { selection --; }

        // Reset position.
        if (selection == 0)     { selection = 1;}
        if (selection == 4)     { selection = 3;}

        // Start game / Highscores / Options
        if (selection == 1) { move_sprite (0, 100, 112); if (joypad() & J_A) { state = 1; break; } }
        if (selection == 2) { move_sprite (0, 100, 128); }
        if (selection == 3) { move_sprite (0, 100, 144); }

        // Input delay.
        delay(200);
    }

    // Start game.
    while (state == 1) { 
        scoreUpdate();
        game(); 
    }

    // Highscores   = state 2
    // Options      = state 3
}