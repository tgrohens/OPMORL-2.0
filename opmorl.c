/*
 *  opmorl.c
 *  OPMORL 2
 *
 *  Created by Théotime Grohens on 13/11/10.
 *  Copyright 2010 OPMORL 2 dev team. All rights reserved.
 *
 */

#include "opmorl.h"

int main(void) {
	init_ncurses();	
	mvprintw(11, 30, "Welcome to OPMORL 2.0");
	init_game();
	game_loop();
	exit_game();
	exit_ncurses();
	return 0;
}

void game_loop() {
	while (1) {
		get_input();
		display_everything();
	}
}

void init_game() {
	rodney.pclass = C_WARRIOR;
	rodney.race = R_HUMAN;
	rodney.gold = rodney.exp = 0;
	rodney.explevel = 1;
	rodney.hp = rodney.max_hp = rand_int(12, 18);
	rodney.charisma = rand_int(12, 18);
	rodney.constitution = rand_int(12, 18);
	rodney.strength = rand_int(12, 18);
	rodney.dexterity = rand_int(12, 18);
	rodney.wisdom = rand_int(12, 18);
	rodney.posx = rand_int(1, 78);
	rodney.posy = rand_int(1, 19);
	create_lvl();
}