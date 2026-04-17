#pragma once
#include "Player.h"

class Striker : public Player
{
public:
    Striker(string n, int num, int s) : Player(n, num, s) {}

    void display() const override
    {
        cout << "[ST] " << name << " (#" << number << ") Skill: " << skill << endl;
    }
};