
#include "../headers.h"

#define MIN_X   8
#define MAX_X   160
#define MIN_Y   16
#define MAX_Y   136


#define FP_SCALE    256
#define SPEED       256
#define NORM_SPEED  179

int x = 0;
int y = 0;
int v[2] = { 0 , 0 };

int player_speed = SPEED;

struct Player player;

void player_init(void) {
    player.x    = 50 * FP_SCALE;
    player.y    = 50 * FP_SCALE;
    player.id   = 20;
    move_sprite( player.id , player.x / FP_SCALE , player.y / FP_SCALE );
    set_sprite_tile(player.id,1);
}




void player_movement(void) {
    move_sprite( player.id , player.x / FP_SCALE , player.y / FP_SCALE );

    if (joypad() & J_UP) { y = -1; }
    else if (joypad() & J_DOWN ) { y = 1; }
    else { y = 0; }
    
    if (joypad() & J_LEFT) { x = -1;}
    else if (joypad() & J_RIGHT ) { x = 1; }
    else { x = 0; }

    v[0] = y;
    v[1] = x;

    if (v[0] == -1 && v[1] == 0) {
        // UP
        player_speed = SPEED;
    } else if (v[0] == -1 && v[1] == 1) {
        // UP-RIGHT
        player_speed = NORM_SPEED;
    } else if (v[0] == 0 && v[1] == 1) {
        // RIGHT
        player_speed = SPEED;
    } else if (v[0] == 1 && v[1] == 1) {
        // DOWN-RIGHT
        player_speed = NORM_SPEED;
    } else if (v[0] == 1 && v[1] == 0) {
        // DOWN
        player_speed = SPEED;
    } else if (v[0] == 1 && v[1] == -1) {
        // DOWN-LEFT
        player_speed = NORM_SPEED;
    } else if (v[0] == 0 && v[1] == -1) {
        // LEFT
        player_speed = SPEED;
    } else if (v[0] == -1 && v[1] == -1) {
        // UP-LEFT
        player_speed = NORM_SPEED;
    }


    player.y += v[0] * player_speed;
    player.x += v[1] * player_speed;

}