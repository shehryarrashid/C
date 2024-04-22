/*
 * Character.cpp
 *
 *  Created on: 9 Apr 2024
 *      Author: shehryarrashid
 */

#include "Character.h"


Character::Character(string name, string description) : BASE_HEALTH(15), BASE_DAMAGE(3){

	this->name = name;
	this->description = description;
	this->health = this->BASE_HEALTH;
	this->damage = this->BASE_DAMAGE;

}

Character::Character():BASE_HEALTH(0), BASE_DAMAGE(0){
	this->name = "";
	this->description = "";
	this->health = BASE_HEALTH;
	this->damage = BASE_DAMAGE;
}


/**
 * Try to complete an action, such as attacking or defending.
 * tryAction generates a number between 0 or 1, determining whether the action attempted was successful.
 * 0 = unsuccessful
 * 1 = successful
 *
 * @return Boolean of whether the action was successful or not.
 */


bool Character::tryAction(){
	return (util.getRandomIndex(0,1) == 1);
}

Character::~Character() {
	// TODO Auto-generated destructor stub
}

