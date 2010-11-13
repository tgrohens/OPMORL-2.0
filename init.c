/*
 *  init.c
 *  OPMORL 2
 *
 *  Created by Théotime Grohens on 13/11/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

/* Various initialization functions */

#include "opmorl.h"

void init_ncurses() {
	initscr();
	raw();
	keypad(stdscr, TRUE);
	noecho();
}

void exit_ncurses() {
	endwin();
}