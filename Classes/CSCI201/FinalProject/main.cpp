/*
 *  Program name: CSCI 201 Final Project - Tank Game
 *  Author: Jeffrey Harmon
 *  Date created: Dec. 9, 2020
 *  Date last updated: Dec. 16, 2020
 *  Purpose: Control a tank to navigate a maze
 */

#include "game.h"
#include "tank.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
  unsigned int width, height;

  cout << "What size board do you want?" << endl;
  cout << "Width (3 - 8): ";
  cin >> width;
  cout << "Height (3 - 8): ";
  cin >> height;

  cout << "Creating " << width << "x" << height << " board...";
}
