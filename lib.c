/*
 *  lib.c
 *  OPMORL 2
 *
 *  Created by Théotime Grohens on 13/11/10.
 *  Copyright 2010 OPMORL 2 dev team. All rights reserved.
 *
 */

/* This includes chained list stuff */

#include "opmorl.h"

int rand_int(int min, int max) {
	return rand()%(max-min+1)+min;
}

void add_monster(Monster *mon) {
	Monster *list = m_list;
	if (list == NULL) {
		list = mon;
		return;
	}
	while (list->next != NULL)
		list = list->next;
	list->next = mon;
}

void add_object(Object *obj) {
	Object *list = o_list;
	if (list == NULL) {
		list = obj;
		return;
	}
	while (list->next != NULL)
		list = list->next;
	list->next = obj;
}

void rm_mon_at(int x, int y, int level) {
	Monster *mon = m_list;
	if (mon == NULL) {
		return;
	}
	if (mon->next == NULL) {
		if (mon->posx == x && mon->posy == y && mon->level == level) {
			free(mon), m_list = NULL;
		}
		return;
	}
	while (mon->next) {
		Monster *maybe = mon->next; /* I find it easier to read/debug (?) like that */
		if (maybe->posx == x && maybe->posy == y && maybe->level == level) {
			mon->next = maybe->next;
			free(maybe);
		}
	}
}

void rm_obj_at(int x, int y, int level) {
	Object *obj = m_list;
	if (obj == NULL) {
		return;
	}
	if (obj->next == NULL) {
		if (obj->posx == x && obj->posy == y && obj->level == level) {
			free(obj), o_list = NULL;
		}
		return;
	}
	while (obj->next) {
		Object *maybe = obj->next; /* I find it easier to read/debug (?) like that */
		if (maybe->posx == x && maybe->posy == y && maybe->level == level) {
			obj->next = maybe->next;
			free(maybe);
		}
	}
}