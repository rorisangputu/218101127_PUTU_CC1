#include "Team.h"
#include <iostream>
using namespace std;

Team::Team(string name) : teamName(name), strategy(nullptr) {}

Team::~Team() {}

void Team::addPlayer(Player *p)
{
    if (players.size() >= 11)
    {
        throw runtime_error("Cannot add more than 11 players to a team.");
    }
    players.push_back(p);
    cout << p->getName() << " added to team." << endl;
}

void Team::displayTeam() const
{
    if (players.empty())
    {
        cout << "No players in team." << endl;
        return;
    }
    cout << "\n=== " << teamName << " ===" << endl;
    if (strategy != nullptr)
    {
        cout << "Formation: " << strategy->getName() << endl;
    }
    for (Player *p : players)
    {
        p->display();
    }
    cout << "Total players: " << players.size() << endl;
}

void Team::setStrategy(FormationStrategy *s)
{
    strategy = s;
    cout << "Formation set to " << s->getName() << endl;
}

void Team::applyStrategy() const
{
    if (strategy == nullptr)
    {
        throw runtime_error("No strategy set for the team.");
    }
    strategy->apply();
}

void Team::saveLineup()
{
    if (players.empty())
    {
        cout << "No players in team to save." << endl;
        return;
    }
    LineupSnapshot snapshot;
    snapshot.formation = strategy ? strategy->getName() : "None";
    for (Player *p : players)
    {
        snapshot.playerNames.push_back(p->getName());
    }
    lineupHistory.add(snapshot);
    cout << "Lineup saved." << endl;
}

void Team::displayLineupHistory() const
{
    if (lineupHistory.size() == 0)
    {
        cout << "No lineups saved yet." << endl;
        return;
    }
    for (int i = 0; i < lineupHistory.size(); i++)
    {
        LineupSnapshot s = lineupHistory.get(i);
        cout << "\nLineup " << i + 1 << " | Formation: " << s.formation << endl;
        for (int j = 0; j < s.playerNames.size(); j++)
        {
            cout << "  " << j + 1 << ". " << s.playerNames[j] << endl;
        }
    }
}

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

int Team::getTeamSize() const
{
    return players.size();
}

string Team::getFormationName() const
{
    return strategy ? strategy->getName() : "None";
}