#include "player.h"

// Getters
std::string player::getName() { return this->name; }
unsigned int player::getID() { return this->id; }

// Constructors
player::player(std::string name, unsigned int id) {
  this->name = name;
  this->id = id;
}