#pragma once

#define TOTAL_DIRS 4

enum direction { NORTH, EAST, SOUTH, WEST };

enum wall_direction { VERTICAL, HORIZONTAL };

struct position {
  unsigned int x;
  unsigned int y;
};

struct gameInfo {
  int wallInDir[TOTAL_DIRS];
  bool enemyInDir[TOTAL_DIRS];
};
