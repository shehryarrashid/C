/*
 * 	MonsterRoom.cpp
 *
 *
 *  Created on: 25 Mar 2024
 *  Author: shehryarrashid
 */
#include <random>
#include <iostream>
#include <new>
#include "MonsterRoom.h"

MonsterRoom::MonsterRoom(Room *sender) : Room(sender) {
	mons = NULL;
}

void MonsterRoom::Generate(int monsterId) {
	mons = new Monster(monsterId);
}

Monster* MonsterRoom::getMonster() {
	return mons;
}

void MonsterRoom::Render() {

	cout << mons->getDisplay() << endl;
	cout << "You enter a dark room, you can hardly see. In front of you, you hear a " << mons->getDescription() << endl;
	cout << "It's a " << mons->getName() << "! The door behind you locks. The battle has already begun." << endl;
}

bool MonsterRoom::isMonsterAlive() {
	return (mons->getHealth() > 0);
}

int MonsterRoom::getMonsterHealth() {
	return mons->getHealth();
}

int MonsterRoom::getMonsterBaseHealth() {
	return mons->getBaseHealth();
}

string MonsterRoom::getMonsterName() {
	return mons->getName();
}

string MonsterRoom::getMonsterNoise() {
	return mons->getDescription();
}

void MonsterRoom::setMonsterHealth(int value) {
	mons->setHealth(value);
}

void MonsterRoom::subtractMonsterHealth(int value) {
	mons->subtractHealth(value);
}

int MonsterRoom::getMonsterAttackPoints() {
	return mons->getDamage();
}

bool MonsterRoom::monsterTryAction() {
	return mons->tryAction();
}

int MonsterRoom::monsterActionToPerform() {
	return mons->actionToPerform();
}




