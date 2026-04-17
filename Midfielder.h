#pragma once
#include "Player.h"

class Midfielder : public Player
{
public:
    Midfielder(string n, int num, int s) : Player(n, num, s) {}

    void display() const override
    {
        cout << "[MID] " << name << " (#" << number << ") Skill: " << skill << endl;
    }
};