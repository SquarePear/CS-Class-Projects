/*
 *  Program name: Television
 *  Author: Jeffrey Harmon
 *  Date created: Jan. 28, 2021
 *  Date last updated: Jan. 29, 2021
 *  Purpose: Input and display information about televisions
 */

#include "television.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

Television *getTelevision();
Television *modifyTelevision(Television *);

int main() {
  vector<Television> televisions;
  Television *currentTelevision;
  char sentinel = 'y';

  do {
    cout << "Television #" << televisions.size() + 1 << endl;

    try {
      currentTelevision = getTelevision();

      televisions.push_back(*currentTelevision);

      cout << endl
           << "You have added " << televisions.size() << " televisions. "
           << "Would you like to add another? (y/n): ";
      cin >> sentinel;
      cout << endl;
    } catch (const std::exception &e) {
      cout << e.what() << endl;
      cin.clear();
      cin.ignore(1000, '\n');
    }

    currentTelevision = nullptr;
  } while (tolower(sentinel) == 'y');

  do {
    for (int i = 0; i < televisions.size(); i++) {
      cout << i + 1 << ": " << televisions[i].getName() << endl;
    }

    cout << endl;
    cout << "Pick a television to modify: ";

    try {
      unsigned int choice;

      if (!(cin >> choice) || choice <= 0 || choice > televisions.size())
        throw out_of_range("Invalid Choice!");

      currentTelevision = &televisions[choice - 1];

      cout << endl;

      modifyTelevision(currentTelevision);

      cout << endl;

      cout << "You have modified television #" << choice << "." << endl;
      cout << "Would you like to modify another? (y/n): ";
      cin >> sentinel;
      cout << endl;

    } catch (const std::exception &e) {
      cout << e.what() << endl;
      cin.clear();
      cin.ignore(1000, '\n');
    }

    currentTelevision = nullptr;
  } while (tolower(sentinel) == 'y');

  cout << endl << "Here is the list of televisions you added:" << endl << endl;

  for (int i = 0; i < televisions.size(); i++) {
    cout << televisions[i].toString() << endl;
  }

  return 1;
}

Television *getTelevision() {
  string manufacturer;
  string model;
  double screenSize;
  Resolution resolution;
  unsigned int refreshRate;
  unsigned int numInputs;
  double price;

  cout << "Manufacturer: ";
  cin >> manufacturer;

  cout << "Model: ";
  cin >> model;

  cout << "Screen size (inches): ";
  cin >> screenSize;

  cout << "Resolution (pixels): " << endl;
  cout << "  width: ";
  cin >> resolution.width;
  cout << "  height: ";
  cin >> resolution.height;

  cout << "Refresh rate: ";
  cin >> refreshRate;

  cout << "Number of inputs: ";
  cin >> numInputs;

  cout << "Price (USD): $";
  cin >> price;

  return new Television(manufacturer, model, screenSize, resolution,
                        refreshRate, numInputs, price);
}

Television *modifyTelevision(Television *television) {
  while (true) {
    if (!television->getPower()) {
      cout << "Turn on " << television->getName() << "? (y/n): ";

      char sentinel = 'y';

      cin >> sentinel;

      if (tolower(sentinel) == 'y')
        television->togglePower();
      else
        return television;

      cout << endl;
    }

    cout << "1: Turn off" << endl;
    cout << "2: Channel up" << endl;
    cout << "3: Channel down" << endl;
    cout << "4: Volume up" << endl;
    cout << "5: Volume down" << endl;
    cout << endl;
    cout << "Pick a modification for " << television->getName() << ": ";

    int choice;

    if (!(cin >> choice) || choice < 1 || choice > 5)
      throw out_of_range("Invalid Choice!");

    cout << endl;

    switch (choice) {
    case 1:
      television->togglePower();
      cout << television->getName() << " is now powered off." << endl;
      break;
    case 2:
      cout << television->getName() << " is now on channel "
           << television->channelUp() << "." << endl;
      break;
    case 3:
      cout << television->getName() << " is now on channel "
           << television->channelDown() << "." << endl;
      break;
    case 4:
      cout << television->getName() << " now has a volume of "
           << television->volumeUp() << "." << endl;
      break;
    case 5:
    default:
      cout << television->getName() << " now has a volume of "
           << television->volumeDown() << "." << endl;
      break;
    }

    cout << endl;

    cout << "Would you like to modify " << television->getName()
         << " more? (y/n): ";

    char sentinel = 'y';

    cin >> sentinel;

    if (tolower(sentinel) != 'y')
      return television;
  }
}
