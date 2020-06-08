/* 
*  Program name: Triangle Validator
*  Author: Jeffrey Harmon
*  Date created: Feb. 17, 2020
*  Date last updated: Feb. 17, 2020
*  Purpose: Check if triangles are valid and/or right
*/

#include <iostream>

int main() {
	// Declaring variables
	int a;
	int b;
	int c;

	bool isValidTriangle = false;
	bool isRightAngle = false;

	// Asking user for input
	do {
		std::cout << "\nEnter length of side 1: ";
		std::cin >> a;

		if (a <= 0) std::cout << "Invalid input! Length must be greater than 0!" << std::endl;
	} while (a <= 0);

	do {
		std::cout << "\nEnter length of side 2: ";
		std::cin >> b;

		if (b <= 0) std::cout << "Invalid input! Length must be greater than 0!" << std::endl;
	} while (b <= 0);
	
	do {
		std::cout << "\nEnter length of side 3: ";
		std::cin >> c;

		if (c <= 0) std::cout << "Invalid input! Length must be greater than 0!" << std::endl;
	} while (c <= 0);

	std::cout << std::endl;

	// Checks that any two sides are always greater than the third side
	if (a + b > c && b + c > a && c + a > b) isValidTriangle = true;

	std::cout << ((isValidTriangle) ? "Triangle is valid!" : "Triangle is invalid!") << std::endl;

	// If triangle is not valid, exit. An invalid triangle cannot be a right triangle.
	if (!isValidTriangle) return 0;

	// Chacks that any two side's squares are greater than the third side's square
	if (a * a + b * b == c * c || b * b + c * c == a * a || c * c + a * a == b * b) isRightAngle = true;

	std::cout << ((isRightAngle) ? "Triangle is right angle!" : "Triangle is not right angle!") << std::endl;
}