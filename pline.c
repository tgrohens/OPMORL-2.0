/*
 *  pline.c
 *  OPMORL 2
 *
 *  Created by Théotime Grohens on 13/11/10.
 *  Copyright 2010 OPMORL dev team. All rights reserved.
 *
 */

/* Print a line on top of the terminal (see schema) */

#include "opmorl.h"

int find_spaces_backwards(char *str) {
	int len = strlen(str);
	int i;
	for (i = len-1; i >= 0; i--)
		if (str[i] == ' ')
			return i;
	return -1;
}

int pline(char * str) { /* Not yet with varargs, to be implemented later */
	int len = strlen(str);
	if (len >= getmaxx(stdscr)) {
		int lenOK = find_spaces_backwards(str);
		if (len-lenOK >= strlen("--More--")) {
			return mvprintw(0, 0, str);
		}
	}
	return 42; /* Temporary */
}