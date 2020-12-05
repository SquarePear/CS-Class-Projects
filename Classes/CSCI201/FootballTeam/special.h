#pragma once

#include "player.h"
#include <string>

class special : public player {
public:
  // Methods
  std::string toString();

  // Constructors
  special(std::string, unsigned int);
};

class kicker : public special {
public:
  // Methods
  std::string getPlayerPosition();
  void play();

  // Constructors
  kicker(std::string, unsigned int);
};

class holder : public special {
public:
  // Methods
  std::string getPlayerPosition();
  void play();

  // Constructors
  holder(std::string, unsigned int);
};

class punter : public special {
public:
  // Methods
  std::string getPlayerPosition();
  void play();

  // Constructors
  punter(std::string, unsigned int);
};

class returner : public special {
public:
  // Methods
  std::string getPlayerPosition();
  void play();

  // Constructors
  returner(std::string, unsigned int);
};