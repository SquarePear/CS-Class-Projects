/*
 *  Program name: Computer Inventory
 *  Author: Jeffrey Harmon
 *  Date created: Nov. 13, 2020
 *  Date last updated: Nov. 13, 2020
 *  Purpose: Display a list of computers in inventory
 */

#include "computer.h"
#include <iostream>
#include <vector>

using namespace std;

Computer getComputer();
int getEnumOption(map<int, string>, int);

int main() {
  vector<Computer> computers;

  bool running = true;

  do {
    computers.push_back(getComputer());

    char choice;
    cout << "Would you like to add another computer [y/N]? ";
    cin >> choice;

    if (!(tolower(choice) == 'y'))
      running = false;
  } while (running);

  for (vector<Computer>::iterator it = computers.begin(); it != computers.end();
       it++)
    cout << endl << it->toString() << endl;

  return 0;
}

Computer getComputer() {
  try {
    Manufacturer manufacturer = static_cast<Manufacturer>(
        getEnumOption(ManufacturerName, ManufacturerLength));
    FormFactor formFactor = static_cast<FormFactor>(
        getEnumOption(FormFactorName, FormFactorLength));

    cout << "Enter the serial number: ";
    string sN;
    cin >> sN;

    Processor processor =
        static_cast<Processor>(getEnumOption(ProcessorName, ProcessorLength));

    cout << "Enter amount of RAM (GB): ";
    int ram;
    cin >> ram;

    StorageType storageType = static_cast<StorageType>(
        getEnumOption(StorageTypeName, StorageTypeLength));

    cout << "Enter capacity of the " << StorageTypeName[storageType]
         << " (GB): ";
    int storageSize;
    cin >> storageSize;

    Computer computer(manufacturer, formFactor, sN, processor, ram, storageType,
                      storageSize);

    return computer;
  } catch (string err) {
    cout << endl << err << endl;
    exit(0);
  }
}

int getEnumOption(map<int, string> nameMap, int length) {
  cout << "Pick one of the following:" << endl;

  for (int i = 0; i < length; i++)
    cout << i + 1 << ": " << nameMap[i] << endl;

  int choice;

  if (!(cin >> choice) || choice < 1 || choice > length + 1)
    throw string("Invalid choice!");

  return choice;
}
