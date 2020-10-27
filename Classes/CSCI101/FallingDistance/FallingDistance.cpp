/*
 *  Program name: Falling Distance Calculator
 *  Author: Jeffrey Harmon
 *  Date created: Apr. 01, 2020
 *  Date last updated: Apr. 01, 2020
 *  Purpose: Calculate falling distance
 */

#include <iomanip>
#include <iostream>

const double G = 9.81;

double fallingDistance(int fallingTime);

int main() {
  // Clear terminal window (May not work in Windows)
  system("clear");

  int fallTime;

  std::cout << "Enter total falling time in seconds: ";

  // Geting input with validation
  while (!(std::cin >> fallTime) || fallTime <= 0) {
    std::cin.clear();
    std::cin.ignore(1000, '\n');
    std::cout << "Time must be an integer greater than 0!" << std::endl
              << "Enter again: ";
  }

  // Output with formatting
  std::cout << "Time (s)    Distance (m)" << std::endl;

  for (int i = 0; i <= fallTime; i++) {
    std::cout << std::setw(12) << std::left << i << std::right
              << fallingDistance(i) << std::endl;
  }

  return 0;
}

// Calculate falling distance after time
double fallingDistance(int fallingTime) {
  return G * fallingTime * fallingTime / 2;
}