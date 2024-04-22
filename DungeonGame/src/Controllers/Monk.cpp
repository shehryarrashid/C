/*
 * Monk.cpp
 *
 *  Created on: 9 Apr 2024
 *      Author: shehryarrashid
 */

#include "Monk.h"

Monk::Monk(string name, string description) : Character(name,description) {
	this->playerProtection = false;
}

bool Monk::tryAction(){
	Util util;
	return (util.getRandomIndex(0,1) == 1);
}

void Monk::subtractHealth(int value){
	this->setHealth(this->getHealth() - value);
	if(this->getHealth() <= 0){
		this->Die();
	}
}

void Monk::Die(){
	cout << endl << this->getName() << " died in battle! The treasure was never found..." << endl;
	exit(0);
}

Monk::~Monk() {

}

