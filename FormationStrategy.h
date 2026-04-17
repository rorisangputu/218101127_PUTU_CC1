#pragma once
#include <iostream>
using namespace std;

class FormationStrategy
{
public:
    virtual void apply() const = 0;
    virtual string getName() const = 0;
    virtual ~FormationStrategy() {}
};

class FourFourTwo : public FormationStrategy
{
public:
    void apply() const override
    {
        cout << "Applying 4-4-2 formation: Balanced attack and defence." << endl;
    }
    string getName() const override { return "4-4-2"; }
};

class FourThreeThree : public FormationStrategy
{
public:
    void apply() const override
    {
        cout << "Applying 4-3-3 formation: Aggressive attacking play." << endl;
    }
    string getName() const override { return "4-3-3"; }
};

class FourTwoTwoTwo : public FormationStrategy
{
public:
    void apply() const override
    {
        cout << "Applying 4-2-2-2 formation: Gegenpress attacking." << endl;
    }
    string getName() const override { return "4-2-2-2"; }
};

class ThreeFiveTwo : public FormationStrategy
{
public:
    void apply() const override
    {
        cout << "Applying 3-5-2 formation: Overloading Midfield." << endl;
    }
    string getName() const override { return "3-5-2"; }
};

class FourTwoThreeOne : public FormationStrategy
{
public:
    void apply() const override
    {
        cout << "Applying 4-2-3-1 formation: Midfield dominance." << endl;
    }
    string getName() const override { return "4-2-3-1"; }
};