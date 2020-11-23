/*
 *  Program name: Soldier Manager
 *  Author: Jeffrey Harmon
 *  Date created: Nov. 19, 2020
 *  Date last updated: Nov. 20, 2020
 *  Purpose: Create, display, and manage a list of soldiers
 */

#include "soldier.h"
#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<Soldier> soldiers;

  // Add soldiers to the list (Randomly generated names)
  soldiers.push_back(Soldier("Michael Edwards", Officer, 3));
  soldiers.push_back(Soldier("Terri Long", Warrent, 4));
  soldiers.push_back(Soldier("Larry Williams", Enlisted, 2));
  soldiers.push_back(Soldier("John Ramos", Enlisted, 7));
  soldiers.push_back(Soldier("Bennie Goodson", Officer, 8));

  Soldier highestRanking = *soldiers.begin();
  for (int i = 0; i < soldiers.size(); i++) {

    cout << soldiers[i] << endl;

    if (soldiers[i] > highestRanking)
      highestRanking = soldiers[i];
  }

  cout << endl;
  cout << "Highest Ranking:" << endl;
  cout << highestRanking << endl;

  try {
    srand(time(NULL));

    while (true) {
      Soldier randomSoldier = soldiers[rand() % soldiers.size()];

      randomSoldier.setRank(rand() % 10 + 1);

      cout << randomSoldier << endl;
    }

  } catch (const exception &e) {
    cerr << endl << e.what() << endl;
  }

  return 0;
}
