#include "game.h"

int positionDistance(position a, position b) {
  if ((a.x == b.x) != (a.y == b.y))
    return 999;

  return std::abs(((a.x == b.x) ? a.x - b.x : a.y - b.y) * 1.0);
}

// Getters
int Game::getScore() { return this->score; }

// Methods
void Game::update() {
  bool success = false;
  while (!success) {
    try {
      this->tank->update();
      success = true;
    } catch (const std::exception &e) {
      std::cout << e.what() << std::endl << std::endl;
    }
  }

  for (int i = 0; i < this->enemyTanks.size(); i++)
    this->enemyTanks.at(i)->update();
}

std::string Game::display() {
  std::stringstream disp;

  for (int i = 0; i < 10; i++)
    disp << std::endl << std::endl << std::endl << std::endl << std::endl;

  position maxPos{this->width * 2, this->height * 2};

  for (int y = 0; y <= maxPos.y; y++) {
    for (int x = 0; x <= maxPos.x; x++) {
      bool vertWall = false;
      bool horWall = false;
      bool breakable = false;
      bool enemy = false;
      bool player = false;

      disp << "  ";

      if (x % 2 == 0)
        vertWall = true;
      if (y % 2 == 0)
        horWall = true;

      if (horWall != vertWall) {
        position pos{x / 2, y / 2};

        wall_direction dir = (horWall) ? HORIZONTAL : VERTICAL;

        for (int i = 0; i < this->walls.size(); i++) {
          Wall *wall = &this->walls.at(i);

          if (!(wall->getDir() == dir && wall->getPos().x == pos.x &&
                wall->getPos().y == pos.y))
            continue;

          breakable = wall->isBreakable();

          if (horWall)
            horWall = wall->isActive();
          if (vertWall)
            vertWall = wall->isActive();
        }
      }

      if (x % 2 == 1 && y % 2 == 1) {
        position pos{(x - 1) / 2, (y - 1) / 2};

        if (this->tank->getPos().x == pos.x && this->tank->getPos().y == pos.y)
          player = true;
        else
          for (int i = 0; i < this->enemyTanks.size(); i++)
            if (this->enemyTanks.at(i)->getPos().x == pos.x &&
                this->enemyTanks.at(i)->getPos().y == pos.y)
              enemy = true;
      }

      if (vertWall && horWall)
        disp << '+';
      else if (vertWall && breakable)
        disp << '}';
      else if (horWall && breakable)
        disp << '~';
      else if (vertWall)
        disp << '|';
      else if (horWall)
        disp << '-';
      else if (player)
        disp << '@';
      else if (enemy)
        disp << '$';
      else
        disp << ' ';

      disp << "  ";
    }

    disp << std::endl << std::endl;
  }

  disp << std::endl << std::endl;

  return disp.str();
}

bool Game::canMove(Tank *tank, direction dir) {
  // TODO: Validate and move tank

  position oldPos = tank->getPos();
  position newPos;

  switch (dir) {
  case NORTH:
    newPos.x = oldPos.x;
    newPos.y = oldPos.y - 1;
  case EAST:
    newPos.x = oldPos.x + 1;
    newPos.y = oldPos.y;
    break;
  case SOUTH:
    newPos.x = oldPos.x;
    newPos.y = oldPos.y + 1;
    break;
  case WEST:
  default:
    newPos.x = oldPos.x - 1;
    newPos.y = oldPos.y;
    break;
  }

  Wall *wallBetween = this->wallBetween(oldPos, newPos);

  if (!wallBetween->isActive())
    return false;

  return true;
}

void Game::fire(Tank *tank, direction dir) {
  // TODO: Fire projectile and check for damage

  position curPos = tank->getPos();

  position checkPos;

  switch (dir) {
  case NORTH:
    checkPos = {curPos.x, 0};
    break;
  case EAST:
    checkPos = {this->width, curPos.y};
    break;
  case SOUTH:
    checkPos = {curPos.x, this->height};
    break;
  case WEST:
    checkPos = {0, curPos.y};
  default:
    break;
  }

  Tank *closestTank = this->tankBetween(curPos, checkPos);

  if (closestTank == nullptr)
    return;

  Wall *closestWall = this->wallBetween(curPos, checkPos);

  if (!(positionDistance(curPos, closestTank->getPos()) <
        positionDistance(curPos, closestWall->getPos())))
    return;

  closestTank->hit(tank->getPower());
}

gameInfo Game::getInfo(Tank *tank) {
  // TODO: Process and return gameInfo object
  gameInfo info;

  position curPos = tank->getPos();

  for (int i = 0; i < TOTAL_DIRS; i++) {
    direction dir = static_cast<direction>(i);

    position checkPos;

    switch (dir) {
    case NORTH:
      checkPos = {curPos.x, 0};
      break;
    case EAST:
      checkPos = {width - 1, curPos.y};
      break;
    case SOUTH:
      checkPos = {curPos.x, height - 1};
      break;
    case WEST:
    default:
      checkPos = {0, curPos.y};
      break;
    }

    Tank *closestTank = this->tankBetween(curPos, checkPos);
    Wall *closestWall = this->wallBetween(curPos, checkPos);

    if (closestWall == nullptr)
      info.wallInDir[i] = 0;
    else
      info.wallInDir[i] = positionDistance(curPos, closestWall->getPos());

    info.enemyInDir[i] =
        closestTank != nullptr &&
        positionDistance(curPos, closestTank->getPos()) < info.wallInDir[i];
  }

  return info;
}

Wall *Game::wallBetween(position a, position b) {
  std::cout << "Wall: " << a.x << ", " << a.y << " | " << b.x << ", " << b.y
            << std::endl;

  if (!((a.x == b.x) != (a.y == b.y)))
    return nullptr;

  std::cout << "test wall" << std::endl;

  position pos{a.x, a.y};
  std::cout << "test wall2" << std::endl;

  int dir = 1, start = 1, end = 1;

  if (a.y == b.y) {
    std::cout << "test wall x" << std::endl;
    end = b.x - a.x;

    if (a.x > b.x) {
      dir = -1;
      start = 0;
      end = a.x - b.x;
    }

    for (int xMod = start; xMod <= end; xMod++) {
      std::cout << "test wall " << start << " | " << end << std::endl;

      pos.x = a.x + xMod * dir;

      for (int i = 0; i < this->walls.size(); i++) {
        Wall *wall = &this->walls.at(i);

        if (wall->getDir() != VERTICAL)
          continue;

        if (wall->getPos().x == pos.x && wall->getPos().y == pos.y &&
            wall->isActive())
          return wall;
      }
    }
  } else if (a.x == b.x) {

    std::cout << "test wall y" << std::endl;
    end = b.y - a.y;
    if (a.y > b.y) {
      dir = -1;
      start = 0;
      end = a.y - b.y;
    }

    for (int yMod = start; yMod <= end; yMod++) {
      pos.y = a.y + yMod * dir;

      for (int i = 0; i < this->walls.size(); i++) {
        Wall *wall = &this->walls.at(i);

        if (wall->getDir() != HORIZONTAL)
          continue;

        if (wall->getPos().x == pos.x && wall->getPos().y == pos.y)
          return wall;
      }
    }
  }

  return nullptr;
};

Tank *Game::tankBetween(position a, position b) {
  std::cout << "Tank: " << a.x << ", " << a.y << " | " << b.x << ", " << b.y
            << std::endl;

  if (!((a.x == b.x) != (a.y == b.y)))
    return nullptr;

  std::cout << "test tank" << std::endl;

  position pos{a.x, a.y};

  int dir = 1, start = 1, end = 1;

  if (a.y == b.y) {
    end = b.x - a.x;

    if (a.x > b.x) {
      dir = -1;
      start = 0;
      end = a.x - b.x;
    }

    for (int xMod = start; xMod <= end; xMod++) {
      pos.x = a.x + xMod * dir;

      if (this->tank->getPos().x == pos.x && this->tank->getPos().y == pos.y)
        return this->tank;

      for (int i = 0; i < this->enemyTanks.size(); i++) {
        Tank *tank = this->enemyTanks.at(i);

        if (tank->getPos().x == pos.x && tank->getPos().y == pos.y)
          return tank;
      }
    }
  } else if (a.x == b.x) {
    end = b.y - a.y;
    if (a.y > b.y) {
      dir = -1;
      start = 0;
      end = a.y - b.y;
    }

    for (int yMod = start; yMod <= end; yMod++) {
      pos.y = a.y + yMod * dir;

      if (this->tank->getPos().x == pos.x && this->tank->getPos().y == pos.y)
        return this->tank;

      for (int i = 0; i < this->enemyTanks.size(); i++) {
        Tank *tank = this->enemyTanks.at(i);

        if (tank->getPos().x == pos.x && tank->getPos().y == pos.y)
          return tank;
      }
    }
  }

  return nullptr;
};

// Overrides
Game::~Game() {
  delete tank;

  auto enemyTankIt = this->enemyTanks.begin();
  auto enemyTankEnd = this->enemyTanks.end();

  for (; enemyTankIt != enemyTankEnd; enemyTankIt++)
    delete *enemyTankIt;
};

// Constructors
Game::Game(int width, int height, int totalTanks = 4) {
  this->height = height;
  this->width = width;

  this->tank = new UserTank(this, position{0, 0});

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

  for (int x = 0; x <= width; x++) {
    for (int y = 0; y <= height; y++) {
      bool active = true;
      bool breakable = false;

      if (x <= width) {
        if (x != 0 && x != width) {
          active = rand() % 10 < 3;
          breakable = rand() % 10 == 1;
        }

        Wall wall(position{x, y}, VERTICAL, active, breakable);

        this->walls.push_back(wall);
      }

      active = true;
      breakable = false;

      if (y <= height) {
        if (y != 0 && y != height) {
          active = rand() % 10 < 3;
          breakable = rand() % 10 == 1;
        }

        Wall wall(position{x, y}, HORIZONTAL, active, breakable);

        this->walls.push_back(wall);
      }
    }
  }
}
