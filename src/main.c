#include    "../Tools/GBDK/include/gb/gb.h"
#include    "title.h"


void main(void) {
    SHOW_BKG;
    SHOW_SPRITES;
    DISPLAY_ON;

    set_bkg_tiles(0,0,20,18,titleScreen);
    set_bkg_data(0,120,title_tiles);
    set_sprite_data(0,3,title_selector);

    uint8_t     frames          = 0;
    uint8_t     selection       = 1;
    uint8_t     up_pressed      = 0;
    uint8_t     down_pressed    = 0;
    while (1) {
        vsync();
        
        frames ++;
        if ( frames == 1  ) { set_sprite_tile(0 , 0); }
        if ( frames == 14 ) { set_sprite_tile(0 , 1); }
        if ( frames == 28 ) { set_sprite_tile(0 , 2); }
        if ( frames >  42 ) { frames = 0;             }
        
        if ( selection <= 0) { selection = 3; }
        if ( selection == 1) { move_sprite( 0 , 64 ,  96 ); }
        if ( selection == 2) { move_sprite( 0 , 64 , 112 ); }
        if ( selection == 3) { move_sprite( 0 , 64 , 128 ); }
        if ( selection >= 4) { selection = 1; }

        if (joypad() & J_UP) { up_pressed = 1; }
        if ( !(joypad() & J_UP) && up_pressed == 1) { selection -= 1; up_pressed = 0; } 
        
        if (joypad() & J_DOWN) { down_pressed = 1; }
        if ( !(joypad() & J_UP) && down_pressed == 1) { selection += 1; down_pressed = 0; } 
    }
}