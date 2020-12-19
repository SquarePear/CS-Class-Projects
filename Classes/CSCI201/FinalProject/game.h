#pragma once

#include "helpers.h"
#include "tank.h"
#include "wall.h"
#include <cmath>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <string>
#include <vector>

class Tank;
class UserTank;
class EnemyTank;

class Game {
protected:
  // Properties
  int score;
  int height;
  int width;
  bool phase;
  UserTank *tank;
  std::vector<EnemyTank *> enemyTanks;
  std::vector<Wall> walls;

public:
  // Getters
  int getScore();

  // Methods
  void update();
  std::string display();
  bool canMove(Tank *, direction);
  void fire(Tank *, direction);
  gameInfo getInfo(Tank *);
  Wall *wallBetween(position, position);
  Tank *tankBetween(position, position);

  // Overrides
  ~Game();

  // Constructors
  Game(int, int, int);
};
