/*
 * 	Room.h
 *
 *
 *  Created on: 25 Mar 2024
 *  Author: shehryarrashid
 */
#pragma once

#ifndef MONKASSIGNMENT_ROOM_H
#define MONKASSIGNMENT_ROOM_H

#include <string>

using namespace std;

class Room {
public:

	Room();

	Room(Room*);

	virtual void Generate() {};

	virtual void setEnteredFrom(Room *previousRoom); // Set the exit to the previous room.

	virtual void Render() {
	};

	virtual void Render(string) {};

	virtual void Generate(int) {};

	virtual void setLeftRoom(Room *left);

	virtual void setRightRoom(Room *right);

	virtual Room* getLeftRoom();

	virtual Room* getRightRoom();

	virtual bool isTreasureRoom() {	return false;	}

	virtual ~Room(){};

private:
	Room *enteredFrom;
	Room *leftDoor;
	Room *rightDoor;
};


#endif //MONKASSIGNMENT_ROOM_H
