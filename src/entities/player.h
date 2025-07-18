#ifndef PLAYER_H
#define PLAYER_H

#include "../headers.h"

struct Player {
    int x;
    int y;
    uint8_t id;
    BOOLEAN shooting;
};


struct PlayerBullet {
    uint8_t x,
            y,
            id,
            tile;

    BOOLEAN ready;
    
};

void player_init( void );
void player_movement( void );
#endif