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
		case 'y':
			move_rodney(rodney.posx-1, rodney.posy-1);
			break;
		case 'u':
			move_rodney(rodney.posx+1, rodney.posy-1);
			break;
		case 'b':
			move_rodney(rodney.posx-1, rodney.posy+1);
			break;
		case 'n':
			move_rodney(rodney.posx+1, rodney.posy+1);
			break;

		case '>':
			go_down();
			break;
		case 'q': /* Need to rewrite it cleanly */
			exit_game();
			exit_ncurses();
			exit(0);
			break;

	}
}


void display_everything() {
	display_stats(); /* The stuff like health points, level et alii */
	display_map();
}

void display_map() {
	int i, j;
	Object *obj = o_list;
	Monster *mon = m_list;
	attron(COLOR_PAIR(DEFAULT));
	for (i = 1; i < 22; i++) { /* First line is reserved */
		for (j = 0; j < 80; j++) {
			switch (lvl_map[rodney.level][i-1][j]) {
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

void display_stats() {
	mvprintw(getmaxy(stdscr)-2, 0, "St:%d Dx:%d Co:%d In:%d Wi:%d Ch:%d", rodney.strength, rodney.dexterity, rodney.constitution, rodney.intelligence, rodney.wisdom, rodney.charisma);
	mvprintw(getmaxy(stdscr)-1, 0, "Dlvl:%d\t$:%d\tHP:%d(%d)", rodney.level+1, rodney.gold, rodney.hp, rodney.max_hp);
}