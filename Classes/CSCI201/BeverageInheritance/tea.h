#pragma once

#include "beverage.h"

#include <sstream>
#include <string>

enum TeaType { BLACK, OOLONG, GREEN, HERBAL, EARL_GREY };

class Tea : public Beverage {
protected:
  // Properties
  TeaType type;

public:
  // Properties
  bool isHot;
  bool hasLemon;
  bool hasCreamer;
  bool hasSweetener;

  // Getters
  TeaType getType();

  // Setters

  // Methods
  std::string toString();

  // Constructors
  Tea(std::string, std::string, unsigned int, unsigned int, unsigned int,
      TeaType, bool, bool, bool, bool);
};
