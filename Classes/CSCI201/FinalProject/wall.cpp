#include "wall.h"

// Getters
position Wall::getPos() { return this->pos; }

wall_direction Wall::getDir() { return this->dir; }

bool Wall::isActive() { return this->active; }

bool Wall::isBreakable() { return this->breakable; }

// Methods
void Wall::hit() {
  if (this->isBreakable() && this->isActive())
    this->active = false;
}

// Constructor
Wall::Wall(position pos, wall_direction dir, bool active = true,
           bool breakable = false) {
  this->pos = pos;
  this->dir = dir;
  this->active = active;
  this->breakable = breakable;
}
