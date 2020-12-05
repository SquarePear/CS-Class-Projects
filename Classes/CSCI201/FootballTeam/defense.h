#pragma once

#include "player.h"
#include <string>

class defense : public player {
public:
  // Methods
  std::string toString();

  // Constructors
  defense(std::string, unsigned int);
};

class defensivelineman : public defense {
public:
  // Methods
  std::string getPlayerPosition();
  void play();

  // Constructors
  defensivelineman(std::string, unsigned int);
};

class linebacker : public defense {
public:
  // Methods
  std::string getPlayerPosition();
  void play();

  // Constructors
  linebacker(std::string, unsigned int);
};

class defensiveback : public defense {
public:
  // Methods
  std::string getPlayerPosition();
  void play();

  // Constructors
  defensiveback(std::string, unsigned int);
};
