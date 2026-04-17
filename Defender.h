#pragma once
#include "Player.h"

class Defender : public Player
{
public:
    Defender(string n, int num, int s) : Player(n, num, s) {}

    void display() const override
    {
        cout << "[DEF] " << name << " (#" << number << ") Skill: " << skill << endl;
    }
};