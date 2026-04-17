#pragma once
#include "Player.h"

class Goalkeeper : public Player
{
public:
    Goalkeeper(string n, int num, int s) : Player(n, num, s) {}

    void display() const override
    {
        cout << "[GK] " << name << " (#" << number << ") Skill: " << skill << endl;
    }
};