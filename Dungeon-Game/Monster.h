#ifndef MONSTER_H
#define MONSTER_H

using namespace std;

enum MONSTER_TYPE{
    GOBLIN
};

class Monster
{
private:
    MONSTER_TYPE type;
    int health;
    int attack_points;
    
public:
    Monster(MONSTER_TYPE);
    ~Monster();
};





#endif