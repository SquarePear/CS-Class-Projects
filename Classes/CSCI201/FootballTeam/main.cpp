/*
 *  Program name: Football Team
 *  Author: Jeffrey Harmon
 *  Date created: Dec. 4, 2020
 *  Date last updated: Dec. 4, 2020
 *  Purpose: Create and display a Football team and its players
 */

#include "defense.h"
#include "offense.h"
#include "player.h"
#include "special.h"
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void addOffensive(vector<player> &players);
void addDefensive(vector<player> &players);
void addSpecial(vector<player> &players);
void displayTeam(vector<player> &players);

string toLower(string s) {
  transform(s.begin(), s.end(), s.begin(),
            [](unsigned char c) { return tolower(c); });
  return s;
}

int main() {
  vector<player> players;

  while (true) {
    try {
      cout << "1. Add Offense Player" << endl;
      cout << "2. Add Defense Player" << endl;
      cout << "3. Add Special Teams Player" << endl;
      cout << "4. Quit" << endl;
      cout << "Enter your choice(1-4) : ";

      int choice;

      if (!(cin >> choice))
        throw invalid_argument("Invalid input.");
      if (choice < 1 || choice > 4)
        throw out_of_range("Input must be between 1 and 4.");

      switch (choice) {
      case 1:
        addOffensive(players);
        break;
      case 2:
        addDefensive(players);
        break;
      case 3:
        addSpecial(players);
        break;
      case 4:
      default:
        displayTeam(players);
        return 0;
        break;
      }

    } catch (const exception &e) {
      cerr << "Error creating player: " << e.what() << endl;

      cin.clear();
      cin.ignore(1000, '\n');
    }
  }

  return 0;
}

void addOffensive(vector<player> &players) {
  unsigned int id;
  string name;
  string position;

  cout << "Player ID: ";
  cin >> id;

  cout << "Name: ";
  cin >> name;

  cout << "Offense Position (QuarterBack / Wide Receiver / Tight End / Running "
          "Back / Offensive Lineman): ";
  cin >> position;

  position = toLower(position);

  if (position == "quarterback") {
    players.push_back(quarterback(name, id));
  } else if (position == "wide receiver") {
    players.push_back(widereceiver(name, id));
  } else if (position == "tight end") {
    players.push_back(tightend(name, id));
  } else if (position == "running back") {
    players.push_back(runningback(name, id));
  } else if (position == "offensive lineman") {
    players.push_back(offensivelineman(name, id));
  } else {
    throw invalid_argument("The position is invalid.");
  }
}

void addDefensive(vector<player> &players) {
  unsigned int id;
  string name;
  string position;

  cout << "Player ID: ";
  cin >> id;

  cout << "Name: ";
  cin >> name;

  cout
      << "Defense Position (Defensive Lineman / Linebacker / Defensive Back): ";
  cin >> position;

  position = toLower(position);

  if (position == "defesive lineman") {
    players.push_back(defensivelineman(name, id));
  } else if (position == "line backer") {
    players.push_back(linebacker(name, id));
  } else if (position == "defensive back") {
    players.push_back(defensivelineman(name, id));
  } else {
    throw invalid_argument("The position is invalid.");
  }
}

void addSpecial(vector<player> &players) {
  unsigned int id;
  string name;
  string position;

  cout << "Player ID: ";
  cin >> id;

  cout << "Name: ";
  cin >> name;

  cout << "Special Teams Position (Kicker / Holder / Punter / Returner): ";
  cin >> position;

  position = toLower(position);

  if (position == "kicker") {
    players.push_back(kicker(name, id));
  } else if (position == "holder") {
    players.push_back(holder(name, id));
  } else if (position == "punter") {
    players.push_back(punter(name, id));
  } else if (position == "returner") {
    players.push_back(returner(name, id));
  } else {
    throw invalid_argument("The position is invalid.");
  }
}

void displayTeam(vector<player> &players) {
  cout << "Number of players in the team: " << to_string(players.size())
       << endl;
  cout << "Player details:" << endl;

  for (int i = 0; i < players.size(); i++) {
    cout << players[i].toString() << endl;
  }
}
