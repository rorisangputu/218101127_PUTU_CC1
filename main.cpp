#include <iostream>
#include <string>
#include "Team.h"
#include "Squad.h"
#include "Goalkeeper.h"
#include "Defender.h"
#include "Midfielder.h"
#include "Striker.h"
#include "FormationStrategy.h"
using namespace std;

int main()
{
    Squad squad("My Squad");
    Team team("My Team");
    int choice;

    do
    {
        cout << "\n--- Soccer Team Strategy Simulator ---\n";
        cout << "1. Add Player to Squad\n";
        cout << "2. Display Squad\n";
        cout << "3. Select Team\n";
        cout << "4. Display Team\n";
        cout << "5. Set Formation\n";
        cout << "6. Apply Strategy\n";
        cout << "7. Save Lineup\n";
        cout << "8. View Lineup History\n";
        cout << "9. Search Player in Team\n";
        cout << "10. Sort Team by Skill\n";
        cout << "11. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1)
        {
            int role, number, skill;
            string name;
            cout << "Enter 0 at any time to go back to menu.\n";

            while (true)
            {
                cout << "Enter player name (0 to stop): ";
                cin >> name;
                if (name == "0")
                    break;

                cout << "Enter jersey number: ";
                cin >> number;

                if (squad.numberExists(number))
                {
                    cout << "Jersey number " << number << " is already taken. Try again." << endl;
                    continue;
                }

                cout << "Enter skill rating (1-100): ";
                cin >> skill;
                cout << "Select role:\n1. Goalkeeper\n2. Defender\n3. Midfielder\n4. Striker\n";
                cin >> role;

                if (role == 1)
                {
                    squad.addPlayer(new Goalkeeper(name, number, skill));
                    cout << squad.getSquadSize() << " player(s) in squad so far." << endl;
                }
                else if (role == 2)
                {
                    squad.addPlayer(new Defender(name, number, skill));
                    cout << squad.getSquadSize() << " player(s) in squad so far." << endl;
                }
                else if (role == 3)
                {
                    squad.addPlayer(new Midfielder(name, number, skill));
                    cout << squad.getSquadSize() << " player(s) in squad so far." << endl;
                }
                else if (role == 4)
                {
                    squad.addPlayer(new Striker(name, number, skill));
                    cout << squad.getSquadSize() << " player(s) in squad so far." << endl;
                }
                else
                    cout << "Invalid role." << endl;
            }
        }
        else if (choice == 2)
        {
            squad.displaySquad();
        }
        else if (choice == 3)
        {
            if (squad.getSquadSize() < 11)
            {
                cout << "Not enough players in squad. Need at least 11." << endl;
            }
            else
            {
                squad.displaySquad();
                cout << "\nPick 11 players by jersey number:" << endl;
                int picked = 0;
                while (picked < 11)
                {
                    int number;
                    cout << "Pick player " << picked + 1 << " of 11 (jersey number): ";
                    cin >> number;
                    Player *p = squad.getPlayerByNumber(number);
                    if (p == nullptr)
                    {
                        cout << "Player not found. Try again." << endl;
                    }
                    else
                    {
                        try
                        {
                            team.addPlayer(p);
                            picked++;
                        }
                        catch (runtime_error &e)
                        {
                            cout << "Error: " << e.what() << endl;
                        }
                    }
                }
                cout << "Team built successfully." << endl;
            }
        }
        else if (choice == 4)
        {
            team.displayTeam();
        }
        else if (choice == 5)
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
        else if (choice == 6)
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
        else if (choice == 7)
        {
            team.saveLineup();
        }
        else if (choice == 8)
        {
            team.displayLineupHistory();
        }
        else if (choice == 9)
        {
            string name;
            cout << "Enter player name to search: ";
            cin >> name;
            int index = team.linearSearch(name);
            if (index != -1)
                cout << "Player found at position " << index + 1 << " in the team." << endl;
            else
                cout << "Player not found." << endl;
        }
        else if (choice == 10)
        {
            team.bubbleSort();
            team.displayTeam();
        }

    } while (choice != 11);

    cout << "Goodbye!" << endl;
    return 0;
}