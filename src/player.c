#include <gb/gb.h>
#include "../include/player.h"

#define RELOAD      20
#define MIN_X       8
#define MAX_X       160
#define MIN_Y       16
#define MAX_Y       136
#define NUM_BULLETS 3

        uint8_t         currentBullet,
                        reload;

struct  Player          player;

struct  PlayerBullet    bullets[NUM_BULLETS];

void playerInit() {
    reload          =   0;
    player.x        =  50;
    player.y        =  50;
    player.id       =  20;
    player.shooting = FALSE;
    currentBullet   =   1;

    for (int i = 0; i < NUM_BULLETS; i++) {
        bullets[i].ready = TRUE;
        bullets[i].x     = 200;   
        bullets[i].y     = 0;
        bullets[i].id    = i + 1;  
        bullets[i].tile  = 2;
        set_sprite_tile(bullets[i].id, bullets[i].tile);
    }
}

// Each frame checks for input then relocates the player.
void playerMovement() {
    move_sprite( player.id , player.x , player.y );
    if (joypad() & J_UP   ) { player.y -- ; if ( player.y < MIN_Y ) { player.y = MIN_Y; } }
    if (joypad() & J_DOWN ) { player.y ++ ; if ( player.y > MAX_Y ) { player.y = MAX_Y; } }
    if (joypad() & J_LEFT ) { player.x -- ; if ( player.x < MIN_X ) { player.x = MIN_X; } }
    if (joypad() & J_RIGHT) { player.x ++ ; if ( player.x > MAX_X ) { player.x = MAX_X; } }
    if (joypad() & J_A    ) { player.shooting = TRUE; } else { player.shooting = FALSE; } 
    if (joypad() & J_LEFT   ) { set_sprite_tile(player.id,0);} else { set_sprite_tile(player.id,1);}
}

void bulletUpdate() {
    // count down to next shot
    if (reload > 0) { reload --; }
    // If player is shooting and timer == 0.
    if (player.shooting && reload == 0) {
        for (int i = 0; i < NUM_BULLETS; i++) {
            if (currentBullet == i + 1) {
                bullets[i].x     = player.x;
                bullets[i].y     = player.y;
                bullets[i].ready = FALSE;
                reload += RELOAD;
                currentBullet = (currentBullet % NUM_BULLETS) + 1;
                break;
            }
        }
    }

    // Hide the bullet.
    for (int i = 0; i < NUM_BULLETS; i++) {
        if (bullets[i].x >= MAX_X) { bullets[i].x = 200; bullets[i].ready = TRUE; }

        bullets[i].x += 5;
        move_sprite(bullets[i].id, bullets[i].x, bullets[i].y);
    }
}

void playerUpdate() { playerMovement(); bulletUpdate(); }