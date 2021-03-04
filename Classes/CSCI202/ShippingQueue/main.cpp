/*
 *  Program name: Copy Stack
 *  Author: Jeffrey Harmon
 *  Date created: Feb. 24, 2021
 *  Date last updated: Feb. 24, 2021
 *  Purpose: Copy a stack externally
 */

#include "package.h"
#include "priorityqueue.h"
#include <iostream>
#include <string>

using namespace std;

Address getAddress();

int main() {
  PriorityQueue<Package> packages;
  char sentinel = 'y';

  Address tempAddress;
  int tempPostalClass;

  try {
    do {
      cout << "Enter package details: " << endl;

      cout << "Postal Class (1-7): ";

      if (!(cin >> tempPostalClass) || tempPostalClass < 1 ||
          tempPostalClass > 7)
        throw runtime_error("Invalid input");

      cin.clear();
      cin.ignore(1000, '\n');

      cout << "Address: " << endl;
      tempAddress = getAddress();

      packages.push(*(new Package(static_cast<PostalClass>(tempPostalClass - 1),
                                  tempAddress)));

      cout << "Add more? (y/n): ";
      if (!(cin >> sentinel))
        throw runtime_error("Invalid input");
    } while (sentinel == 'y');
  } catch (const std::exception &e) {
    cout << e.what() << endl;
    cin.clear();
    cin.ignore(1000, '\n');
  }

  cout << endl << endl;

  while (!packages.empty())
    cout << packages.pop() << " ";

  return 0;
}

Address getAddress() {
  Address address;

  cout << "  Line 1: ";
  if (!getline(cin, address.line1))
    throw runtime_error("Invalid line.");

  cout << "  Line 2 (n): ";
  if (!getline(cin, address.line2))
    throw runtime_error("Invalid line.");

  if (address.line2 == "n")
    address.line2 = "";

  cout << "  City: ";
  if (!getline(cin, address.city))
    throw runtime_error("Invalid city.");

  cout << "  State: ";
  if (!getline(cin, address.state))
    throw runtime_error("Invalid state.");

  cout << "  Postal Code: ";
  if (!(cin >> address.postalCode))
    throw runtime_error("Invalid postal code.");

  cin.clear();
  cin.ignore(1000, '\n');

  cout << "  Country: ";
  if (!getline(cin, address.country))
    throw runtime_error("Invalid country.");

  return address;
}
