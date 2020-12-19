#pragma once

#include "helpers.h"

class Wall {
protected:
  // Properties
  position pos;
  wall_direction dir;
  bool active = true;
  bool breakable = false;

public:
  // Getters
  position getPos();
  wall_direction getDir();
  bool isActive();
  bool isBreakable();

  // Methods
  void hit();

  // Constructor
  Wall(position, wall_direction, bool, bool);
};
