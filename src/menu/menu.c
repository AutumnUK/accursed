#include <gb/gb.h>
#include "menu_map.h"
#include "menu_sprites.h"
#include "../generics/sprites.h"



uint8_t main_menu( void ){
    uint8_t selection       = 1;
    uint8_t a_press         = 0;
    uint8_t a_pressed       = 0;
    uint8_t down_press      = 0;
    uint8_t down_pressed    = 0;
    uint8_t up_press        = 0;
    uint8_t up_pressed      = 0;
    
    set_sprite_data ( 0 , 128 , sprites );
    set_bkg_tiles   ( 0 , 0, 20, 18 , menuScreen);
    set_bkg_data    ( 0 , 127, menuSprites);
    set_sprite_tile ( 0 , 1); 

    while(1) {
        vsync();
        if (joypad() & J_A) { a_press = 1; a_pressed = 1; }
        else { a_press = 0; }
        if (a_press == 0 && a_pressed == 1) { return selection; }
        
        if (joypad() & J_DOWN) { down_press = 1; down_pressed = 1; }
        else { down_press = 0; }
        if (down_press == 0 && down_pressed == 1) { selection++; down_pressed = 0; }

        if (joypad() & J_UP) { up_press = 1; up_pressed = 1; }
        else { up_press = 0; }
        if (up_press == 0 && up_pressed == 1) { selection--; up_pressed = 0; }

        if (selection == 0)     { selection = 1;}
        if (selection == 4)     { selection = 3;}

        switch (selection){
            case 1: move_sprite (0, 100, 112); break;
            case 2: move_sprite (0, 100, 128); break;
            case 3: move_sprite (0, 100, 144); break;
        }
    }
}