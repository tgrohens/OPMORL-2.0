/*
 *  pline.c
 *  OPMORL 2
 *
 *  Created by Théotime Grohens on 13/11/10.
 *  Copyright 2010 OPMORL dev team. All rights reserved.
 *
 */

/* Print a line on top of the terminal */

#include "opmorl.h"

int pline(char * str) { /* Not yet with varargs, to be implemented later */ /* This blocks until everything has been displayed */
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