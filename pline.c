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


/* Little bug here : "--More--" stuff doesn't go to the space and overlaps on the second line */

int pline(char * str) { /* Not yet with varargs, to be implemented later */ /* This blocks until everything has been displayed */
	int len = strlen(str);
	if (len > getmaxx(stdscr)) {
		char *more = "--More--";
		int lenOk = len-1;
		while (str[lenOk] != ' ' && len-lenOk < 8)
			lenOk--;
		char *newStr = strdup(&str[lenOk]);
		str[lenOk-1] = '\0';
		mvprintw(0, 0, strcat(str, more));
		while (getch() != '\n');
		pline(newStr);
		free(newStr);
	} else {
		char *fill = malloc(sizeof(char)*(getmaxx(stdscr)+1));
		memset(fill, ' ', getmaxx(stdscr));
		mvprintw(0, 0, fill);
		mvprintw(0, 0, str);
	}

	return 42; /* Temporary */
}