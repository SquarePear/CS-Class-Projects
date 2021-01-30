/*
 *  Program name: StateInfo
 *  Author: Jeffrey Harmon
 *  Date created: Jan. 27, 2021
 *  Date last updated: Jan. 29, 2021
 *  Purpose: Input and display information about states
 */

#include "state.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

State getState();
Person getPerson();
string eee(int);

int main() {
  vector<State> states;
  char sentinel = 'y';

  do {
    State state;

    try {
      state = getState();
      states.push_back(state);

      if (states.size() >= 50) {
        sentinel = 'n';
      } else {
        cout << endl << "Would you like to add another state? (y/n): ";
        cin >> sentinel;
        cout << endl;
      }
    } catch (const std::exception &e) {
      cout << e.what() << endl;
      cin.clear();
      cin.ignore(1000, '\n');
    }

  } while (tolower(sentinel) == 'y');

  cout << endl << "Here is the list of states you added:" << endl << endl;

  for (int i = 0; i < states.size(); i++) {
    State state = states[i];

    cout << state.name << " (" << state.abbreviation << "):" << endl;
    cout << "  Governor: " << state.governor.firstName << " "
         << state.governor.middleInitial << ". " << state.governor.lastName
         << endl;
    cout << "  Lieutenant Governor: " << state.lieutenantGovernor.firstName
         << " " << state.lieutenantGovernor.middleInitial << ". "
         << state.lieutenantGovernor.lastName << endl;
    cout << "  Capitol: " << state.capitol << endl;
    cout << "  Flower: " << state.flower << endl;
    cout << "  Congressional Representatives: " << state.representatives
         << endl;
    cout << "  Order added to the Union: " << eee(state.order) << endl;
    cout << "  Founding Year: " << state.year << endl;
  }

  return 1;
}

State getState() {
  State state;

  cout << "Enter the State's info:" << endl;

  cout << "Name: ";
  if (!(cin >> state.name))
    throw runtime_error("Invalid name.");
  cout << "Abbreviation: ";
  if (!(cin >> state.abbreviation) || state.abbreviation.length() != 2)
    throw runtime_error("Invalid abbreviation.");

  cout << "Governor: " << endl;
  state.governor = getPerson();
  cout << "Lieutenant Governor: " << endl;
  state.lieutenantGovernor = getPerson();

  cout << "Capitol: ";
  if (!(cin >> state.capitol))
    throw runtime_error("Invalid capitol.");
  cout << "Flower: ";
  if (!(cin >> state.flower))
    throw runtime_error("Invalid flower.");
  cout << "Representatives: ";
  if (!(cin >> state.representatives) || state.representatives < 1)
    throw runtime_error("Invalid number of representatives.");
  cout << "Order (1 - 50): ";
  if (!(cin >> state.order) || state.order < 1 || state.order > 50)
    throw runtime_error("Invalid founding order.");
  cout << "Founding Year (>= 1776): ";
  if (!(cin >> state.year) || state.year < 1776)
    throw runtime_error("Invalid founding year.");

  return state;
}

Person getPerson() {
  Person person;

  cout << "  First Name: ";
  if (!(cin >> person.firstName))
    throw runtime_error("Invalid name.");
  cout << "  Middle Initial: ";
  if (!(cin >> person.middleInitial))
    throw runtime_error("Invalid initial.");
  cout << "  Last Name: ";
  if (!(cin >> person.lastName))
    throw runtime_error("Invalid name.");

  return person;
}

string eee(int number) {
  string num = to_string(number);
  if (number == 1)
    num += "st";

  if (number == 2)
    num += "nd";

  if (number == 3)
    num += "rd";

  if (number >= 4)
    num += "th";

  return num;
}