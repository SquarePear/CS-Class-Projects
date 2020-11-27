#pragma once

#include <sstream>
#include <stdexcept>
#include <string>

class Beverage {
protected:
  // Properties
  std::string name;
  std::string description;
  unsigned int servingSize; // in milliliters
  unsigned int calories;    // per serving
  unsigned int price;

public:
  // Getters
  std::string getName();
  std::string getDescription();
  unsigned int getServingSize();
  unsigned int getCalories();
  unsigned int getPrice();

  // Setters
  void setPrice(unsigned int);

  // Methods
  std::string toString();

  // Constructors
  Beverage(std::string, std::string, unsigned int, unsigned int, unsigned int);
};
