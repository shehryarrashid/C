/*
 *  Util.h
 *
 *  Created on: 2 Apr 2024
 *  Author: shehryarrashid
 */

#ifndef CONTROLLERS_UTIL_H_
#define CONTROLLERS_UTIL_H_

#include <iostream>
#include <random>
#include <string>
#include <fstream>
#include <ncurses.h>


using namespace std;

class Util {
private:

	random_device rd;

public:

	int getRandomIndex(int, int);

	void log(string log);
	void clearLogs() {
		clearLogs(false);
	}

	// Calls itself with false; giving a default action to keep the file if no parameter is given
	void clearLogs(bool deleteFile);


};

#endif /* CONTROLLERS_UTIL_H_ */
