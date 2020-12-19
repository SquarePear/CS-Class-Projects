/*
 *  Program name: CSCI 201 Final Project - Tank Game
 *  Author: Jeffrey Harmon
 *  Date created: Dec. 9, 2020
 *  Date last updated: Dec. 18, 2020
 *  Purpose: Control a tank to navigate a maze
 */

#include "game.h"
#include "tank.h"
#include <iostream>
#include <stdlib.h>
#include <string>
#include <time.h>

using namespace std;

int main() {
  int width, height, enemyCount;

  srand(time(NULL));

  cout << "What size board do you want?" << endl;
  cout << "Width (2 - 3): ";
  cin >> width;
  cout << "Height (2 - 3): ";
  cin >> height;
  cout << "How many enemies do you want? (1 - 2): ";
  cin >> enemyCount;

  cout << "Creating " << width << "x" << height << " board..." << endl;
  cout << "Adding your tank..." << endl;
  cout << "Adding " << enemyCount << " enemy tanks..." << endl;

  Game game(width, height, enemyCount);

  while (true) {
    cout << game.display();
    game.update();
  }
}
