#pragma once

#include "helpers.h"

class Tank {
protected:
  // Properties
  unsigned int health;
  unsigned int x;
  position pos;

public:
  // Methods
  virtual void update();
  void move(direction);
  void hit();

  // Getters
  int getHealth();
  int getPos();
};
