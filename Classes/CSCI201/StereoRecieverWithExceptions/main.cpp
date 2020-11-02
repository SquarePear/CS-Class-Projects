/*
 *  Program name: Stereo Reciever with exceptions
 *  Author: Jeffrey Harmon
 *  Date created: Nov. 2, 2020
 *  Date last updated: Nov. 2, 2020
 *  Purpose: Display and control a virtual stereo reciever
 */

#include "stereoReceiver.h"
#include <climits>
#include <iostream>
#include <string>

using namespace std;

void displayReceiver(StereoReceiver);

int main() {
  try {
    string manufacturer;
    string model;
    string serialNumber;
    int wattage;
    int numberOfChannels;

    cout << "Enter the manufacturer: ";
    cin >> manufacturer;

    cout << endl << "Enter the model: ";
    cin >> model;

    cout << endl
         << "Enter the 10 digit serialNumber (may contain both letters and "
            "numbers): ";
    cin >> serialNumber;

    cout << endl << "Enter the wattage per channel (between 20 and 200): ";
    cin >> wattage;

    cout << endl << "Enter the number of channels (between 5 and 13): ";
    cin >> numberOfChannels;

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
      try {
        int choice;

        cout << "What setting would you like to change?" << endl;

        cout << "1. Band" << endl;
        cout << "2. Frequency" << endl;
        cout << "3. Volume" << endl;

        if (!(std::cin >> choice))
          exit(1);

        // Verify choice
        if (!(choice >= 1 && choice <= 4))
          throw string("That is not a valid response.");

        bandType curBand = stereoReceiver.getBand();

        // Do something based on choice

        switch (choice) {
        // Change band
        case 1:
          char bandChoice;

          cout << "Enter the new band. Enter A for AM and F for FM: ";

          if (!(std::cin >> bandChoice))
            exit(1);

          switch (tolower(bandChoice)) {
          case 'a':
            stereoReceiver.setBand(AM);
            break;
          case 'f':
            stereoReceiver.setBand(FM);
            break;
          default:
            throw string("Inappropriate value for Band");
            break;
          }

          cout << endl
               << "The band is now "
               << ((stereoReceiver.getBand() == AM) ? "AM" : "FM") << endl;

          break;
        // Change frequency
        case 2:
          double frequency;

          cout << "Enter the new frequency. The frequency range for ";

          if (curBand == AM)
            cout << "AM is 535 - 1605: ";
          else
            cout << "FM is 88.1 - 107.9: ";

          if (!(std::cin >> frequency))
            exit(1);

          stereoReceiver.setFrequency(frequency);

          cout << endl
               << "The freqency is now " << stereoReceiver.getFrequency()
               << endl;

          break;
        // Change volume
        case 3:
          int volume;

          cout << "Enter the new volume level ";

          if (!(cin >> volume))
            exit(1);

          stereoReceiver.setVolume(volume);

          cout << endl
               << "The volume is now " << stereoReceiver.getVolume() << endl;

          break;
        }
      } catch (string err) {
        cout << endl << err << endl;
      }

      try {
        char cont;

        cout << "Would you like to change another setting? Enter y or n: ";

        if (!(std::cin >> cont))
          exit(1);

        // Verify choice
        if (!(tolower(cont) == 'y' || tolower(cont) == 'n'))
          throw string("That is not a valid response.");

        if (tolower(cont) == 'n')
          active = false;

      } catch (string err) {
        cout << endl << err << endl;
      }
    }

    // Display final settings
    cout << "Here are the settings for the " << stereoReceiver.getManufacturer()
         << " - " << stereoReceiver.getModel() << endl;
    cout << "Band: " << ((stereoReceiver.getBand() == AM) ? "AM" : "FM")
         << endl;
    cout << "Frequency: " << stereoReceiver.getFrequency() << endl;
    cout << "Volume: " << stereoReceiver.getVolume() << endl;
    cout << "Power: " << ((stereoReceiver.getPower()) ? "On" : "Off") << endl;

    cout << endl << "Turning off the stereo. " << endl;

    stereoReceiver.setPower(false);

    cout << "The stereo is now off" << endl;

    return 0;
  } catch (string err) {
    cout << endl << err << endl;
  }
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
