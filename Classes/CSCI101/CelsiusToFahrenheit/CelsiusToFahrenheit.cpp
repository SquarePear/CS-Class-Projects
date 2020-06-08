/* 
*  Program name: Celsius to Fahrenheit
*  Author: Jeffrey Harmon
*  Date created: Mar. 26, 2020
*  Date last updated: Mar. 26, 2020
*  Purpose: Convert a range of Celsius values into Fahrenheit
*/

#include <iostream>
#include <iomanip>

// Function prototype
double celsiusToFahrenheit(int celsius);

int main() {
	int upperCelsius, lowerCelsius;

	// Input validation loop
	do {
		std::cout << "Enter a value for the lower Celsius temperature (whole numbers only): ";
		std::cin >> lowerCelsius;

		std::cout << "Enter a value for the upper Celsius temperature (whole numbers only): ";
		std::cin >> upperCelsius;

		if (lowerCelsius >= upperCelsius) std::cout << "\nLower value must be less than upper value!\n" << std::endl;
	} while (lowerCelsius >= upperCelsius);

	// Adding spacing
	std::cout << std::endl;

	// Loop to display all of the conversions
	for (int i = lowerCelsius; i <= upperCelsius; i++) {
		// A bunch of output/formating to display results
		std::cout << std::setw(8) << std::left << std::to_string(i) + "°C";
		std::cout << " | ";
		std::cout << std::setw(8) << std::right << celsiusToFahrenheit(i) << "°F" << std::endl;
	}

	return 0;
}

// Function to convert Celsius to Fahrenheit
double celsiusToFahrenheit(int celsius) {
	return 1.8 * celsius + 32;
}