/*
 *  Program name: BMI Calculator
 *  Author: Jeffrey Harmon
 *  Date created: Feb. 25, 2020
 *  Date last updated: Feb. 25, 2020
 *  Purpose: Check and evaluate the user's BMI
 */

#include <iomanip>
#include <iostream>

int main() {
  double weight;
  double height;

  // Getting and setting the user's weight
  do {
    std::cout << "\nEnter your weight in pounds: ";
    std::cin >> weight;

    if (weight <= 0)
      std::cout << "Invalid input! Weight must be greater than 0!" << std::endl;
  } while (weight <= 0);

  // Getting and setting the user's height
  do {
    std::cout << "\nEnter your height in inches: ";
    std::cin >> height;

    if (height <= 0)
      std::cout << "Invalid input! Height must be greater than 0!" << std::endl;
  } while (height <= 0);

  // Calculating the BMI
  double BMI = weight * 703 / (height * height);

  // Setting precision of output to 3 so there is only one decimal place and
  // displaying BMI
  std::cout << std::setprecision(3) << "\nYour BMI is " << BMI << std::endl;

  // Adding spacing
  std::cout << std::endl;

  // Checking the range the user's BMI is in
  if (BMI > 25)
    std::cout << "You are overweight";
  else if (BMI < 18.5)
    std::cout << "You are underweight";
  else
    std::cout << "You are a healthy weight";

  std::cout << " according to your BMI" << std::endl;

  // Finish the program
  return 0;
}