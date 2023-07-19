#ifndef PLAYER_H
#define PLAYER_H

#include <gb/gb.h>

struct Player {
    uint8_t x,
            y,
            id;
    BOOLEAN shooting;
};

struct PlayerBullet {
    uint8_t x,
            y,
            id,
            tile;

    BOOLEAN ready;
    
};
#endif