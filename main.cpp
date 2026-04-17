#include <iostream>
#include <string>
#include "Team.h"
#include "Goalkeeper.h"
#include "Defender.h"
#include "Midfielder.h"
#include "Striker.h"
#include "FormationStrategy.h"
using namespace std;

int main()
{
    Team team("My Team");
    int choice;

    do
    {
        cout << "\n--- Soccer Team Strategy Simulator ---\n";
        cout << "1. Add Player\n";
        cout << "2. Display Team\n";
        cout << "3. Set Formation\n";
        cout << "4. Apply Strategy\n";
        cout << "5. Search Player\n";
        cout << "6. Sort Players by Skill\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1)
        {
            int role, number, skill;
            string name;
            cout << "Enter player name: ";
            cin >> name;
            cout << "Enter jersey number: ";
            cin >> number;
            cout << "Enter skill rating (1-100): ";
            cin >> skill;
            cout << "Select role:\n1. Goalkeeper\n2. Defender\n3. Midfielder\n4. Striker\n";
            cin >> role;

            try
            {
                if (role == 1)
                    team.addPlayer(new Goalkeeper(name, number, skill));
                else if (role == 2)
                    team.addPlayer(new Defender(name, number, skill));
                else if (role == 3)
                    team.addPlayer(new Midfielder(name, number, skill));
                else if (role == 4)
                    team.addPlayer(new Striker(name, number, skill));
                else
                    cout << "Invalid role." << endl;
            }
            catch (runtime_error &e)
            {
                cout << "Error: " << e.what() << endl;
            }
        }
        else if (choice == 2)
        {
            team.displayTeam();
        }
        else if (choice == 3)
        {
            int formation;
            cout << "Select formation:\n1. 4-4-2\n2. 4-3-3\n3. 4-2-2-2\n4. 3-5-2\n5. 4-2-3-1\n";
            cin >> formation;

            if (formation == 1)
                team.setStrategy(new FourFourTwo());
            else if (formation == 2)
                team.setStrategy(new FourThreeThree());
            else if (formation == 3)
                team.setStrategy(new FourTwoTwoTwo());
            else if (formation == 4)
                team.setStrategy(new ThreeFiveTwo());
            else if (formation == 5)
                team.setStrategy(new FourTwoThreeOne());
            else
                cout << "Invalid formation." << endl;
        }
        else if (choice == 4)
        {
            try
            {
                team.applyStrategy();
            }
            catch (runtime_error &e)
            {
                cout << "Error: " << e.what() << endl;
            }
        }
        else if (choice == 5)
        {
            string name;
            cout << "Enter player name to search: ";
            cin >> name;
            int index = team.linearSearch(name);
            if (index != -1)
            {
                cout << "Player found at position " << index + 1 << " in the roster." << endl;
            }
            else
            {
                cout << "Player not found." << endl;
            }
        }
        else if (choice == 6)
        {
            team.bubbleSort();
            team.displayTeam();
        }

    } while (choice != 7);

    cout << "Goodbye!" << endl;
    return 0;
}