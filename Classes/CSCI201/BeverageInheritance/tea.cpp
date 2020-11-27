#include "tea.h"

// Getters
TeaType Tea::getType() { return this->type; }

// Setters

// Methods
std::string Tea::toString() {
  std::stringstream ss;

  ss << Beverage::toString();

  return ss.str();
}

// Constructors
Tea::Tea(std::string name, std::string description, unsigned int servingSize,
         unsigned int calories, unsigned int price, TeaType type, bool isHot,
         bool hasLemon, bool hasCreamer, bool hasSweetener)
    : Beverage(name, description, servingSize, calories, price) {
  this->type = type;
  this->isHot = isHot;
  this->hasLemon = hasLemon;
  this->hasCreamer = hasCreamer;
  this->hasSweetener = hasSweetener;
}
