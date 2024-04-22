/*
 * Monk.h
 *
 *  Created on: 9 Apr 2024
 *      Author: shehryarrashid
 */

#ifndef CONTROLLERS_MONK_H_
#define CONTROLLERS_MONK_H_
#include "../Models/Character.h"


class Monk : public Character {
public:

	Monk(string, string);

	bool tryAction();
	void subtractHealth(int);
	void Die();


	virtual ~Monk();

	bool getPlayerProtection() const {
		return playerProtection;
	}

	void setPlayerProtection(bool toggle) {
		this->playerProtection = toggle;
	}

private:
	bool playerProtection;
};

#endif /* CONTROLLERS_MONK_H_ */
