#ifndef Monk_H
#define Monk_H

#include <iostream>
#include <string>
#include "Room.h"

using namespace std;

class Monk
{
private:

    string name;
    string description;
    int health;
    int attack_points;
    Room current_room;

public:
    
    Monk(string, string);


    ~Monk();
};

#endif

