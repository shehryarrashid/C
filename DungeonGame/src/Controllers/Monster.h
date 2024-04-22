/*
 * Monster.h
 *
 *  Created on: 9 Apr 2024
 *      Author: shehryarrashid
 */

#ifndef CONTROLLERS_MONSTER_H_
#define CONTROLLERS_MONSTER_H_
#include "../Models/Character.h"
#include "Util.h"


class Monster : public Character {

public:

	Monster(int);

	int actionToPerform();

	virtual ~Monster();

	int getAttackChance() const {
		return attackChance;
	}

	void setAttackChance(int attackChance) {
		this->attackChance = attackChance;
	}

	int getDefendChance() const {
		return defendChance;
	}

	void setDefendChance(int defendChance) {
		this->defendChance = defendChance;
	}

	const string& getDisplay() const {
		return display;
	}

	void setDisplay(const string &display) {
		this->display = display;
	}

private:

	Util util;
	string display;
	int attackChance;
	int defendChance;

	// Functions to create the monster
	void goblin();
	void vampire();
	void beast();

};

#endif /* CONTROLLERS_MONSTER_H_ */
