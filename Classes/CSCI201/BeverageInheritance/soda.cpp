#include "soda.h"

// Getters
std::string Soda::getBrand() { return this->brand; }

SodaType Soda::getType() { return this->type; }

// Setters

// Methods
std::string Soda::toString() {
  std::stringstream ss;

  ss << Beverage::toString();

  return ss.str();
}

// Constructors
Soda::Soda(std::string name, std::string description, unsigned int servingSize,
           unsigned int calories, unsigned int price, std::string brand,
           SodaType type, bool isDiet)
    : Beverage(name, description, servingSize, calories, price) {
  this->brand = brand;
  this->type = type;
  this->isDiet = isDiet;
}
