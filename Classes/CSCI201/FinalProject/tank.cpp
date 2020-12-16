#include "tank.h"

// TANK CLASS
// Getters
int Tank::getHealth() { return this->health; }

int Tank::getPower() { return this->power; }

position Tank::getPos() { return this->pos; }

// Methods
void Tank::update() {}

bool Tank::move(direction dir) { return this->game->move(this, dir); }

void Tank::fire(direction dir) { this->game->fire(this, dir); }

void Tank::hit(unsigned int power) { this->health -= power; }

// Constructors
Tank::Tank(Game *game, position pos) {
  this->game = game;
  this->pos = pos;
}

// USERTANK CLASS
// Methods
void UserTank::update() {
  unsigned int choice;
  std::cout << "What do you want to do?" << std::endl;
  std::cout << "1: MOVE:" << std::endl;
  std::cout << "2: FIRE" << std::endl;
  std::cout << "Choice: " << std::endl;

  if (!(std::cin >> choice) || choice > 2)
    throw std::out_of_range("Invalid choice!");

  unsigned int dirChoice;

  std::cout << "Which direction?" << std::endl;
  std::cout << "1: NORTH" << std::endl;
  std::cout << "2: EAST:" << std::endl;
  std::cout << "3: SOUTH:" << std::endl;
  std::cout << "4: WEST:" << std::endl;
  std::cout << "Direction: " << std::endl;

  if (!(std::cin >> dirChoice) || dirChoice > TOTAL_DIRS)
    throw std::out_of_range("Invalid direction!");

  direction dir = static_cast<direction>(dirChoice);

  if (choice == 1)
    this->move(dir);
  else
    this->fire(dir);
}

// ENEMYTANK CLASS
// Methods
void EnemyTank::update() {
  gameInfo info = this->game->getInfo(this);

  for (int i = 0; i < TOTAL_DIRS; i++) {
    direction currentDir = static_cast<direction>(i);

    if (info.enemyInDir[currentDir])
      return this->fire(currentDir);
  }

  bool success = false;

  do {
    direction randomDir = static_cast<direction>(rand() % TOTAL_DIRS);

    success = this->move(randomDir);
  } while (!success);
}
