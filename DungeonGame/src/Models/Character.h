/*
 * Character.h
 *
 *  Created on: 9 Apr 2024
 *      Author: shehryarrashid
 */

#ifndef MODELS_CHARACTER_H_
#define MODELS_CHARACTER_H_

#include "../Controllers/Util.h"

class Character
{

public:
	// Constructor for Monk
	Character(string , string);

	// Constructor for Monsters
	Character();

	virtual ~Character();

	int getDamage() const {
		return damage;
	}

	void setDamage(int damage) {
		this->damage = damage;
	}

	const string& getDescription() const {
		return description;
	}

	void setDescription(const string &description) {
		this->description = description;
	}

	int getHealth() const {
		return health;
	}

	void setHealth(int health) {
		this->health = health;
	}

	void subtractHealth(int amount) {
			health -= amount;
	}

	const string& getName() const {
		return name;
	}

	void setName(const string &name) {
		this->name = name;
	}

	const int getBaseHealth() const {
		return BASE_HEALTH;
	}

	bool tryAction();

	const Util& getUtil() const {
		return util;
	}

private:


	string name;
	string description;
	int health;
	int damage;
	Util util;

protected:

	int BASE_HEALTH;
	int BASE_DAMAGE;

};

#endif /* MODELS_CHARACTER_H_ */
