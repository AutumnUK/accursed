#include <gb/gb.h> 
#include "enemy.c"

uint8_t seconds, 
		frame;
		
void frameController() { frame++; if (frame == 60) { seconds++; frame = 0; } }

void level() {
    frameController();
	
	// Wave 1
	if (seconds ==  2 && frame ==  0) { enemyInit(&skulls[0], 10, 170,  50, SKULL_SPRITE_TILE);  squarePattern(&skulls[0], 60); }
	if (seconds ==  2 && frame == 20) { enemyInit(&skulls[1], 11, 170,  50, SKULL_SPRITE_TILE);  squarePattern(&skulls[1], 60); }
	if (seconds ==  2 && frame == 40) {	enemyInit(&skulls[2], 12, 170,  50, SKULL_SPRITE_TILE);  squarePattern(&skulls[2], 60); }
	if (seconds ==  3 && frame ==  0) { enemyInit(&skulls[3], 13, 170,  50, SKULL_SPRITE_TILE);  squarePattern(&skulls[3], 60); }
	if (seconds ==  3 && frame == 20) { enemyInit(&skulls[4], 14, 170,  50, SKULL_SPRITE_TILE);  squarePattern(&skulls[4], 60); }
		
	// Wave 2
	if (seconds ==  8 && frame ==  0) { enemyInit(&skulls[0], 10, 170, 110, SKULL_SPRITE_TILE); squarePatternR(&skulls[0], 60); }
	if (seconds ==  8 && frame == 20) { enemyInit(&skulls[1], 11, 170, 110, SKULL_SPRITE_TILE); squarePatternR(&skulls[1], 60); }
	if (seconds ==  8 && frame == 40) {	enemyInit(&skulls[2], 12, 170, 110, SKULL_SPRITE_TILE); squarePatternR(&skulls[2], 60); }
	if (seconds ==  9 && frame ==  0) { enemyInit(&skulls[3], 13, 170, 110, SKULL_SPRITE_TILE); squarePatternR(&skulls[3], 60); }
	if (seconds ==  9 && frame == 20) { enemyInit(&skulls[4], 14, 170, 110, SKULL_SPRITE_TILE); squarePatternR(&skulls[4], 60); }
	
	// Wave 3
	if (seconds == 14 && frame ==  0) { enemyInit(&skulls[0], 10, 170, 110, SKULL_SPRITE_TILE); squarePatternR(&skulls[0], 60); }
	if (seconds == 14 && frame == 20) { enemyInit(&skulls[1], 11, 190,  50, SKULL_SPRITE_TILE);  squarePattern(&skulls[1], 60); }
	if (seconds == 14 && frame == 40) {	enemyInit(&skulls[2], 12, 170, 110, SKULL_SPRITE_TILE); squarePatternR(&skulls[2], 60); }
	if (seconds == 15 && frame ==  0) { enemyInit(&skulls[3], 13, 190,  50, SKULL_SPRITE_TILE);  squarePattern(&skulls[3], 60); }
	if (seconds == 15 && frame == 20) { enemyInit(&skulls[4], 14, 170, 110, SKULL_SPRITE_TILE); squarePatternR(&skulls[4], 60); }
	
	enemyUpdate(&skulls[0]);
	enemyUpdate(&skulls[1]);
	enemyUpdate(&skulls[2]);
	enemyUpdate(&skulls[3]);
	enemyUpdate(&skulls[4]);
	
	if (seconds == 20) { seconds = 0; }
}
