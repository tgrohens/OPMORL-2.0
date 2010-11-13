/*
 *  opmorl.c
 *  OPMORL 2
 *
 *  Created by Théotime Grohens on 13/11/10.
 *  Copyright 2010 OPMORL 2 dev group. All rights reserved.
 *
 */

#include "opmorl.h"

int main(void) {
	init_ncurses();
	attron(A_BLINK);
	printw("hello");
	box(stdscr, 3, 8);
	getch();
	exit_ncurses();
	return 0;
}