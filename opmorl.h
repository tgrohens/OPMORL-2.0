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

#define COLOR

#ifdef COLOR
#define RODNEY_COLOR 1
#define DEFAULT_BACKCOLOR -1
#define DEFAULT_FORECOLOR -1
#endif

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
	
	int color; /* to be used with COLOR_PAIR(color) */
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
	int color; /* to be used with COLOR_PAIR(color) */
} Monster;

typedef enum {
	T_WALL, T_CORRIDOR, T_DOOR, T_FLOOR, T_STAIRS
} Tiletype;

typedef enum {
	C_SAMURAI, C_WARRIOR, C_ARCHER
} PClass;

typedef enum {
	R_HUMAN, R_ELF, R_GNOME
} Race;

typedef struct Player {
	PClass pclass;
	Race race;
	int posx, posy; /* Position */
	int explevel, exp; /* Experience stuff */
	int hp, max_hp;
	
	int dexterity, strength, constitution, intelligence, wisdom, charisma; /* Stats */
	
	Object inventory[52];
	int gold;
} Player;

/* Prototypes */

void init_ncurses();
void init_game();
void init_colors();
void game_loop();
void exit_game();
void exit_ncurses();

void create_lvl();

void get_input();

int pline(char *, int);
void display_everything();
void display_map();

int rand_int(int, int);

void move_rodney(int, int);

/* Globals */

Tiletype lvl_map[21][80];
Player rodney;