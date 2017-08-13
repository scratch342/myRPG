#ifndef OPPONENT_H
#define OPPONENT_H
#include <string>

using namespace std;

class Opponent{
private:
    string name;
public:
    int special;
    int hp;
    Opponent(int myHp, string myName, int mySpecial){
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

    friend ostream& operator<<(ostream &o, Opponent p){
        o << "| HP = " << p.hp << " | " << "| NAME = " << p.name << " | " << "| SPECIAL = " << p.special << " | " << "\t" << endl;
        return o;
    }
};

#endif // OPPONENT_H
