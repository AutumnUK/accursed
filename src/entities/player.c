
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
    // replace this with a function that returns a value if I press an input/combination of inputs.
    switch (joypad()) {
        case J_UP:      player.y -= SPEED; break;
        case J_UP && J_RIGHT: player.y -= NORM_SPEED; break;
        case J_DOWN:    player.y += SPEED; break;
        case J_RIGHT:   player.x += SPEED; break;
        case J_LEFT:    player.x -= SPEED; break;
    }

    


    player.x += x;
    player.y += y;

}