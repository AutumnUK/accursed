
#include "../headers.h"

#define MIN_X   8
#define MAX_X   160
#define MIN_Y   16
#define MAX_Y   136


struct Player player;

void player_init(void) {
    player.x    = 50;
    player.y    = 50;
    player.id   = 20;
    move_sprite( player.id , player.x , player.y );
    set_sprite_tile(player.id,1);
}