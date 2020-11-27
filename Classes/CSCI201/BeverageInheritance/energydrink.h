#pragma once

#include "beverage.h"

#include <sstream>
#include <string>

enum StimulantType { CAFFEINE, TAURINE };

class EnergyDrink : public Beverage {
protected:
  // Properties
  std::string brand;
  StimulantType stimulant;

public:
  // Properties
  bool hasSweetener;

  // Getters
  std::string getBrand();
  StimulantType getStimulant();

  // Setters

  // Methods
  std::string toString();

  // Constructors
  EnergyDrink(std::string, std::string, unsigned int, unsigned int,
              unsigned int, std::string, StimulantType, bool);
};
