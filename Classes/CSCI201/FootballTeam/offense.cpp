#include "offense.h"

// ---- OFFENSE CLASS ----
// Methods
std::string offense::toString() {
  return this->name + " (" + std::to_string(this->id) + "): Offense - " +
         this->getPlayerPosition();
}

// Constructors
offense::offense(std::string name, unsigned int id) : player(name, id) {}

// ---- QUARTERBACK CLASS ----
// Methods
std::string quarterback::getPlayerPosition() { return "QuarterBack"; }

void quarterback::play() { /* Do something */
}

// Constructors
quarterback::quarterback(std::string name, unsigned int id)
    : offense(name, id) {}

// ---- WIDERECEIVER CLASS ----
// Methods
std::string widereceiver::getPlayerPosition() { return "Wide Receiver"; }

void widereceiver::play() { /* Do something */
}

// Constructors
widereceiver::widereceiver(std::string name, unsigned int id)
    : offense(name, id) {}

// ---- TIGHTEND CLASS ----
// Methods
std::string tightend::getPlayerPosition() { return "Tight End"; }

void tightend::play() { /* Do something */
}

// Constructors
tightend::tightend(std::string name, unsigned int id) : offense(name, id) {}

// ---- RUNNINGBACK CLASS ----
// Methods
std::string runningback::getPlayerPosition() { return "Running Back"; }

void runningback::play() { /* Do something */
}

// Constructors
runningback::runningback(std::string name, unsigned int id)
    : offense(name, id) {}

// ---- OFFENSIVELINEMAN CLASS ----
// Methods
std::string offensivelineman::getPlayerPosition() {
  return "Offensive Lineman";
}

void offensivelineman::play() { /* Do something */
}

// Constructors
offensivelineman::offensivelineman(std::string name, unsigned int id)
    : offense(name, id) {}
