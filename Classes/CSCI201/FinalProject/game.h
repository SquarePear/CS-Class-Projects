#pragma once

#include "helpers.h"
#include "tank.h"
#include "wall.h"
#include <sstream>
#include <vector>

using std::stringstream;
using std::vector;

class Game {
protected:
  // Properties
  unsigned int score;
  unsigned int height;
  unsigned int width;
  vector<Tank> tanks;
  vector<Wall> walls;

public:
  // Methods
  void update();
  stringstream display();
  void fire(Tank, direction);
  void move(Tank, direction);

  // Constructors
  Game(unsigned int, unsigned int);
};
