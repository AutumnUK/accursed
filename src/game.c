#include <gb/gb.h>
#include "level1_background.c"
#include "enemy.c"
#include "player.c"
#include "score.c"

uint8_t seconds, 
        frame;

void bulletCollision() {
    uint8_t i, 
            j;
    for ( i = 0; i < NUM_BULLETS; i++) {
        for ( j = 0; j < ENEMY_COUNT; j++) {
            if (skulls[j].active && 
                bullets[i].x >= skulls[j].x - 4 && 
                bullets[i].x <= skulls[j].x + 8 &&
                bullets[i].y >= skulls[j].y - 4 && 
                bullets[i].y <= skulls[j].y + 4) {
                // Collision detected
                bullets[i].x = 0;
                bullets[i].y = 0; // Move bullet offscreen
                score1 ++;
                skulls[j].x = 170; // Move enemy offscreen
                deactivateEnemy(&skulls[j]);
            }
        }
    }
}

void playerHurtCollision() {
    uint8_t i;

    for ( i = 0; i < ENEMY_COUNT; i++ ) {
        if (skulls[i].active && 
            player.x >= skulls[i].x && 
            player.x <= skulls[i].x - 8 &&
            player.y >= skulls[i].y - 4 && 
            player.y <= skulls[i].y + 4) {
                score1 ++;
            }
    }
}

void generalUpdate() {
        bulletCollision();
    playerHurtCollision();
    scoreUpdate();
    wait_vbl_done();
}

void level1() {
    uint8_t i;

    // Clock.
    frame++; if (frame == 60) { seconds++; frame = 0; }

	playerUpdate();
    for (i = 0; i < 5; i++) { enemyUpdate(&skulls[i]); }
	
    enemyInit(&skulls[5], 20, 150,50,SKULL_SPRITE_TILE,1); homingPattern(&skulls[5]);

	// Wave 1
	if (seconds ==  2 && frame ==  0) { enemyInit(&skulls[0], 10, 170,  50, SKULL_SPRITE_TILE,1);  squarePattern(&skulls[0], 60); }
	if (seconds ==  2 && frame == 20) { enemyInit(&skulls[1], 11, 170,  50, SKULL_SPRITE_TILE,1);  squarePattern(&skulls[1], 60); }
	if (seconds ==  2 && frame == 40) {	enemyInit(&skulls[2], 12, 170,  50, SKULL_SPRITE_TILE,1);  squarePattern(&skulls[2], 60); }
	if (seconds ==  3 && frame ==  0) { enemyInit(&skulls[3], 13, 170,  50, SKULL_SPRITE_TILE,1);  squarePattern(&skulls[3], 60); }
	if (seconds ==  3 && frame == 20) { enemyInit(&skulls[4], 14, 170,  50, SKULL_SPRITE_TILE,1);  squarePattern(&skulls[4], 60); }
		
	// Wave 2
	if (seconds ==  8 && frame ==  0) { enemyInit(&skulls[0], 10, 170, 110, SKULL_SPRITE_TILE,1); squarePatternR(&skulls[0], 60); }
	if (seconds ==  8 && frame == 20) { enemyInit(&skulls[1], 11, 170, 110, SKULL_SPRITE_TILE,1); squarePatternR(&skulls[1], 60); }
	if (seconds ==  8 && frame == 40) {	enemyInit(&skulls[2], 12, 170, 110, SKULL_SPRITE_TILE,1); squarePatternR(&skulls[2], 60); }
	if (seconds ==  9 && frame ==  0) { enemyInit(&skulls[3], 13, 170, 110, SKULL_SPRITE_TILE,1); squarePatternR(&skulls[3], 60); }
	if (seconds ==  9 && frame == 20) { enemyInit(&skulls[4], 14, 170, 110, SKULL_SPRITE_TILE,1); squarePatternR(&skulls[4], 60); }
	
	// Wave 3
	if (seconds == 14 && frame ==  0) { enemyInit(&skulls[0], 10, 170, 110, SKULL_SPRITE_TILE,1); squarePatternR(&skulls[0], 60); }
	if (seconds == 14 && frame == 20) { enemyInit(&skulls[1], 11, 190,  50, SKULL_SPRITE_TILE,1);  squarePattern(&skulls[1], 60); }
	if (seconds == 14 && frame == 40) {	enemyInit(&skulls[2], 12, 170, 110, SKULL_SPRITE_TILE,1); squarePatternR(&skulls[2], 60); }
	if (seconds == 15 && frame ==  0) { enemyInit(&skulls[3], 13, 190,  50, SKULL_SPRITE_TILE,1);  squarePattern(&skulls[3], 60); }

	// Wave 4
	if (seconds == 20 && frame ==  0) { enemyInit(&skulls[0], 10, 170,  50, SKULL_SPRITE_TILE,1);  squarePattern(&skulls[0], 60); }
	if (seconds == 20 && frame == 20) { enemyInit(&skulls[1], 11, 190, 110, SKULL_SPRITE_TILE,1); squarePatternR(&skulls[1], 60); }
	if (seconds == 20 && frame == 40) {	enemyInit(&skulls[2], 12, 170,  50, SKULL_SPRITE_TILE,1);  squarePattern(&skulls[2], 60); }
	if (seconds == 21 && frame ==  0) { enemyInit(&skulls[3], 13, 190, 110, SKULL_SPRITE_TILE,1); squarePatternR(&skulls[3], 60); }
	
	if (seconds == 25) { seconds = 0; }
}

uint8_t game() {
    uint8_t currentlevel; 

    currentlevel = 1;
    scoreInit();
    playerInit();
    seconds = 0;
    frame = 0;
    // Level 1
    level1_bkg_init();
    
    while(currentlevel = 1) {
        generalUpdate();
        level1();
        level1_bkg_update();
    }

    // Level 2

    // Level 3

    // Level 4

    // Level 5
}