/*
 * 	main.h
 *
 *
 *  Created on: 02 Mar 2024
 *  Author: shehryarrashid
 */


#ifndef MONKASSIGNMENT_MAIN_H
#define MONKASSIGNMENT_MAIN_H

#include <string>
#include "Controllers/DungeonController.h"
using namespace std;

class MainView {
public:
	void startGame(string playerName, string description);
	void printDungeon();

private:
	DungeonController *dungeonController;

};

#endif //MONKASSIGNMENT_MAIN_H
