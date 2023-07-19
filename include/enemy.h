#ifndef ENEMY_H
#define ENEMY_H

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
			currentNode;

    BOOLEAN active;

    struct 	Node node[NODES];
};
#endif