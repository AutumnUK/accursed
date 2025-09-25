#include <gb/gb.h>

uint8_t score1,
        score10,
        score100,
        score1000,
        score10000;

void scoreDisplay(uint8_t s, uint8_t id, uint8_t x) { 
    if (s == 0) { set_sprite_tile(id,100); }
    if (s == 1) { set_sprite_tile(id,101); }
    if (s == 2) { set_sprite_tile(id,102); }
    if (s == 3) { set_sprite_tile(id,103); }
    if (s == 4) { set_sprite_tile(id,104); }
    if (s == 5) { set_sprite_tile(id,105); }
    if (s == 6) { set_sprite_tile(id,106); }
    if (s == 7) { set_sprite_tile(id,107); }
    if (s == 8) { set_sprite_tile(id,108); }
    if (s == 9) { set_sprite_tile(id,109); }
    move_sprite(id,x,152);
}

void scoreUpdate(void) {
    scoreDisplay(score10000, 30,  8);
    scoreDisplay(score1000,  31, 16);
    scoreDisplay(score100,   32, 24);
    scoreDisplay(score10,    33, 32);
    scoreDisplay(score1,     34, 40);
	set_sprite_tile (35,100);
	move_sprite     (35,48,152);
    if (score1 >= 10) { score10 ++; score1 -= 10;}
}

void scoreInit(void) {
    score10000 = 0;
    score1000  = 0;
    score100   = 0;
    score10    = 0;
    score1     = 0;
}
