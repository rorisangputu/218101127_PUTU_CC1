#include "Team.h"
#include <iostream>
using namespace std;

Team::Team(string name) : teamName(name), strategy(nullptr) {}

Team::~Team()
{
    for (Player *p : players)
    {
        delete p;
    }
}

void Team::addPlayer(Player *p)
{
    if (players.size() >= 11)
    {
        throw runtime_error("Cannot add more than 11 players to a team.");
    }
    players.push_back(p);
    cout << p->getName() << " added to the team." << endl;
}

void Team::displayTeam() const
{
    if (players.empty())
    {
        cout << "No players in the team." << endl;
        return;
    }
    cout << "\n=== " << teamName << " ===" << endl;
    if (strategy != nullptr)
    {
        cout << "Formation: " << strategy->getName() << endl;
    }
    cout << "Players:" << endl;
    for (Player *p : players)
    {
        p->display();
    }
    cout << "Total players: " << players.size() << endl;

    cout << "\nFormation History:" << endl;
    for (int i = 0; i < formationHistory.size(); i++)
    {
        cout << i + 1 << ". " << formationHistory.get(i) << endl;
    }
}

void Team::setStrategy(FormationStrategy *s)
{
    strategy = s;
    formationHistory.add(s->getName());
    cout << "Strategy updated." << endl;
}

void Team::applyStrategy() const
{
    if (strategy == nullptr)
    {
        throw runtime_error("No strategy set for the team.");
    }
    strategy->apply();
}

// Bubble sort - sorts players by skill (ascending)
void Team::bubbleSort()
{
    int n = players.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (*players[j] > *players[j + 1])
            {
                Player *temp = players[j];
                players[j] = players[j + 1];
                players[j + 1] = temp;
            }
        }
    }
    cout << "Players sorted by skill (ascending)." << endl;
}

// Linear search - finds player by name, returns index or -1
int Team::linearSearch(string name) const
{
    for (int i = 0; i < players.size(); i++)
    {
        if (players[i]->getName() == name)
        {
            return i;
        }
    }
    return -1;
}