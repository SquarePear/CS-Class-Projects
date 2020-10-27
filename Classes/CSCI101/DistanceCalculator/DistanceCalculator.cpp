/*
 *  Program name: Distance Calculator
 *  Author: Jeffrey Harmon
 *  Date created: Mar. 02, 2020
 *  Date last updated: Mar. 02, 2020
 *  Purpose: Calculate distance traveled over time
 */

#include <iomanip>
#include <iostream>

int main() {
  // Declaring variables
  int speed, time;

  // Getting user input
  do {
    std::cout << "What is the average speed of the vehicle? (≥0) ";
    std::cin >> speed;
  } while (speed < 0);

  do {
    std::cout << "How many hours has it traveled? (>1) ";
    std::cin >> time;
  } while (time < 1);

  std::cout << std::endl;

  // Displaying results
  std::cout << "Hour   Distance Traveled" << std::endl
            << "------------------------" << std::endl;

  // Looping for each hour
  for (int i = 0; i <= time; i++) {
    std::cout << i << "      " << i * speed << std::endl;
  }

  return 0;
}