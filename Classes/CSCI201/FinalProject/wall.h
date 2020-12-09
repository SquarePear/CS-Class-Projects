#pragma once

#include "helpers.h"
#include "tank.h"
#include <sstream>
#include <vector>

using std::stringstream;
using std::vector;

class Wall {
protected:
  // Properties
  bool active = true;
  bool breakable = false;

public:
  // Getters
  bool isActive();
  bool isBreakable();

  // Methods
  void hit();
};
