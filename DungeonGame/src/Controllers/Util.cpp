/*
 * 	Util.cpp
 *
 *  Created on: 2 Apr 2024
 *  Author: shehryarrashid
 */

#include "Util.h"

int Util::getRandomIndex(int from, int to) {
	static std::mt19937 eng(rd());
	std::uniform_int_distribution<> distr(from, to);

	return distr(eng);
}


/*
 * An easy interface to log any text into the log file.
 * Appends a new line to the log file with the log parameter.
 */
void Util::log(string log) {
	log += "\n";
	ofstream outputFile;
	outputFile.open("game_events.log", std::ios_base::app);
	outputFile << log;
}

/**
 * Clear the logs file.
 * Parameter deleteFile gives the option to fully delete the text file from the system.
 * If false, the file is cleared but kept on disk. If true, the file is deleted.
 *
 * As seen in the LogController.h Header File, if no parameter is given, it defaults to false and calls this method.
 */
void Util::clearLogs(bool deleteFile) {
	if (!deleteFile) {
		ofstream ofs;
		ofs.open("game_events.log", std::ofstream::out | std::ofstream::trunc);
		ofs.close();
	} else {
		const int deleteResult = remove("game_events.log");
		if (deleteResult != 0) {
			cout << "Failed to delete the log file" << endl;
		}
	}
}

