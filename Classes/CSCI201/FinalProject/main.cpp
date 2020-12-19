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

  // Initialize random
  srand(time(NULL));

  try {
    cout << "What size board do you want?" << endl;
    cout << "Width (4 - 10): ";
    cin >> width;

    if (width > 10 || width < 4)
      throw std::out_of_range("Width must be between 4 and 10!");

    cout << "Height (4 - 10): ";
    cin >> height;

    if (height > 10 || height < 4)
      throw std::out_of_range("Height must be between 4 and 10!");

    cout << "How many enemies do you want? (1 - 5): ";
    cin >> enemyCount;

    if (enemyCount < 1)
      throw std::out_of_range("You need at least one enemy!");

    if (enemyCount > 5)
      throw std::out_of_range("You can't have more than 5 enemies!");

    cout << "Creating " << width << "x" << height << " board..." << endl;
    cout << "Adding your tank..." << endl;
    cout << "Adding " << enemyCount << " enemy tanks..." << endl;

    // Create game instance
    Game game(width, height, enemyCount);

    // Game loop
    while (true) {
      try {
        cout << game.display();
        game.update();
      } catch (const std::exception &e) {
        cout << e.what() << endl;
      }
    }
  } catch (const std::exception &e) {
    cout << e.what() << endl;
  }
}
