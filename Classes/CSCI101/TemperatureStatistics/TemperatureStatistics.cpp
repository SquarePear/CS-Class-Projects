/*
 *  Program name: Temperature Statistics
 *  Author: Jeffrey Harmon
 *  Date created: Apr. 22, 2020
 *  Date last updated: Apr. 22, 2020
 *  Purpose: Display entered temperature data
 */

#include <iomanip>
#include <iostream>

#define TOTAL_MONTHS 12

// List of month names
const std::string MONTHS[TOTAL_MONTHS] = {
    "January", "February", "March",     "April",   "May",      "June",
    "July",    "August",   "September", "October", "November", "December"};

// Declaring function prototypes
void getData(double rainfall[TOTAL_MONTHS][2]);
double averageHigh(double rainfall[TOTAL_MONTHS][2]);
double averageLow(double rainfall[TOTAL_MONTHS][2]);
int indexHighTemp(double rainfall[TOTAL_MONTHS][2]);
int indexLowTemp(double rainfall[TOTAL_MONTHS][2]);

int main() {
  // Clearing terminal (only works in Unix based OSes like macOS and Linux)
  system("clear");

  double rainfall[TOTAL_MONTHS][2] = {{0}};

  // Ask user for input
  getData(rainfall);

  // Calculating information
  double averageLowTemp = averageLow(rainfall);
  double averageHighTemp = averageHigh(rainfall);

  int lowTempIndex = indexLowTemp(rainfall);
  int highTempIndex = indexHighTemp(rainfall);

  // Outputting information
  std::cout << std::fixed << std::setprecision(2) << std::endl;

  std::cout << "Annual Temperature Report for Hancock County." << std::endl;
  std::cout << "The average low recorded temperature was " << averageLowTemp
            << " degrees." << std::endl;
  std::cout << "The average high recorded temperature was " << averageHighTemp
            << " degrees." << std::endl;
  std::cout << "The lowest recorded temperature was in " << MONTHS[lowTempIndex]
            << " at " << rainfall[lowTempIndex][0] << " degrees." << std::endl;
  std::cout << "The highest recorded temperature was in "
            << MONTHS[highTempIndex] << " at " << rainfall[highTempIndex][1]
            << " degrees." << std::endl;

  return 0;
}

// This function reads and stores data in the two-dimensional array
void getData(double rainfall[TOTAL_MONTHS][2]) {
  for (int i = 0; i < TOTAL_MONTHS; i++) {
    double lowTemp = 0;
    double highTemp = 0;

    std::cout << "Enter the lowest temperature recorded in " << MONTHS[i]
              << ": ";
    while (!(std::cin >> lowTemp)) {
      std::cout << "Invalid input! Please enter again: ";
      std::cin.clear();
      std::cin.ignore(1000, '\n');
    }

    std::cout << "Enter the highest temperature recorded in " << MONTHS[i]
              << ": ";
    while (!(std::cin >> highTemp) || highTemp < lowTemp) {
      std::cout << "Invalid input! Value must be greater that the lowest "
                   "temperature. Please enter again: ";
      std::cin.clear();
      std::cin.ignore(1000, '\n');
    }

    // Save inputted information
    rainfall[i][0] = lowTemp;
    rainfall[i][1] = highTemp;
  }
}

// This function calculates and returns the average low temperature for the
// year.
double averageLow(double rainfall[TOTAL_MONTHS][2]) {
  double averageLow = 0;

  for (int i = 0; i < TOTAL_MONTHS; i++) {
    averageLow += rainfall[i][0];
  }

  return averageLow / TOTAL_MONTHS;
}

// This function calculates and returns the average high temperature for the
// year.
double averageHigh(double rainfall[TOTAL_MONTHS][2]) {
  double averageHigh = 0;

  for (int i = 0; i < TOTAL_MONTHS; i++) {
    averageHigh += rainfall[i][1];
  }

  return averageHigh / TOTAL_MONTHS;
}

// This function returns the index of the lowest low temperature in the array.
int indexLowTemp(double rainfall[TOTAL_MONTHS][2]) {
  int indexLow = 0;

  for (int i = 1; i < TOTAL_MONTHS; i++) {
    if (rainfall[indexLow][0] > rainfall[i][0])
      indexLow = i;
  }

  return indexLow;
}

// This function returns the index of the highest high temperature in the array.
int indexHighTemp(double rainfall[TOTAL_MONTHS][2]) {
  int indexHigh = 0;

  for (int i = 1; i < TOTAL_MONTHS; i++) {
    if (rainfall[indexHigh][1] < rainfall[i][1])
      indexHigh = i;
  }

  return indexHigh;
}
