#include "date.h"

const string MONTH_NAMES[12] = {
    "January", "February", "March",     "April",   "May",      "June",
    "July",    "August",   "September", "October", "November", "December"};
const int MONTH_LENGTHS[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// Getters

int Date::getMonth() { return month; }

int Date::getDay() { return day; }

int Date::getYear() { return year; }

// Setters

void Date::setMonth(int m) {
  bool validMonth = (m >= 1 && m <= 12);

  if (!validMonth)
    throw string("The month must be a valid month (1-12)");

  month = m;
}

void Date::setDay(int d) {
  int maxDay = MONTH_LENGTHS[month - 1];

  bool yearIsDivisibleByFour = year / 4.0 == year / 4;
  bool isLeapMonth = (month == 2 && yearIsDivisibleByFour);

  if (isLeapMonth)
    maxDay++;

  bool validDay = (d >= 1 && d <= maxDay);

  if (!validDay)
    throw string("Invalid Value - There are " + std::to_string(maxDay) +
                 " days in the month of " + MONTH_NAMES[month - 1]);

  day = d;
}

void Date::setYear(int y) {
  bool validYear = (y >= 1900 && y <= 2020);

  if (!validYear)
    throw string("The year must be between 1900 and 2020");

  year = y;
}

// Methods

string Date::toString() {
  return MONTH_NAMES[month - 1] + " " + std::to_string(day) + ", " +
         std::to_string(year);
}

// Constructors

Date::Date(int month, int day, int year) {
  setMonth(month);
  setDay(day);
  setYear(year);
}
