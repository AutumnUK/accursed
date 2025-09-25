// Enemy struct
// Define a general enemy init
// Define specific enemy init
// Define patterns that can be used by a specific enemy

#include <gb/gb.h>
#include "../include/units.h"

#define SKULL_SPRITE_TILE   3
#define MAX_SCREEN_X        160
#define MAX_SCREEN_Y        144
#define ENEMY_COUNT         20

struct	Enemy 	            skulls[ENEMY_COUNT];

void moveEnemy(struct Enemy * m)		{ move_sprite( m-> id , m -> x , m -> y); }
void activateEnemy(struct Enemy * m)	{ m -> active = 1; }
void deactivateEnemy(struct Enemy * m)	{ m -> active = 0; }
void goToNode(struct Enemy * m, struct Node * n) {
    if ( m -> x > n -> x) { m -> x --; }    // If monster x > node x. Mode left.
    if ( m -> x < n -> x) { m -> x ++; }    // If monster x < ndoe x. Move right.
    if ( m -> y > n -> y) { m -> y --; }    // If monster y > node y. Move up.
    if ( m -> y < n -> y) { m -> y ++; }    // If monster y < node y. Move down.
}

void enemyInit(struct Enemy * m, uint8_t id, uint8_t x, uint8_t y, uint8_t sprite, uint8_t hp) {
    m -> active 		=	1;
    m -> x      		=	x;
    m -> startx 		=	x;
    m -> y      		=	y;
    m -> starty 		=	y;
    m -> id     		=	id;
	m -> currentNode 	= 	0;
    m -> health         =   hp;
    set_sprite_tile(m -> id , sprite);
}

void enemyUpdate(struct Enemy * m) {

	if ( m -> active) { 
		moveEnemy(m);
		if ( m -> x == m -> node[ m -> currentNode ].x && m -> y == m -> node [ m -> currentNode ].y) { m -> currentNode ++; }
		goToNode (m, & m -> node[m -> currentNode]);
		if (m -> currentNode == 4) { m -> active = 0; }

	}
	
	if ( m -> active == 0 ) {
		m -> x = 0;
		m -> y = 0;
		moveEnemy(m);
	}
}


//  Patterns
void homingPattern(struct Enemy * m) {
    m -> node[0].x = m -> x;
    m -> node[0].y = m -> y;  
}

void squarePattern(struct Enemy * m, uint8_t distance) {	
    m -> node[0].x = m -> startx;                   m -> node[0].y = m -> starty;                   // Start
    m -> node[1].x = m -> node[0].x -= distance;    m -> node[1].y = m -> node[0].y;                // Move Left
    m -> node[2].x = m -> node[1].x;                m -> node[2].y = m -> node[1].y += distance;    // Move Down
    m -> node[3].x = m -> node[2].x += distance;    m -> node[3].y = m -> node[2].y;                // Move Right
}

void squarePatternR(struct Enemy * m, uint8_t distance) {	
    m -> node[0].x = m -> startx;                   m -> node[0].y = m -> starty;                   // Start
    m -> node[1].x = m -> node[0].x -= distance;    m -> node[1].y = m -> node[0].y;                // Move Left
    m -> node[2].x = m -> node[1].x;                m -> node[2].y = m -> node[1].y -= distance;    // Move Up
    m -> node[3].x = m -> node[2].x += distance;    m -> node[3].y = m -> node[2].y;                // Move Right
}