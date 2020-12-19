#pragma once

#define TOTAL_DIRS 4

enum direction { NORTH, EAST, SOUTH, WEST };

enum wall_direction { VERTICAL, HORIZONTAL };

struct position {
  int x;
  int y;
};

struct gameInfo {
  int wallInDir[TOTAL_DIRS];
  bool enemyInDir[TOTAL_DIRS];
};
