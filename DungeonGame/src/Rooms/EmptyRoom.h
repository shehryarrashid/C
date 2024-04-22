/*
 * 	EmptyRoom.h
 *
 *
 *  Created on: 25 Mar 2024
 *  Author: shehryarrashid
 */

#ifndef MONKASSIGNMENT_EMPTYROOM_H
#define MONKASSIGNMENT_EMPTYROOM_H


#include "../Models/Room.h"

class EmptyRoom: public Room {
public:

	EmptyRoom(Room*);
	void Generate(int) override;
	bool hasPrayed; // Has the player prayed in the room already? Default to false.
	bool hasItem;
	void Render() override;
	bool isTreasureRoom() override {
			return false;
	};
	virtual ~EmptyRoom(){};

};

#endif //MONKASSIGNMENT_EMPTYROOM_H
