/*
 * 	Room.cpp
 *
 *
 *  Created on: 25 Mar 2024
 *  Author: shehryarrashid
 */

#include "Room.h"

Room::Room(Room *sender) {
	setEnteredFrom(sender);
}

void Room::setEnteredFrom(Room *previousRoom) {
	enteredFrom = previousRoom;
}

Room* Room::getLeftRoom() {
	return leftDoor;
}

Room* Room::getRightRoom() {
	return rightDoor;
}

void Room::setLeftRoom(Room *left) {
	leftDoor = left;
}

void Room::setRightRoom(Room *right) {
	rightDoor = right;
}
