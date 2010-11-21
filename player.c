/*
 *  player.c
 *  OPMORL 2
 *
 *  Created by Théotime Grohens on 21/11/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "opmorl.h"

void move_rodney(int newx, int newy) {
	if (lvl_map[newy-1][newx] == T_WALL || lvl_map[newy][newx] == T_DOOR)
		return;
	rodney.posx = newx;
	rodney.posy = newy;
}