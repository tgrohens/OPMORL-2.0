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
	
	char str[] = "Hello ! I am the Lizard King !";
	
	pline(str);
	
	while (getch() != 'q');
	exit_ncurses();
	return 0;
}