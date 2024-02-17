#ifndef Dungeon_H
#define Dungeon_H

#include<vector>
#include "Room.h"

const int MAX_TREASURE_ROOMS = 1;

using namespace std;

class Dungeon
{
private:
    vector<Room> rooms;

public:

    Dungeon(/* args */);
    ~Dungeon();

};

#endif
