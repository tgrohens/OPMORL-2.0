/*
 *  opmorl.c
 *  OPMORL 2
 *
 *  Created by Théotime Grohens on 13/11/10.
 *  Copyright 2010 OPMORL 2 dev team. All rights reserved.
 *
 */

#include "opmorl.h"

#define init_game()
#define exit_game()

int main(void) {
	init_ncurses();
	init_game();
	game_loop();
	exit_game();
	exit_ncurses();
	return 0;
}

void game_loop() {
	display_map();
	getch();
}