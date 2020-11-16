/*
 *  Program name: Output state info
 *  Author: Jeffrey Harmon
 *  Date created: Nov. 15, 2020
 *  Date last updated: Nov. 15, 2020
 *  Purpose: Read a file and output information about US states
 */

#include <fstream>
#include <iostream>
#include <map>
#include <string>

using namespace std;

struct State {
  string abbrv;
  string name;
  string governor;
  string flower;
};

void displayState(State);

int main() {
  map<string, State> states;

  fstream fileIn("states.txt", fstream::in);

  while (!fileIn.eof()) {
    State state;

    getline(fileIn, state.abbrv);
    getline(fileIn, state.name);
    getline(fileIn, state.governor);
    getline(fileIn, state.flower);

    states.insert(pair<string, State>(state.abbrv, state));
  }

  fileIn.close();

  string input;

  while (true) {
    cout << "Enter a state abbreviation or enter # to quit: ";
    cin >> input;

    if (input == "#")
      break;

    if (states.find(input) == states.end()) {
      cout << "That is not a valid state." << endl;
      continue;
    }

    State state = states[input];

    displayState(state);
  };

  return 0;
}

void displayState(State state) {
  cout << endl;
  cout << "State Name: " << state.name << endl;
  cout << "Governor: " << state.governor << endl;
  cout << "Flower: " << state.flower << endl;
  cout << endl;
}
