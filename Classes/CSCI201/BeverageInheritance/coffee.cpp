#include "coffee.h"

// Getters
RoastType Coffee::getType() { return this->type; }

// Setters

// Methods
std::string Coffee::toString() {
  std::stringstream ss;

  ss << Beverage::toString();

  return ss.str();
}

// Constructors
Coffee::Coffee(std::string name, std::string description,
               unsigned int servingSize, unsigned int calories,
               unsigned int price, RoastType type, bool isHot,
               bool isCaffeinated, bool hasCreamer, bool hasSweetener)
    : Beverage(name, description, servingSize, calories, price) {
  this->type = type;
  this->isHot = isHot;
  this->isCaffeinated = isCaffeinated;
  this->hasCreamer = hasCreamer;
  this->hasSweetener = hasSweetener;
}
