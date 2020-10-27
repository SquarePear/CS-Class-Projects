/*
 *  Program name: Rainfall Statistics
 *  Author: Jeffrey Harmon
 *  Date created: Apr. 13, 2020
 *  Date last updated: Apr. 13, 2020
 *  Purpose: Display entered rainfall data
 */

#include <iomanip>
#include <iostream>

#define TOTAL_MONTHS 12

const std::string MONTHS[TOTAL_MONTHS] = {
    "January", "February", "March",     "April",   "May",      "June",
    "July",    "August",   "September", "October", "November", "December"};

int main() {
  system("clear");

  double rainfall[TOTAL_MONTHS] = {0};

  // Asking for input for each month
  for (int i = 0; i < TOTAL_MONTHS; i++) {
    std::cout << "Enter the amount of rainfall there was in " << MONTHS[i]
              << " (inches): ";

    while (!(std::cin >> rainfall[i]) || rainfall[i] < 0) {
      std::cout << "Invalid value! Please enter again: ";

      std::cin.clear();
      std::cin.ignore(1000, '\n');
    }

    std::cout << std::endl;
  }

  // Calculate and store different statistics
  double totalRainfall = 0;
  int wettestMonth = 0;
  int driestMonth = 0;

  for (int i = 0; i < TOTAL_MONTHS; i++) {
    totalRainfall += rainfall[i];

    if (rainfall[i] < rainfall[driestMonth])
      driestMonth = i;
    if (rainfall[i] > rainfall[wettestMonth])
      wettestMonth = i;
  }

  // Outputting information
  std::cout << std::fixed << std::setprecision(2) << std::endl;

  std::cout << "Annual Rain Report for Hancock County" << std::endl;
  std::cout << "Total rainfall: " << totalRainfall << " inches" << std::endl;
  std::cout << "Average monthly rainfall: " << totalRainfall / TOTAL_MONTHS
            << " inches" << std::endl;
  std::cout << "The least rain fell in " << MONTHS[driestMonth] << " with "
            << rainfall[driestMonth] << " inches" << std::endl;
  std::cout << "The most rain fell in " << MONTHS[wettestMonth] << " with "
            << rainfall[wettestMonth] << " inches" << std::endl;

  return 0;
}