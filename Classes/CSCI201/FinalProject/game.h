#pragma once

#include "helpers.h"
#include "tank.h"
#include "wall.h"
#include <sstream>
#include <vector>

using std::stringstream;
using std::vector;

class Tank;
class UserTank;
class EnemyTank;

class Game {
protected:
  // Properties
  unsigned int score;
  unsigned int height;
  unsigned int width;
  bool phase;
  UserTank *tank;
  vector<EnemyTank *> enemyTanks;
  vector<Wall> walls;

public:
  // Getters
  unsigned int getScore();

  // Methods
  void update();
  stringstream display();
  bool move(Tank *, direction);
  void fire(Tank *, direction);
  gameInfo getInfo(Tank *);

  // Overrides
  ~Game();

  // Constructors
  Game(unsigned int, unsigned int, unsigned int);
};
