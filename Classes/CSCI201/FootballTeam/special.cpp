#include "special.h"

// ---- SPECIAL CLASS ----
// Methods
std::string special::toString() {
  return this->name + " (" + std::to_string(this->id) + "): Special - " +
         this->getPlayerPosition();
}

// Constructors
special::special(std::string name, unsigned int id) : player(name, id) {}

// ---- KICKER CLASS ----
// Methods
std::string kicker::getPlayerPosition() { return "Kicker"; }

void kicker::play() { /* Do something */
}

// Constructors
kicker::kicker(std::string name, unsigned int id) : special(name, id) {}

// ---- HOLDER CLASS ----
// Methods
std::string holder::getPlayerPosition() { return "Holder"; }

void holder::play() { /* Do something */
}

// Constructors
holder::holder(std::string name, unsigned int id) : special(name, id) {}

// ---- PUNTER CLASS ----
// Methods
std::string punter::getPlayerPosition() { return "Punter"; }

void punter::play() { /* Do something */
}

// Constructors
punter::punter(std::string name, unsigned int id) : special(name, id) {}

// ---- RETURNER CLASS ----
// Methods
std::string returner::getPlayerPosition() { return "Returner"; }

void returner::play() { /* Do something */
}

// Constructors
returner::returner(std::string name, unsigned int id) : special(name, id) {}
