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
		case 'q':
			exit_game();
			exit_ncurses();
			exit(0);
			break;

	}
}

int pline(char * str) { /* CRAPPY */
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
		retval += pline(newStr);
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
/*	display_stats(); */ /* The stuff like health points, level et alii */
}

void display_map() {
	int i, j;
	Object *obj = o_list;
	Monster *mon = m_list;
	attron(COLOR_PAIR(DEFAULT));
	for (i = 1; i < 22; i++) { /* First line is reserved */
		for (j = 0; j < 80; j++) {
			switch (lvl_map[rodney.level-1][i-1][j]) {
				case T_CLOSED_DOOR:
					mvaddch(i, j, '+');
					break;
				case T_OPEN_DOOR:
					mvaddch(i, j, '-');
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

	attroff(COLOR_PAIR(DEFAULT));
	/* Objects */
	if (o_list)
		do {
			attron(COLOR_PAIR(obj->color));
			(void)mvaddch(obj->posy, obj->posx, obj->symbol);
			attroff(COLOR_PAIR(obj->color));
		} while ((obj = obj->next));
	
	/* Monsters */
	if (m_list)
		do {
			attron(COLOR_PAIR(mon->color));
			(void)mvaddch(mon->posy, mon->posx, mon->symbol);
			attroff(COLOR_PAIR(mon->color));
		} while ((mon = mon->next));
	
	/* Rodney */
	attron(COLOR_PAIR(rodney.color));
	attron(A_BOLD);
	(void)mvaddch(rodney.posy, rodney.posx, '@');
	attroff(A_BOLD);
	attroff(COLOR_PAIR(rodney.color));

	move(rodney.posy, rodney.posx);
}