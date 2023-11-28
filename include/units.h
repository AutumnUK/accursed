#ifndef UNITS_H
#define UNITS_H

#include <gb/gb.h>

#define NODES 4

struct Node {
    uint8_t x,
            y;
};

struct Enemy {
    uint8_t x,
            startx,
            y,
            starty,
            id,
			currentNode,
            health;

    BOOLEAN active;

    struct 	Node node[NODES];
};

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