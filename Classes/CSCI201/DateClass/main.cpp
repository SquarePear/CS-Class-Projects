/*
 *  Program name: DateClass
 *  Author: Jeffrey Harmon
 *  Date created: Nov. 2, 2020
 *  Date last updated: Nov. 2, 2020
 *  Purpose: Create, modify, and get info about a date
 */

#include "date.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
  int month, day, year;

  cout << "Make a date!" << endl;
  cout << "  Month: ";
  cin >> month;
  cout << "  Day: ";
  cin >> day;
  cout << "  Year: ";
  cin >> year;
  try {
    Date date(month, day, year);

    cout << "The date is: " << date.toString() << endl;

    cout << "Change the date!" << endl;
    cout << "  New Month: ";
    cin >> month;
    date.setMonth(month);
    cout << "  New Day: ";
    cin >> day;
    date.setDay(day);
    cout << "  New Year: ";
    cin >> year;
    date.setYear(year);
    cout << "The new date is: " << date.toString() << endl;
  } catch (string err) {
    cout << err << endl;
    return 1;
  }
}
