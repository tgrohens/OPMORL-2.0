/*
 *  monster.c
 *  OPMORL 2
 *
 *  Created by Théotime Grohens on 20/11/10.
 *  Copyright 2010 OPMORL 2 dev team. All rights reserved.
 *
 */

/* Same remarks apply for monsters that the ones in object.c */

typedef enum {
	EMPTY, FOR, NOW
} Mtype;

typedef struct Monster {
	Mtype type;
	
	char name[50];
	
	int posx, posy, level;
	int attack;
	int life_points;
	int flags; /* Such as invisible, flying ... */
} Monster;