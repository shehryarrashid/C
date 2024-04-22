/*
 * 	main.cpp
 *
 *
 *  Created on: 02 Mar 2024
 *  Author: shehryarrashid
 */

#include <iostream>
#include "Controllers/DungeonController.h"
#include "main.h"



int main() {

	string name, description;
	MainView *mainDungeon = new MainView();

	cout << "  ,--.     ,--.   ,--.,------.,--.    ,-----. ,-----. ,--.   ,--.,------.     ,--.  " << endl;
	cout << ",-'  '-.   |  |   |  ||  .---'|  |   '  .--./'  .-.  '|   `.'   ||  .---'   ,-'  '-." << endl;
	cout << "'-.  .-'   |  |.'.|  ||  `--, |  |   |  |    |  | |  ||  |'.'|  ||  `--,    '-.  .-'" << endl;
	cout << "  |  |     |   ,'.   ||  `---.|  '--.'  '--'\\'  '-'  '|  |   |  ||  `---.     |  |  " << endl;
	cout << "  `--'     '--'   '--'`------'`-----' `-----' `-----' `--'   `--'`------'     `--'  " << endl;


	mainDungeon->printDungeon();
	cout << "You're in a fractured reality. And a Dungeon! don't forget that. Once you advance through a door, there's no going back. Good luck... \n \nNow that's over, what's your name?\n";
	getline(cin, name);

	cout << "The powerful Monk has established his name " << " \nBut what's his story? \n";
	getline(cin, description);


	mainDungeon->startGame(name, description);
	return 0;
}


void MainView::startGame(string playerName, string description) {
	this->dungeonController = new DungeonController(playerName,description);

}

void MainView::printDungeon(){
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
