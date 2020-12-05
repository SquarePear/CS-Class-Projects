#pragma once

#include <string>

class player {
protected:
  std::string name;
  unsigned int id;

public:
  // Getters
  std::string getName();
  unsigned int getID();

  // Methods
  virtual std::string getPlayerPosition() = 0;
  virtual void play() = 0;
  virtual std::string toString() = 0;

  // Constructors
  player(std::string, unsigned int);
};
