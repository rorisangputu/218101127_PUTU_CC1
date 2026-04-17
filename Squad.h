#pragma once
#include <vector>
#include "Player.h"
using namespace std;

class Squad
{
private:
    vector<Player *> players;
    string squadName;

public:
    Squad(string name);
    ~Squad();

    void addPlayer(Player *p);
    void displaySquad() const;
    Player *getPlayerByNumber(int number) const;
    int getSquadSize() const;
    bool numberExists(int number) const;
};