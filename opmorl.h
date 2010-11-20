/*
 *  opmorl.h
 *  OPMORL 2
 *
 *  Created by Théotime Grohens on 13/11/10.
 *  Copyright 2010 OPMORL 2 dev team. All rights reserved.
 *
 */

/* This header is to be included in every other file for now*/

/* Includes */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#ifdef _WIN32
#include <conio.h>
#else
#include <ncurses.h>
#endif

#define DEBUG

#define VERSION 0.01
#define STRING_V "OPMORL 2 prealpha"

/* Structs */

typedef enum {
	O_SWORD, O_SHIELD, O_POTION, O_WAND, O_RING, O_BODY_ARMOR, O_HELM, O_FOOD, O_SCROLL /* We are free not to implement all of them right now */
} Otype; /* Object type */

typedef struct Object {
	Otype type;
	
	char name[50];
	
	int is_gold; /* We treat this separately */
	int posx, posy, level; /* Coordinates : x, y, level (we want levels that remain) */
	int value; /* The monetary value for buying / selling the object */
	int damage; /* For everything that attacks, including wands */
	//	Effect effect; /* For potions */
	int shots_left; /* For wands */
	int flags; /* Such as invisible... */
} Object;

typedef enum {
	EMPTY, FOR, NOW
} Mtype; /* Monster type */

typedef struct Monster {
	Mtype type;
	
	char name[50];
	
	int posx, posy, level;
	int attack;
	int life_points;
	int flags; /* Such as invisible, flying ... */
} Monster;

typedef enum {
	T_WALL, T_CORRIDOR, T_DOOR, T_GROUND, T_STAIRS
} Tiletype;

/* Prototypes */

void init_ncurses();
void init_game();
void game_loop();
void exit_game();
void exit_ncurses();

void create_map();

int pline(char *);
void display_map();

/* Globals */

Tiletype map[21][80];