/*
 *  Program name: Stereo Reciever
 *  Author: Jeffrey Harmon
 *  Date created: Oct. 27, 2020
 *  Date last updated: Oct. 28, 2020
 *  Purpose: Display and control a virtual stereo reciever
 */

#include "stereoReceiver.h"
#include <climits>
#include <iostream>
#include <string>

using namespace std;

void displayReceiver(StereoReceiver);

int main() {
  string manufacturer;
  string model;
  string serialNumber;
  int wattage;
  int numberOfChannels;

  cout << "Enter the manufacturer: ";
  cin >> manufacturer;

  cout << endl << "Enter the model: ";
  cin >> model;

  // Verify serial number is 10 characters
  do {
    cout << endl
         << "Enter the 10 digit serialNumber (may contain both letters and "
            "numbers): ";

    if (!(cin >> serialNumber) || !(serialNumber.length() == 10))
      cout << endl << "The serial number must be 10 digits. Try again.";

    cin.clear();
    cin.ignore(1000, '\n');
  } while (!(serialNumber.length() == 10));

  // Verify wattage is between 20 and 200
  do {
    cout << endl << "Enter the wattage per channel (between 20 and 200): ";

    if (!(cin >> wattage))
      cout << endl
           << "You entered something that isn't a number! Please Try again.";

    if (!(wattage >= 20 && wattage <= 200))
      cout << endl << "The wattage must be between 20 and 200.";

    cin.clear();
    cin.ignore(1000, '\n');
  } while (!(wattage >= 20 && wattage <= 200));

  // Verify frequency is between 5 and 13
  do {
    cout << endl << "Enter the number of channels (between 5 and 13): ";

    if (!(cin >> numberOfChannels))
      cout << endl
           << "You entered something that isn't a number! Please Try again.";

    if (!(numberOfChannels >= 5 && numberOfChannels <= 13))
      cout << endl << "The number of channels must be between 5 and 13.";

    cin.clear();
    cin.ignore(1000, '\n');
  } while (!(numberOfChannels >= 5 && numberOfChannels <= 13));

  // Create instance of a stereo reciever
  StereoReceiver stereoReceiver(manufacturer, model, serialNumber, wattage,
                                numberOfChannels);

  cout << endl;
  displayReceiver(stereoReceiver);

  cout << "Turning on the stereo. " << endl;

  stereoReceiver.setPower(true);

  cout << "The stereo is now on" << endl;

  bool active = true;

  // Loop for changing the stereo's settings
  while (active) {
    int choice;

    // Verification loop
    do {
      cout << "What setting would you like to change?" << endl;

      cout << "1. Band" << endl;
      cout << "2. Frequency" << endl;
      cout << "3. Increase Volume" << endl;
      cout << "4. Decrease Volume" << endl;

      // Verify choice
      if (!(std::cin >> choice) || !(choice >= 1 && choice <= 4))
        cout << "That is not a valid response." << endl;

      cin.clear();
      cin.ignore(1000, '\n');
    } while (!(choice >= 1 && choice <= 4));

    bandType curBand = stereoReceiver.getBand();

    // Do something based on choice
    switch (choice) {
    // Change band
    case 1:
      char newBandChoice;

      // Verification loop
      do {
        cout << "Enter the new band. Enter A for AM and F for FM: ";

        // Verify choice
        if (!(std::cin >> newBandChoice) ||
            !(tolower(newBandChoice) == 'a' || tolower(newBandChoice) == 'f'))
          cout << endl << "That is not a valid response." << endl;

        cin.clear();
        cin.ignore(1000, '\n');
      } while (
          !(tolower(newBandChoice) == 'a' || tolower(newBandChoice) == 'f'));

      cout << "The band is now ";

      if (tolower(newBandChoice) == 'a') {
        stereoReceiver.setBand(AM);
        cout << "AM";
      } else {
        stereoReceiver.setBand(FM);
        cout << "FM";
      }

      cout << endl;

      break;
    // Change frequency
    case 2:
      double newFreq;

      do {
        cout << endl << "Enter the new frequency. The frequency range for ";

        if (curBand == AM)
          cout << "AM is 535 - 1605: ";
        else
          cout << "FM is 88.1 - 107.9: ";

        if (!(cin >> newFreq))
          cout
              << endl
              << "You entered something that isn't a number! Please Try again.";

        if (!((curBand == AM) ? (newFreq >= 535 && newFreq <= 1605)
                              : (newFreq >= 88.1 && newFreq <= 107.9)))
          cout << endl << "That frequency is out of range.";

        cin.clear();
        cin.ignore(1000, '\n');
      } while (!((curBand == AM) ? (newFreq >= 535 && newFreq <= 1605)
                                 : (newFreq >= 88.1 && newFreq <= 107.9)));

      stereoReceiver.setFrequency(newFreq);

      cout << "The freqency is now " << stereoReceiver.getFrequency() << endl;
      ;

      break;
    // Increase volume
    case 3:
      if (stereoReceiver.getVolume() == 10)
        cout << "The volume is at the maximum value and cannot be increased"
                " further"
             << endl;
      else
        stereoReceiver.increaseVolume();

      cout << "The volume is now " << stereoReceiver.getVolume() << endl;

      break;
    // Decrease volume
    case 4:
      if (stereoReceiver.getVolume() == 0)
        cout << "The volume is at the minimum value and cannot be decreased"
                " further"
             << endl;
      else
        stereoReceiver.decreaseVolume();

      cout << "The volume is now " << stereoReceiver.getVolume() << endl;

      break;
    }

    char cont;

    // Verification loop
    do {
      cout << "Would you like to change another setting? Enter y or n: ";

      // Verify choice
      if (!(std::cin >> cont) ||
          !(tolower(cont) == 'y' || tolower(cont) == 'n'))
        cout << endl << "That is not a valid response." << endl;

      cin.clear();
      cin.ignore(1000, '\n');
    } while (!(tolower(cont) == 'y' || tolower(cont) == 'n'));

    if (tolower(cont) == 'n')
      active = false;
  }

  cout << "Would you like to change other attributes? " << endl;

  // Display final settings
  cout << "Here are the settings for the " << stereoReceiver.getManufacturer()
       << " - " << stereoReceiver.getModel() << endl;
  cout << "Band: " << ((stereoReceiver.getBand() == AM) ? "AM" : "FM") << endl;
  cout << "Frequency: " << stereoReceiver.getFrequency() << endl;
  cout << "Volume: " << stereoReceiver.getVolume() << endl;
  cout << "Power: " << ((stereoReceiver.getPower()) ? "On" : "Off") << endl;

  cout << endl << "Turning off the stereo. " << endl;

  stereoReceiver.setPower(false);

  cout << "The stereo is now off" << endl;

  return 0;
}

void displayReceiver(StereoReceiver s) {
  cout << "Here is the Stereo Receiver information:" << endl;
  cout << "Manufacturer: " << s.getManufacturer() << endl;
  cout << "Model: " << s.getModel() << endl;
  cout << "Serial Number: " << s.getSerialNumber() << endl;
  cout << "Watts per channel: " << s.getWattage() << endl;
  cout << "Number of channels: " << s.getNumberOfChannels() << endl;
  cout << "Band: " << ((s.getBand() == AM) ? "AM" : "FM") << endl;
  cout << "Frequency: " << s.getFrequency() << endl;
  cout << "Volume: " << s.getVolume() << endl;
  cout << "Power: " << ((s.getPower()) ? "On" : "Off") << endl;
  cout << endl;
}
