/*
 * 	MonsterRoom.h
 *
 *
 *  Created on: 25 Mar 2024
 *  Author: shehryarrashid
 */

#ifndef MONKASSIGNMENT_MONSTERROOM_H
#define MONKASSIGNMENT_MONSTERROOM_H

#include "../Models/Room.h"

#include "../Controllers/Monster.h"

class MonsterRoom: public Room {
public:

	MonsterRoom(Room*);

	void Generate(int) override;

	Monster* getMonster();

	void Render() override;

	bool isMonsterAlive();

	// Methods from the MonsterController

	int getMonsterHealth();

	int getMonsterBaseHealth();

	string getMonsterName();

	string getMonsterNoise();

	void setMonsterHealth(int value);

	void subtractMonsterHealth(int value);

	int getMonsterAttackPoints();

	bool monsterTryAction();

	int monsterActionToPerform();

	virtual ~MonsterRoom(){};

private:

	Monster *mons;
};

#endif //MONKASSIGNMENT_MONSTERROOM_H
