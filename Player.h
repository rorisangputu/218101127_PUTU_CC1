#pragma once
#include <iostream>
#include <string>
using namespace std;

class Player {
protected:
    string name;
    int number;
    int skill;

public:
    Player(string n, int num, int s) : name(n), number(num), skill(s) {}
    
    virtual void display() const = 0;
    
    int getSkill() const { return skill; }
    string getName() const { return name; }
    int getNumber() const { return number; }
    
    // Operator overloading - compare players by skill
    bool operator>(const Player& other) const { return skill > other.skill; }
    bool operator<(const Player& other) const { return skill < other.skill; }
    bool operator==(const Player& other) const { return skill == other.skill; }
    
    virtual ~Player() {}
};