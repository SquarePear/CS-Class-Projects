/*
 *  Program name: CubeInfo
 *  Author: Jeffrey Harmon
 *  Date created: Oct. 26, 2020
 *  Date last updated: Oct. 27, 2020
 *  Purpose: Create, modify, and get info about a "cube"
 */

#include "cube.h"
#include <climits>
#include <iostream>
#include <string>

using namespace std;

void displayCube(Cube);
int inputVerification(string);
void changeProperty(Cube &theCube);

int main() {
  // Declaring variables
  int length, width, height;
  string color;

  // Get value for length
  length = inputVerification("length");

  // Get value for width
  cout << endl;
  width = inputVerification("width");

  // Get value for height
  cout << endl;
  height = inputVerification("height");

  // Get value for color (No verification needed)
  cout << endl << "Enter the color of the cube: ";
  cin >> color;

  // Create a cube
  Cube cube;

  // Set all of the cube's properties
  cube.setLength(length);
  cube.setWidth(width);
  cube.setHeight(height);
  cube.setColor(color);

  // Display the cube's info in terminal windoe
  displayCube(cube);

  // Loop for editing cube's info
  while (bool active = true) {
    char choice;

    // Verification loop
    do {
      cout << "Would you like to change any of the cube's information? ";

      // Verify choice
      if (!(std::cin >> choice) ||
          !(tolower(choice) == 'y' || tolower(choice) == 'n'))
        cout << endl << "That is not a valid response." << endl;

      cin.clear();
      cin.ignore(1000, '\n');
    } while (!(tolower(choice) == 'y' || tolower(choice) == 'n'));

    // Do something based on choice
    switch (tolower(choice)) {
    case 'y':
      changeProperty(cube);
      break;

    default:
      active = false;
      displayCube(cube);
      return 0;
    }
  }

  return 0;
}

void displayCube(Cube theCube) {
  cout << endl;
  cout << "Length: " << theCube.getLength() << endl;
  cout << "Width: " << theCube.getWidth() << endl;
  cout << "Height: " << theCube.getHeight() << endl;
  cout << "Color: " << theCube.getColor() << endl;
  cout << "Volume: " << theCube.calculateVolume() << endl;
}

// Verify input for cube sizes
int inputVerification(string name) {
  int val;

  // Verification loop
  do {
    cout << "Enter the " << name << " of the cube: ";

    // Verify input
    if (!(std::cin >> val))
      cout << endl
           << "You entered something that isn't a number! Please Try again."
           << endl;
    else if (val <= 0)
      cout << endl << "The " << name << " must be greater than 0." << endl;

    cin.clear();
    cin.ignore(1000, '\n');
  } while (val <= 0);

  return val;
}

void changeProperty(Cube &theCube) {
  int choice;

  // Verification loop
  do {
    cout << endl << "What property would you like to change?" << endl;

    cout << "1. Length" << endl;
    cout << "2. Width" << endl;
    cout << "3. Height" << endl;
    cout << "4. Color" << endl;

    // Verify choice
    if (!(std::cin >> choice) || !(choice >= 1 && choice <= 4))
      cout << endl << "That is not a valid response.";

    cin.clear();
    cin.ignore(1000, '\n');
  } while (!(choice >= 1 && choice <= 4));

  // Do something based on choice
  switch (choice) {
  case 1:
    theCube.setLength(inputVerification("length"));
    break;
  case 2:
    theCube.setWidth(inputVerification("width"));
    break;
  case 3:
    theCube.setHeight(inputVerification("height"));
    break;
  default:
    string color;
    cout << endl << "Enter the color of the cube: ";
    cin >> color;
    theCube.setColor(color);
    break;
  }
}
