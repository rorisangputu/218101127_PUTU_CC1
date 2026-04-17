#include "Squad.h"
#include <iostream>
using namespace std;

Squad::Squad(string name) : squadName(name) {}

Squad::~Squad()
{
    for (Player *p : players)
    {
        delete p;
    }
}

void Squad::addPlayer(Player *p)
{
    players.push_back(p);
    cout << p->getName() << " added to squad." << endl;
}

void Squad::displaySquad() const
{
    if (players.empty())
    {
        cout << "Squad is empty." << endl;
        return;
    }
    cout << "\n=== " << squadName << " Squad ===" << endl;
    for (int i = 0; i < players.size(); i++)
    {
        cout << i + 1 << ". ";
        players[i]->display();
    }
}

Player *Squad::getPlayerByNumber(int number) const
{
    for (Player *p : players)
    {
        if (p->getNumber() == number)
        {
            return p;
        }
    }
    return nullptr;
}

int Squad::getSquadSize() const
{
    return players.size();
}

bool Squad::numberExists(int number) const
{
    for (Player *p : players)
    {
        if (p->getNumber() == number)
        {
            return true;
        }
    }
    return false;
}