/*
 * 	TreasureRoom.h
 *
 *
 *  Created on: 21 Mar 2024
 *  Author: shehryarrashid
 */

#ifndef MONKASSIGNMENT_TREASUREROOM_H
#define MONKASSIGNMENT_TREASUREROOM_H

#include "../Models/Room.h"

class TreasureRoom: public Room {
public:
	TreasureRoom(Room*);

	void Generate() override;

	void Render(string) override;

	bool isTreasureRoom() override {
		return true;
	}
	; // Tells the manager of the Room class that this is the treasure subclass.

	bool isTreasureCollected;

	void TreasureCollected(string);

	virtual ~TreasureRoom(){};

};

#endif //MONKASSIGNMENT_TREASUREROOM_H
