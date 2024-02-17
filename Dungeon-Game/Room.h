#ifndef Room_H
#define Room_H

using namespace std;
#include<vector>

enum TYPE{
    TREASURE,
    MONSTER,
    EMPTY
};


class Room
{
private:
    TYPE type;
    vector<Room> conn_rooms;
    
public:
    Room(TYPE, Room...);
    Room(TYPE);
    void connectRoom(Room*);
    ~Room();
};

#endif
