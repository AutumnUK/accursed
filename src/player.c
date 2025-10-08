#include    "../Tools/GBDK/include/gb/gb.h"

#define     RELOAD      20
#define     MIN_X       8
#define     MAX_X       160
#define     MIN_Y       16
#define     MAX_Y       136
#define     NUM_BULLETS 3
#define     SPEED       1
#define     NORM_SPEED  256 / 170

struct Player {
    int x;
    int y;
    int id;
    int shooting;

};

struct PlayerBullet {
    uint8_t x,
            y,
            id,
            tile;

    BOOLEAN ready;
    
};

uint8_t currentBullet, reload;

struct  Player          player;
struct  PlayerBullet    bullets[NUM_BULLETS];

void playerInit(void) {
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

void playerMovement(void) {
    move_sprite( player.id , player.x, player.y);
    int moving_right = 0;
    int moving_up = 0;
    int moving_left = 0;

    if (joypad() & J_RIGHT) { moving_right = 1; } else { moving_right = 0;}
    if (joypad() & J_LEFT) { moving_left = 1;} else { moving_left = 0;}
    if (joypad() & J_UP) { moving_up = 1; } else {moving_up = 0;}

    if (moving_right == 1) {
        player.x += SPEED;
    }

    if (moving_right == 1 && moving_up == 1) {
        player.x += NORM_SPEED;
        player.y -= NORM_SPEED;
    }
    if (moving_left == 1) {
        player.x -= SPEED;
    }

    

    if (joypad() & J_A    ) { player.shooting = TRUE; } else { player.shooting = FALSE; } 
    if (joypad() & J_LEFT   ) { set_sprite_tile(player.id,0);} else { set_sprite_tile(player.id,1);}
}

void bulletUpdate(void) {
    if (reload > 0) { reload --; }
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

    for (int i = 0; i < NUM_BULLETS; i++) {
        if (bullets[i].x >= MAX_X) { bullets[i].x = 200; bullets[i].ready = TRUE; }

        bullets[i].x += 5;
        move_sprite(bullets[i].id, bullets[i].x, bullets[i].y);
    }
}

void playerUpdate(void) { playerMovement(); bulletUpdate(); }