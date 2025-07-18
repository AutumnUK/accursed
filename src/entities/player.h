#ifndef PLAYER_H
#define PLAYER_H

#include "../headers.h"

struct Player {
    uint8_t x;
    uint8_t y;
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
#endif