/*
 *  pline.c
 *  OPMORL 2
 *
 *  Created by Théotime Grohens on 13/11/10.
 *  Copyright 2010 OPMORL 2 dev team. All rights reserved.
 *
 */

#include "opmorl.h"

void get_input() {
	char ch = getch();
	switch (ch) {
		case 'h':
			move_rodney(rodney.posx-1, rodney.posy);
			break;
		case 'j':
			move_rodney(rodney.posx, rodney.posy+1);
			break;
		case 'k':
			move_rodney(rodney.posx, rodney.posy-1);
			break;
		case 'l':
			move_rodney(rodney.posx+1, rodney.posy);
			break;
		case 'Q':
			exit_game();
			exit_ncurses();
			exit(0);
			break;

	}
}

int pline(char * str, int stuff_comes_after) { /* Not yet with varargs, to be implemented later */ /* This blocks until everything has been displayed */
	int len = strlen(str), termLen = getmaxx(stdscr), retval;
	if (len > termLen) {
		char *more = "--More--";
		int lenOk = len-1;
		while (str[lenOk] != ' ' && len-lenOk < 8) /* Here the bug */
			lenOk--;
		lenOk++;
		char *newStr = strdup(&str[lenOk]);
		str[lenOk-1] = '\0';
		retval = mvprintw(0, 0, strcat(str, more));
		while (getch() != '\n');
		retval += pline(newStr, 42);
		free(newStr);
	} else {
		char *fill = malloc(sizeof(char)*termLen+1);
		memset(fill, ' ', termLen);
		fill[termLen] = '\0';
		mvprintw(0, 0, fill);
		retval = mvprintw(0, 0, str);
	}
	return retval;
}

void display_everything() {
	display_map();
/*	display_stats(); */
}

void display_map() {
	int i, j;
	for (i = 1; i < 22; i++) { /* First line is reserved */
		for (j = 0; j < 80; j++) {
			switch (lvl_map[i-1][j]) {
				case T_DOOR:
					mvaddch(i, j, '+');
					break;
				case T_CORRIDOR:
					mvaddch(i, j, '=');
					break;
				case T_WALL:
					mvaddch(i, j, '#');
					break;
				case T_FLOOR:
					mvaddch(i, j, '.');
					break;
				case T_STAIRS:
					mvaddch(i, j, '>');
					break;

			}
		}
	}
	/* Then, print objects on top of this and then monsters */
	attron(COLOR_PAIR(1));
	attron(A_BOLD);
	mvaddch(rodney.posy, rodney.posx, '@');
	attroff(A_BOLD);
	attroff(COLOR_PAIR(1));
	move(rodney.posy, rodney.posx);
}