/*
 * 	DungeonController.cpp
 *
 *  Created on: 21 Mar 2024
 *  Author: shehryarrashid
 */

#include <iostream>
#include <random>
#include "DungeonController.h"


DungeonController::DungeonController(string playerName, string description) {

	monk = new Monk(playerName,description);

	util = new Util;

	util->clearLogs();
	util->log("Monk has been spawn: " + playerName);
	util->log("Monk's description: " + description);


	EmptyRoom *spawnRoom = new EmptyRoom(nullptr);
	spawnRoom->Generate(util->getRandomIndex(1, 100));
	spawnRoom->Render();
	currentRoom = spawnRoom;
	ExploreEmptyRoom();
}

void DungeonController::printDungeon(){
	std::cout << "           _____________________________________________" << std::endl;
	    std::cout << "          |.'',                                     ,''.|" << std::endl;
	    std::cout << "          |.'.'',                                 ,''.'.|" << std::endl;
	    std::cout << "          |.'.'.'',                             ,''.'.'.|" << std::endl;
	    std::cout << "          |.'.'.'.'',                         ,''.'.'.'.|" << std::endl;
	    std::cout << "          |.'.'.'.'.|                         |.'.'.'.'.|" << std::endl;
	    std::cout << "          |.'.'.'.'.|===;                 ;===|.'.'.'.'.|" << std::endl;
	    std::cout << "          |.'.'.'.'.|:::|',             ,'|:::|.'.'.'.'.|" << std::endl;
	    std::cout << "          |.'.'.'.'.|---|'.|, _______ ,|.'|---|.'.'.'.'.|" << std::endl;
	    std::cout << "          |.'.'.'.'.|:::|'.|'|???????|'|.'|:::|.'.'.'.'.|" << std::endl;
	    std::cout << "          |,',',',',|---|',|'|???????|'|,'|---|,',',',',|" << std::endl;
	    std::cout << "          |.'.'.'.'.|:::|'.|'|???????|'|.'|:::|.'.'.'.'.|" << std::endl;
	    std::cout << "          |.'.'.'.'.|---|','   /%%%\\   ','|---|.'.'.'.'.|" << std::endl;
	    std::cout << "          |.'.'.'.'.|===:'    /%%%%%\\    ':===|.'.'.'.'.|" << std::endl;
	    std::cout << "          |.'.'.'.'.|%%%%%%%%%%%%%%%%%%%%%%%%%|.'.'.'.'.|" << std::endl;
	    std::cout << "          |.'.'.'.','       /%%%%%%%%%\\       ','.'.'.'.|" << std::endl;
	    std::cout << "          |.'.'.','        /%%%%%%%%%%%\\        ','.'.'.|" << std::endl;
	    std::cout << "          |.'.','         /%%%%%%%%%%%%%\\         ','.'.|" << std::endl;
	    std::cout << "          |.','          /%%%%%%%%%%%%%%%\\          ','.|" << std::endl;
	    std::cout << "          |;____________/%%%%%      %%%%%%\\____________;|\n" << std::endl;

}


void DungeonController::GenerateRoom(Room *sender, string direction) {

	roomsExplored += 1;

	cout << monk->getName() << " The Monk has explored ";
	printf("%d room(s) in the dungeon. \n", roomsExplored);

	/*
	 Set the chance of finding a treasure gradually higher, and the chance of finding an empty room to heal lower.
	 This behaviour should encourage an end-game. Whether it be defeat due to a lower chance of healing, or win if
	 the treasure room is found. This prevents the game from running for too long.
	 */

	if (roomsExplored > 10) {
		treasureChance = 10;
		emptyChance = 15;
		monsterChance = 45;
		util->log("Player successfully explored more than 10 rooms");
	}else if (roomsExplored > 3){
		treasureChance = 5;
		util->log("Player successfully explored more than 3 rooms");
	}

	int roomId = randomRoomId();
	Room *newRoom;
	util->log("Generating new room...");

	switch (roomId) {
	default:
	case (0):

		newRoom = new EmptyRoom(sender);
		newRoom->Generate(util->getRandomIndex(1, 100));
		newRoom->Render();

		if (direction == "0")
			currentRoom->setLeftRoom(newRoom);
		else
			currentRoom->setRightRoom(newRoom);

		currentRoom = newRoom;
		util->log("Generated new Empty room");
		ExploreEmptyRoom();
		break;
	case (1): {

		newRoom = new MonsterRoom(sender);
		newRoom->Generate(util->getRandomIndex(0, 2));
		newRoom->Render();

		if (direction == "0")
			currentRoom->setLeftRoom(newRoom);
		else
			currentRoom->setRightRoom(newRoom);

		currentRoom = newRoom;
		util->log("Generated new Monster room");
		BeginCombat();
		break;
	}
	case (2): {

		TreasureRoom *treasureRoom = new TreasureRoom(sender);
		treasureRoom->Generate();

		if (direction == "0")
			currentRoom->setLeftRoom(treasureRoom);
		else
			currentRoom->setRightRoom(treasureRoom);

		currentRoom = treasureRoom;
		treasureRoom->Render(monk->getName());
		util->log("Generated Treasure room!");
		break;
	}
	}
}


/**
 * Generate a random room ID.
 * 0 = Empty Room
 * 1 = Monster Room
 * 2 = Treasure Room
 *
 * @return The room ID which was generated here.
 */

int DungeonController::randomRoomId() {

	util->log("Choosing a random room ID from the percentage chances");

	int roomChance = util->getRandomIndex(1, 100);

	if (roomChance < treasureChance) {
		return 2;
	} else if (roomChance < emptyChance) {
		return 0;
	} else {
		return 1;
	}
}

// Function To Control Combat Functionality

void DungeonController::BeginCombat() {
	int turn = 0;

	MonsterRoom *room = (MonsterRoom*) currentRoom;

	while (room->isMonsterAlive()) {

		printf("The monster's health is currently: [%d / %d]\n",
				room->getMonsterHealth(), room->getMonsterBaseHealth());

		printf("The Monk's Health is currently: [%d / %d]\n",
				 monk->getHealth(),
				 monk->getBaseHealth());


		if (turn == 0) {
			string instruction = "2";

			while (instruction != "0" && instruction != "1") {
				cout << "What will the Monk do? \n [0] = Attack \n [1] = Defend\n";
				cin >> instruction;

				if (instruction != "0" && instruction != "1") {
					cout << "Enter a valid instruction!" << endl;
				}
			}

			if (instruction == "0"){
				CombatTryAttack(room, turn);
			}
			else{
				CombatTryDefend(room, turn);
			}

			turn = 1; // Set the turn to the monster.
		} else {

			if (room->monsterActionToPerform() == 0) {
				CombatTryAttack(room, turn);
			} else {
				CombatTryDefend(room, turn);
			}
			if (room->monsterTryAction()) { // Tries to attack or defend

			}
			turn = 0; // Set the turn back to the player.
		}

	}

	// The Monster has been defeated, allow the player to move on.
	cout << "The " << room->getMonsterName() << " was defeated by "
			<< monk->getName()
			<< " The Monk! \n The Monk moves on to the next room..." << endl;
	util->log("DEFEAT: Monster was defeated by player");

	MoveRoom();
}

void DungeonController::ExploreEmptyRoom() {
	// Initialise the instruction to something other than the supported options, to enter the while loop
	string instruction = "2";

	// Keep asking the player for the correct instruction. Break out of the loop when it's a 0 or 1.
	while (instruction != "0" && instruction != "1") {
		cout << "\n What would you like to do? \n [0] = pray \n [1] = move on"
				<< endl;
		cin >> instruction;
		if (instruction != "0" && instruction != "1") {
			cout << "Input unrecognised :( " << endl;
		}
	}

	if (instruction == "0") {

		monk->setHealth(monk->getBaseHealth());
		util->log("Player prayed in empty room: restoring health");
		printf(
				"Naturally, you sit inside the demonic-looking summoning circle. You're now full health! [%d / %d] \n",
				monk->getHealth(),
				monk->getBaseHealth());
	}

	// Cast the current room to an EmptyRoom object.
	EmptyRoom *room = (EmptyRoom*) currentRoom;

	if (room->hasItem) {
		cout << "As " << monk->getName() << " walks forward, he sees a glisten in front of him." << endl;

		util->log("Generated item inside current room");

		instruction = "2";

		while (instruction != "0" && instruction != "1") {

			cout << " What do you do? \n [0] = Pick Up \n [1] = Ignore" << endl;

			cin >> instruction;

			if (instruction != "0" && instruction != "1")
				cout << "Invalid Instruction!!! The Monk didn't understand that!" << endl;
		}

		if (instruction == "0") {
			if (util->getRandomIndex(1, 100) < 21) {

				util->log("ITEM: Staff of Protection");

				cout << "You approach the item and pick it up... It's a Staff of Protection! \n "
						"During your next combat, the Staff of Protection will block the first attack."
						<< endl;

				monk->setPlayerProtection(true);

			} else {
				util->log("ITEM: sewing needle; subtracting player health");
				cout
						<< "You approach the item and pick it up... OUCH! It was a sewing needle! \n "
							"You lose 1 HP. :( " << endl;

				monk->subtractHealth(1);
			}
		}
	}

	cout << monk->getName()
			<< " the Monk moves on to the next room..." << endl;
	MoveRoom();
}

void DungeonController::MoveRoom() {
	string direction = "_";

	// which direction will the player go?
	while (direction != "0" && direction != "1") {
		this->printDungeon();
		cout << "Which way does " <<   monk->getName()
				<< " go?\n [0] = Left \n [1] = Right \n";
		cin >> direction;
		if (direction != "0" && direction != "1") {

			cout << "The Monk realises this isn't a direction..." << endl;

		}
	}
	GenerateRoom(currentRoom, direction);
}

void DungeonController::CombatTryAttack(MonsterRoom *room, int turn) {

	if (turn == 0) {
		if ( monk->tryAction()) {

			cout << monk->getName() << " the Monk attacks the " << room->getMonsterName() << "!" << endl;

			room->subtractMonsterHealth(monk->getDamage());

		} else {
			cout << "The " << room->getMonsterName() << " dodged "
					<< monk->getName() << "'s attack!"
					<< endl;
		}
	} else {
		if (room->monsterTryAction()) {

			if (monk->getPlayerProtection()) {

				cout << "\n The " << room->getMonsterName()
						<< " tried to attack, but the Staff of Protection blocked the attack from the "
						<< room->getMonsterName() << "!" << endl;

				monk->setPlayerProtection(false);

			} else {
				cout << "\nThe " << room->getMonsterName() << " strikes "
						<< monk->getName() << " the Monk!" << endl;

				monk->subtractHealth(room->getMonsterAttackPoints());
			}
		} else {
			cout << "\nThe " << room->getMonsterName() << " failed to attack "
					<< monk->getName() << " the Monk!"
					<< endl;

		}
	}
}

void DungeonController::CombatTryDefend(MonsterRoom *room, int turn) {
	if (turn == 0) {
		if (monk->tryAction()) {
			cout << endl;
			cout << monk->getName()
					<< " the Monk defends themselves against the monster, restoring 1 HP."
					<< endl;

			// If the player does not have max health, increase it by 1. Otherwise, move on.
			if (monk->getHealth() != monk->getBaseHealth())

				monk->setHealth(monk->getHealth() + 1);


		} else {
			cout << endl;
			cout << monk->getName()
					<< " the Monk failed to defend against the " << room->getMonsterName() << endl;

			cout << "The " << room->getMonsterName() << " dealt ";
			printf("%d damage!\n", room->getMonsterAttackPoints());


			monk->subtractHealth(room->getMonsterAttackPoints());
		}
	} else {
		if (room->monsterTryAction()) {
			if (room->getMonsterHealth() != room->getMonsterBaseHealth()) {

				room->setMonsterHealth(room->getMonsterHealth() + 1);

				cout << "\nThe " << room->getMonsterName() << " defended against " <<  monk->getName()
					 << " the Monk and gained +1 health." << endl;


			} else {

				cout << "\nThe " << room->getMonsterName() << " defended itself, but was already full health." << endl;

			}
		} else {
			room->subtractMonsterHealth(monk->getDamage());

			cout << "\nThe " << room->getMonsterName()
				 << " failed to defend itself, and " <<  monk->getName() << " exploited this!" << endl;

		}
	}
}
