#include <gb/gb.h>
#include "sprites.c"
#include "background.c"
#include "level.c"
#include "player.c"

void main() {  
    set_sprite_data( 0, 128, sprites);
    bkgInit();
    playerInit();
    scoreInit();
    SHOW_SPRITES;
    DISPLAY_ON;
	
    while(1) {
        bkgUpdate();
        level();
        playerUpdate();
        wait_vbl_done();
        scoreUpdate();
    }
	
}