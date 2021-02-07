/*
 *  Program name: Television Dynamic Array
 *  Author: Jeffrey Harmon
 *  Date created: Feb. 4, 2021
 *  Date last updated: Feb. 5, 2021
 *  Purpose: Input and display information about televisions stored in a dynamic
 *           array
 */

#include "television.h"
#include <iostream>
#include <string>
using namespace std;

Television *getTelevision();
Television *modifyTelevision(Television *);

int main() {
  int maxTelevisions = 0;

  // Get number of TVs

  cout << "How many televisions do you want to add?: ";

  while (!(cin >> maxTelevisions) || maxTelevisions <= 0) {
    cout << "Invalid input. Must be an integer greater than 0!" << endl;
    cout << "Please enter again: ";
    cin.clear();
    cin.ignore(1000, '\n');
  }

  cout << endl;

  Television **televisions = new Television *[maxTelevisions] { nullptr };
  Television *currentTelevision;

  int numTelevisions = 0;

  // Get TV's information

  while (numTelevisions < maxTelevisions) {
    cout << "Television #" << numTelevisions + 1 << endl;

    try {
      currentTelevision = getTelevision();

      televisions[numTelevisions++] = currentTelevision;
    } catch (const std::exception &e) {
      cout << e.what() << endl;
      cin.clear();
      cin.ignore(1000, '\n');
    }

    cout << endl;

    currentTelevision = nullptr;
  };

  // Output TVs

  cout << endl << "Here is the list of televisions you added:" << endl << endl;

  for (int i = 0; i < numTelevisions; i++) {
    cout << televisions[i]->toString() << endl;
  }

  // Deallocate memory

  for (int i = 0; i < numTelevisions; i++) {
    delete televisions[i];
  }

  delete[] televisions;

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
