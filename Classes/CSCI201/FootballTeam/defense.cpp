#include "defense.h"

// ---- DEFENSE CLASS ----
// Methods
std::string defense::toString() {
  return this->name + " (" + std::to_string(this->id) + "): Defense - " +
         this->getPlayerPosition();
}

// Constructors
defense::defense(std::string name, unsigned int id) : player(name, id) {}

// ---- DEFENSIVELINEMAN CLASS ----
// Methods
std::string defensivelineman::getPlayerPosition() {
  return "Defensive Lineman";
}

void defensivelineman::play() { /* Do something */
}

// Constructors
defensivelineman::defensivelineman(std::string name, unsigned int id)
    : defense(name, id) {}

// ---- LINEBACKER CLASS ----
// Methods
std::string linebacker::getPlayerPosition() { return "Linebacker"; }

void linebacker::play() { /* Do something */
}

// Constructors
linebacker::linebacker(std::string name, unsigned int id) : defense(name, id) {}

// ---- DEFENSIVEBACK CLASS ----
// Methods
std::string defensiveback::getPlayerPosition() { return "Defensive Back"; }

void defensiveback::play() { /* Do something */
}

// Constructors
defensiveback::defensiveback(std::string name, unsigned int id)
    : defense(name, id) {}
