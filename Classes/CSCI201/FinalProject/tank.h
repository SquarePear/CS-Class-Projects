#pragma once

#include "game.h"
#include "helpers.h"
#include "iostream"

class Game;

class Tank {
protected:
  // Properties
  unsigned int health = 1;
  unsigned int power = 1;
  position pos;
  Game *game;

public:
  // Getters
  int getHealth();
  int getPower();
  position getPos();

  // Methods
  virtual void update();
  bool move(direction);
  void fire(direction);
  void hit(unsigned int);

  // Constructors
  Tank(Game *, position);
};

class UserTank : public Tank {
protected:
  // Properties
  unsigned int health = 2;

public:
  // Methods
  void update();

  // Constructors
  UserTank(Game *game, position pos) : Tank(game, pos){};
};

class EnemyTank : public Tank {
protected:
  // Properties
  unsigned int health = 1;

public:
  // Methods
  void update();

  // Constructors
  EnemyTank(Game *game, position pos) : Tank(game, pos){};
};