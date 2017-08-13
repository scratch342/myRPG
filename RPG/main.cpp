#include <iostream>
#include "player.h"
#include "opponent.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#include <string>

using namespace std;

enum Options{
    ATTACK = 1,
    SPECIAL_ATTACK = 2,
    GAIN_HP = 3,
    GAIN_SPECIAL = 4
};

Options options(Player myPlayer){

    sleep(3);
    cout << myPlayer << endl << endl;

    sleep(3);
    cout << "You have 4 options : " << endl;
    cout << "1. Attack" << endl;
    cout << "2. Special Attack" << endl;
    cout << "3. Gain HP " << endl;
    cout << "4. Gain Special " << endl;

    int userInput;
    cin >> userInput;
    cin.sync();

    Options choice = static_cast<Options>(userInput);
    return choice;
}

Options options(Opponent opponent){
    cout << opponent << endl << endl;

    sleep(3);
    cout << "1. Attack" << endl;
    cout << "2. Special Attack" << endl;
    cout << "3. Gain HP " << endl;
    cout << "4. Gain Special " << endl;

    srand(time(NULL));

    int choice1 = rand() % 4 + 1;

    Options choice = static_cast<Options>(choice1);

    sleep(3);
    cout << "Computer has chosen " << choice1 << endl << endl << endl;

    return choice;
}

void check(Options choice, Player &player, Opponent &opponent){
    switch(choice){
        case ATTACK:
            opponent.hp -= 200;
            sleep(3);
            break;
        case SPECIAL_ATTACK:
            if(player.special >= 5){
                opponent.hp -= 300;
                player.special -= 5;
            }else{
                cout << "Not enough special!" << endl;
            }
            sleep(3);
            break;
        case GAIN_HP:
            player.gainHp();
            cout << player << endl;
            sleep(3);
            break;
        case GAIN_SPECIAL:
            player.gainSpecial();
            cout << player << endl;
            sleep(3);
            break;
    }
}
void check(Options choice, Player &player, Opponent &opponent, int i){
    switch(choice){
        case ATTACK:
            player.hp -= 200;
            sleep(3);
            break;
        case SPECIAL_ATTACK:
            if(opponent.special >= 5){
                player.hp -= 300;
                opponent.special -= 5;
            }else{
                cout << "Not enough special!" << endl;
            }
            sleep(3);
            break;
        case GAIN_HP:
            opponent.gainHp();
            cout << opponent << endl;
            sleep(3);
            break;
        case GAIN_SPECIAL:
            opponent.gainSpecial();
            cout << opponent << endl;
            sleep(3);
            break;
    }
}

void move(Player &player, Opponent &opponent){
    static int s_turn = 0;

    if(s_turn == 0){
        cout << endl;
        Options choice = options(player);
        check(choice, player, opponent);
        s_turn = 1;
        if(player.hp > 0 && opponent.hp > 0){
            move(player, opponent);
        }else{
            if(opponent.hp <= 0){
                cout << "Player wins!" << endl;
            }else if(player.hp <= 0){
                cout << "Opponent wins!" << endl;
            }
        }
    }else{
        cout << endl;
        Options choice = options(opponent);
        check(choice, player, opponent, 1);
        s_turn = 0;

        if(player.hp > 0 && opponent.hp > 0){
            move(player, opponent);
        }else{
            if(opponent.hp <= 0){
                cout << "Player wins!" << endl;
            }else if(player.hp <= 0){
                cout << "Opponent wins!" << endl;
            }
        }
    }

}

int main()
{

    cout << "Welcome to an RPG! Please enter your first name : ";
    string userName;
    getline(cin, userName);

    cin.sync();

    Player myPlayer(1000, userName, 10);
    Opponent opponent(1000, "Opponent 1", 10);

    move(myPlayer, opponent);

    return 0;
}
