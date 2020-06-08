/* 
*  Program name: Tip Calculator
*  Author: Jeffrey Harmon
*  Date created: Feb. 12, 2020
*  Date last updated: Feb. 12, 2020
*  Purpose: Take input from the user and output the bill for a meal
*/

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double roundToDecimalPlace(double val, int place) {
	return round(val * pow(10.0, place)) / pow(10.0, place);
}

int main() {
	double mealCharge;

	cout << "How much did the meal cost?\n$";
	cin >> mealCharge;
	cout << endl;

	double tipPercentage = 0;

	while (!tipPercentage) {
		cout << "What percentage tip would you like to give?\na) 15%\nb) 20%\nc) 25%\nChoice: ";
		char choice;
		cin >> choice;
		switch (choice) {
			case 'a':
				tipPercentage = 0.15;
				break;
			case 'b':
				tipPercentage = 0.2;
				break;
			case 'c':
				tipPercentage = 0.25;
				break;
			default:
				break;
		}

		cout << endl;
	}

	cout << "Meal Cost: $" << roundToDecimalPlace(mealCharge, 2) << endl;
	cout << "Tax (6.75%): $" << roundToDecimalPlace(mealCharge * 0.0675, 2) << endl;
	cout << "Tip (" << tipPercentage * 100 << "%): $" << roundToDecimalPlace(mealCharge * tipPercentage, 2) << endl;
	cout << "Total Cost: $" << roundToDecimalPlace(mealCharge + mealCharge * tipPercentage + mealCharge * 0.0675, 2) << endl;
}