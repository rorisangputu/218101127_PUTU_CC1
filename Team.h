#pragma once
#include <vector>
#include <string>
#include "Player.h"
#include "FormationStrategy.h"
using namespace std;

// Generic repository template
template <typename T>
class Repository
{
private:
    vector<T> items;

public:
    void add(T item) { items.push_back(item); }
    T get(int index) const { return items[index]; }
    int size() const { return items.size(); }
};

// Stores a full team lineup snapshot
struct LineupSnapshot
{
    string formation;
    vector<string> playerNames;
};

class Team
{
private:
    vector<Player *> players;
    FormationStrategy *strategy;
    string teamName;
    Repository<LineupSnapshot> lineupHistory;

public:
    Team(string name);
    ~Team();

    void addPlayer(Player *p);
    void displayTeam() const;
    void setStrategy(FormationStrategy *s);
    void applyStrategy() const;
    void saveLineup();
    void displayLineupHistory() const;

    // Search and sort
    void bubbleSort();
    int linearSearch(string name) const;

    int getTeamSize() const;
    string getFormationName() const;
};