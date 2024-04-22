/*
 * 	DungeonController.h
 *
 *  Created on: 21 Mar 2024
 *  Author: shehryarrashid
 */
#ifndef MONKASSIGNMENT_DUNGEONCONTROLLER_H
#define MONKASSIGNMENT_DUNGEONCONTROLLER_H

// Controller Dependencies

#include "Monster.h"
#include "Monk.h"


// Room Dependencies
#include "../Rooms/MonsterRoom.h"
#include "../Rooms/EmptyRoom.h"
#include "../Rooms/TreasureRoom.h"



#include "Util.h"

class DungeonController {
public:
	DungeonController(string playerName, string description);

	void increaseRoomCount() {
		roomsExplored++;
	}
	int getRoomCount() {
		return roomsExplored;
	}

	void GenerateRoom(Room*, string);
	void roomByID(int, Room*);
	void printDungeon();
	void BeginCombat();
	int  randomRoomId();
	void ExploreEmptyRoom();
	void MoveRoom();
	void CombatTryAttack(MonsterRoom*, int);
	void CombatTryDefend(MonsterRoom*, int);



private:

	Monk *monk;
	Util *util;

	int roomsExplored = 0;
	int treasureChance = -1;
	int emptyChance = 20;
	int monsterChance = 60;

	Room *currentRoom;
};

#endif //MONKASSIGNMENT_DUNGEONCONTROLLER_H
