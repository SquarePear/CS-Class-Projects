#include "game.h"

// Getters
unsigned int Game::getScore() { return this->score; }

// Methods
void Game::update() {
  this->tank->update();

  auto enemyTankIt = this->enemyTanks.begin();
  auto enemyTankEnd = enemyTankIt + this->enemyTanks.size() / 2;

  if (phase) {
    enemyTankIt = enemyTankEnd;
    enemyTankEnd = this->enemyTanks.end();
  }

  for (; enemyTankIt != enemyTankEnd; enemyTankIt++)
    (*enemyTankIt)->update();
}

stringstream Game::display() {
  // TODO: Display board
  stringstream disp;

  return disp;
}

bool Game::move(Tank *, direction) {
  // TODO: Validate and move tank
  return true;
}

void Game::fire(Tank *, direction) {
  // TODO: Fire projectile and check for damage
}

gameInfo Game::getInfo(Tank *) {
  // TODO: Process and return gameInfo object
  gameInfo info;

  return info;
}

// Overrides
Game::~Game() {
  delete tank;

  auto enemyTankIt = this->enemyTanks.begin();
  auto enemyTankEnd = this->enemyTanks.end();

  for (; enemyTankIt != enemyTankEnd; enemyTankIt++)
    delete *enemyTankIt;
};

// Constructors
Game::Game(unsigned int width, unsigned int height,
           unsigned int totalTanks = 4) {
  this->height = height;
  this->width = width;

  UserTank tank(this, position{0, 0});

  this->tank = &tank;

  for (int i = 0; i < totalTanks; i++) {
    position pos{rand() % width, rand() % height};

    bool valid = true;

    if (pos.x == 0 && pos.y == 0)
      valid = false;

    for (int j = 0; j < enemyTanks.size(); j++) {
      EnemyTank enemy = *(enemyTanks.at(j));

      if (!(pos.x == enemy.getPos().x && pos.y == enemy.getPos().y))
        continue;

      valid = false;
      return;
    }

    if (!valid && i-- >= 0)
      continue;

    enemyTanks.push_back(new EnemyTank(this, pos));
  }
}
