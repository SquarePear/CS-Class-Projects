#pragma once

#include "player.h"
#include <string>

class offense : public player {
public:
  // Methods
  std::string toString();

  // Constructors
  offense(std::string, unsigned int);
};

class quarterback : public offense {
public:
  // Methods
  std::string getPlayerPosition();
  void play();

  // Constructors
  quarterback(std::string, unsigned int);
};

class widereceiver : public offense {
public:
  // Methods
  std::string getPlayerPosition();
  void play();

  // Constructors
  widereceiver(std::string, unsigned int);
};

class tightend : public offense {
public:
  // Methods
  std::string getPlayerPosition();
  void play();

  // Constructors
  tightend(std::string, unsigned int);
};

class runningback : public offense {
public:
  // Methods
  std::string getPlayerPosition();
  void play();

  // Constructors
  runningback(std::string, unsigned int);
};

class offensivelineman : public offense {
public:
  // Methods
  std::string getPlayerPosition();
  void play();

  // Constructors
  offensivelineman(std::string, unsigned int);
};
