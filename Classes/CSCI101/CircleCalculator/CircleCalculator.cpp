/*
 *  Program name: Circle Calculator
 *  Author: Jeffrey Harmon
 *  Date created: Apr. 09, 2020
 *  Date last updated: Apr. 09, 2020
 *  Purpose: Calculate the measurements of a circle from two points
 */

#include <cmath>
#include <iomanip>
#include <iostream>

#define PI std::acos(-1)

double calculateRadius(double x1, double y1, double x2, double y2);
double calculateArea(double radius);
double calculatePerimeter(double radius);

int main() {
  int x1 = 0;
  int y1 = 0;
  int x2 = 0;
  int y2 = 0;

  // Clearing terminal
  std::system("clear");

  // Input + Validation
  std::cout << "Enter the first point (x, y): " << std::endl;

  std::cout << "x: ";

  while (!(std::cin >> x1)) {
    std::cout << "Invalid value! Enter again: ";

    std::cin.clear();
    std::cin.ignore(1000, '\n');
  }

  std::cout << "y: ";

  while (!(std::cin >> y1)) {
    std::cout << "Invalid value! Enter again: ";

    std::cin.clear();
    std::cin.ignore(1000, '\n');
  }

  std::cout << std::endl << "Enter the second point (x, y): " << std::endl;

  std::cout << "x: ";

  while (!(std::cin >> x2)) {
    std::cout << "Invalid value! Enter again: ";

    std::cin.clear();
    std::cin.ignore(1000, '\n');
  }

  std::cout << "y: ";

  while (!(std::cin >> y2)) {
    std::cout << "Invalid value! Enter again: ";

    std::cin.clear();
    std::cin.ignore(1000, '\n');
  }

  // Calculating and outputing circle measurements
  std::cout << std::endl << "--- Circle Measurements ---" << std::endl;

  double radius = calculateRadius(x1, y1, x2, y2);

  std::cout << "Radius: " << radius << std::endl;
  std::cout << "Area: " << calculateArea(radius) << std::endl;
  std::cout << "Perimeter: " << calculatePerimeter(radius) << std::endl;

  return 0;
}

double calculateRadius(double x1, double y1, double x2, double y2) {
  // sqrt((x2 - x1)^2 + (y2 - y1)^2)
  return std::sqrt(std::pow(x2 - x1, 2) + std::pow(y2 - y1, 2));
}

double calculateArea(double radius) {
  // πr^2
  return PI * std::pow(radius, 2);
}

double calculatePerimeter(double radius) {
  // 2πr
  return 2 * PI * radius;
}