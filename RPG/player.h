#ifndef PLAYER_H
#define PLAYER_H

#include <string>

using namespace std;

class Player{
private:
    string name;
public:
    int special;
    int hp;
    Player(int myHp, string myName, int mySpecial){
        hp = myHp;
        name = myName;
        special = mySpecial;
    }
    string getName(){
        return name;
    }

    int getSpecial(){
        return special;
    }

    int gainHp(){
        hp += 100;
    }

    int gainSpecial(){
        special += 3;
    }

    friend ostream& operator<<(ostream &o, Player p){
        o << "| HP = " << p.hp << " | " << "| NAME = " << p.name << " | " << "| SPECIAL = " << p.special << " | " << "\t" << endl;
        return o;
    }
};

#endif // PLAYER_H
