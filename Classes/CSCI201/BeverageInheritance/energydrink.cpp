#include "energydrink.h"

// Getters
std::string EnergyDrink::getBrand() { return this->brand; }

StimulantType EnergyDrink::getStimulant() { return this->stimulant; }

// Setters

// Methods
std::string EnergyDrink::toString() {
  std::stringstream ss;

  ss << Beverage::toString();

  return ss.str();
}

// Constructors
EnergyDrink::EnergyDrink(std::string name, std::string description,
                         unsigned int servingSize, unsigned int calories,
                         unsigned int price, std::string brand,
                         StimulantType stimulant, bool hasSweetener)
    : Beverage(name, description, servingSize, calories, price) {
  this->brand = brand;
  this->stimulant = stimulant;
  this->hasSweetener = hasSweetener;
}
