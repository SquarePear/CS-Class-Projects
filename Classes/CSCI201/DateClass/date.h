#ifndef DATE_H
#define DATE_H
#include <string>

using std::string;

class Date {
private:
  // Properties
  int month;
  int day;
  int year;

public:
  // Getters
  int getMonth();
  int getDay();
  int getYear();

  // Setters
  void setMonth(int);
  void setDay(int);
  void setYear(int);

  // Methods
  string toString();

  // Constructors
  Date(int, int, int);
};

#endif
