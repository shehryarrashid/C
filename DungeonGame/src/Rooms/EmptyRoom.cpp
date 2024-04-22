/*
 * 	EmptyRoom.cpp
 *
 *  Created on: 21 Mar 2024
 *  Author: shehryarrashid
 */
#include <iostream>
#include <random>
#include "EmptyRoom.h"
using namespace std;

EmptyRoom::EmptyRoom(Room *sender) : Room(sender) {
	this->hasItem = false;
	this->hasPrayed = false;
}

void EmptyRoom::Generate(int itemChance) {
	this->hasPrayed = false;
	// Set hasItem to true if rngItemGen returns less than 20, therefore making an item a 20% chance.
	hasItem = (itemChance < 20);
}

void EmptyRoom::Render() {
		std::cout << "You entered an empty room!\n";
		std::cout << " ___________________________________" << std::endl;
	    for (int i = 0; i < 9; ++i) {
	        std::cout << "|                                   |" << std::endl;
	    }
	    std::cout << "|               ___                 |" << std::endl;
	    std::cout << "|              /   \\                |" << std::endl;
	    std::cout << "|             |     |               |" << std::endl;
	    std::cout << "|             |  _  |               |" << std::endl;
	    std::cout << "|             | / \\ |               |" << std::endl;
	    std::cout << "|             |/   \\|               |" << std::endl;
	    std::cout << "|              \\___/                |" << std::endl;
	    for (int i = 0; i < 9; ++i) {
	        std::cout << "|                                   |" << std::endl;
	    }
	    std::cout << "|___________________________________|\n" << std::endl;


}
