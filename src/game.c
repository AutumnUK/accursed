#include <gb/gb.h>

uint8_t game() {
    uint8_t currentlevel;


    
    currentlevel = 1;

    scoreInit();
    playerInit();

    while(currentlevel = 1) {
        scoreUpdate();
        level();
        
        scoreUpdate();
        wait_vbl_done();
    }
}