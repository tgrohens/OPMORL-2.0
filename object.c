/*
 *  object.c
 *  OPMORL 2
 *
 *  Created by Théotime Grohens on 20/11/10.
 *  Copyright 2010 OPMORL 2 dev team. All rights reserved.
 *
 */

/* WE STILL HAVE TO CHOOSE HOW TO IMPLEMENT THE CHAINED LIST */

/* I think we should have a global chained list for objects + one for objects in rodney's inventory *
 * We'll see later whether monsters have objects too, and how we deal with it						*/

#include "opmorl.h"

typedef enum {
	O_SWORD, O_SHIELD, O_POTION, O_WAND, O_RING, O_BODY_ARMOR, O_HELM, O_FOOD /* We are free not to implement all of them right now */
} Otype;

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