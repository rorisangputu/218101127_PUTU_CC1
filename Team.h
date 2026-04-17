#pragma once
#include <vector>
#include <string>
#include "Player.h"
#include "FormationStrategy.h"
using namespace std;

// Generic repository template for storing any type
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

class Team
{
private:
    vector<Player *> players;
    FormationStrategy *strategy;
    string teamName;
    Repository<string> formationHistory;

public:
    Team(string name);
    ~Team();

    void addPlayer(Player *p);
    void displayTeam() const;
    void setStrategy(FormationStrategy *s);
    void applyStrategy() const;

    // Search and sort
    void bubbleSort();
    int linearSearch(string name) const;
};