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
#include <ncurses.h>

/* Structs */

extern enum Otype; /* Object type */
extern struct Object;

extern enum Mtype; /* Monster type */
extern struct Monster;

/* Prototypes */

void init_ncurses();
void exit_ncurses();

int pline(char *);