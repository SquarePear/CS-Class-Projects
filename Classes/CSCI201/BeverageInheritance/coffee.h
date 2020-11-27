#pragma once

#include "beverage.h"
#include <sstream>
#include <string>

enum RoastType { LIGHT, MEDIUM, DARK, FRENCH_ROAST, ESPRESSO };

class Coffee : public Beverage {
protected:
  // Properties
  RoastType type;

public:
  // Properties
  bool isHot;
  bool isCaffeinated;
  bool hasCreamer;
  bool hasSweetener;

  // Getters
  RoastType getType();

  // Setters

  // Methods
  std::string toString();

  // Constructors
  Coffee(std::string, std::string, unsigned int, unsigned int, unsigned int,
         RoastType, bool, bool, bool, bool);
};
