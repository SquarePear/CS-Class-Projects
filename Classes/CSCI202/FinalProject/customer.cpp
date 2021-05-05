#include "customer.h"
#include <cmath>
#include <string>

// Getters
unsigned int Customer::getID() const { return this->ID; }

std::string Customer::getName() const { return this->name; }

// Methods
std::string Customer::toString() const {
  return std::to_string(this->ID) + " - " + this->name;
}

// Overrides
bool Customer::operator<(const Customer &o) const {
  return this->ID < o.getID();
};

// Constructors
Customer::Customer(unsigned short ID, std::string name) : name(name) {
  if (std::trunc(std::log10(ID)) + 1 != 4)
    throw std::invalid_argument("ID must be 4 digits!");

  this->ID = ID;
}
