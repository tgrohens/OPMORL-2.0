/*
 *  init.c
 *  OPMORL 2
 *
 *  Created by Théotime Grohens on 13/11/10.
 *  Copyright 2010 OPMORL 2 dev team. All rights reserved.
 *
 */

/* Various initialization functions */

#include "opmorl.h"

void init_ncurses() {
	initscr();
	raw();
	keypad(stdscr, TRUE);
	noecho();
	start_color();
	mvprintw(11, 30, "Welcome to OPMORL 2.0");
	/* Color stuff */
	init_pair(RODNEY_COLOR, 7, 0);
}

void exit_ncurses() {
	endwin();
}


void exit_game() {
	
}