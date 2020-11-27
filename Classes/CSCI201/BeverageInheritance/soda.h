#pragma once

#include "beverage.h"

#include <sstream>
#include <string>

enum SodaType { COLA, LEMON_LIME, BIRCH };

class Soda : public Beverage {
protected:
  // Properties
  std::string brand;
  SodaType type;

public:
  // Properties
  bool isDiet;

  // Getters
  std::string getBrand();
  SodaType getType();

  // Setters

  // Methods
  std::string toString();

  // Constructors
  Soda(std::string, std::string, unsigned int, unsigned int, unsigned int,
       std::string, SodaType, bool);
};
