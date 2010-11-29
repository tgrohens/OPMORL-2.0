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
#ifdef COLOR
	init_colors();
#endif
}

void init_colors() {
	start_color();
	use_default_colors();
	init_pair(CLR_WHITE, COLOR_WHITE, DEFAULT_BACKCOLOR); /* broken by the enum, wtf */
	/* et aliis coloris */
}

void exit_ncurses() {
	endwin();
}


void exit_game() {
	mvprintw(0, 0, "Goodbye.");
	getch();
}