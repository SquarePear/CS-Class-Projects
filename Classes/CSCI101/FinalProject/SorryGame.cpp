/*
 *  Program name: CSCI 101 Final Project - Sorry Game
 *  Author: Jeffrey Harmon
 *  Date created: May. 6, 2020
 *  Date last updated: May. 14, 2020
 *  Purpose: Play a game of Sorry wth user input
 */

#include <stdlib.h>
#include <time.h>

#include <iostream>

// Defining game options
#define MIN_PLAYERS 2
#define MAX_PLAYERS 4
#define FINAL_SPACE 60

struct RollInfo {
  int total;
  int diceValues[2];
  bool doubles;
};

struct Player {
  std::string name;
  int position;
  RollInfo rolls[2];
};

// Declaring function prototypes
void displayBoard(Player players[MAX_PLAYERS], int playerCount);
int getFirstPlayer(Player players[MAX_PLAYERS], int playerCount);
int getLastPlayer(Player players[MAX_PLAYERS], int playerCount);
void movePlayer(Player players[MAX_PLAYERS], int playerCount, int currentPlayer,
                int spaces);
RollInfo rollDie(int rollCount[11]);
void runDiceAction(RollInfo roll, Player players[MAX_PLAYERS], int playerCount,
                   int currentPlayer);
void swapPlayers(Player players[MAX_PLAYERS], int playerA, int playerB);

int main() {
  // Variable to check for the restart loop
  bool restart = false;

  do {
    // Initialize random
    srand(time(NULL));

    int playerCount = 0;
    Player players[MAX_PLAYERS];

    // Get player information
    std::cout << "How many players are there? (" << MIN_PLAYERS << "-"
              << MAX_PLAYERS << "): ";
    while (!(std::cin >> playerCount) || playerCount < MIN_PLAYERS ||
           playerCount > MAX_PLAYERS) {
      std::cout << "Invalid player count! Please enter again: " << std::endl;
      std::cin.clear();
      std::cin.ignore(1000, '\n');
    }

    for (int i = 0; i < playerCount; i++) {
      std::cout << "Player " << i + 1 << ", please enter your name: ";
      while (!(std::cin >> players[i].name) || players[i].name.length() > 12) {
        std::cout << "Invalid name! Please enter again: ";
        std::cin.clear();
        std::cin.ignore(1000, '\n');
      }

      players[i].position = 0;
    }

    std::cin.clear();
    std::cin.ignore(1000, '\n');

    int rollCount[11] = {0};

    int gameState = 0;

    // Game loop
    while (gameState == 0) {
      // Player loop
      for (int i = 0; i < playerCount; i++) {
        displayBoard(players, playerCount);

        std::cout << players[i].name << ", press enter to roll" << std::endl;
        std::cin.ignore();

        RollInfo roll = rollDie(rollCount);

        players[i].rolls[1] = players[i].rolls[0];
        players[i].rolls[0] = roll;

        std::cout << "You rolled a " << roll.total << " (" << roll.diceValues[0]
                  << "+" << roll.diceValues[1] << ")" << std::endl;

        runDiceAction(roll, players, playerCount, i);
        // win logic
        if (players[i].position == FINAL_SPACE) {
          gameState = i + 1;
          i = playerCount;
          continue;
        } else {
          // Doubles logic
          if (players[i].rolls[1].doubles && players[i].rolls[0].doubles) {
            std::cout << players[i].name
                      << " rolled doubles twice in a row and had to start over!"
                      << std::endl;

            players[i].rolls[0].doubles = false;

            players[i].position = 0;
          } else if (players[i].rolls[0].doubles) {
            std::cout << players[i].name
                      << " rolled doubles and they get an extra turn!"
                      << std::endl;
            i--;
          }
        }

        std::cin.ignore();
      }
    }

    // End screen
    displayBoard(players, playerCount);

    std::cout << "Congratulations " << players[gameState - 1].name
              << "! You win!" << std::endl
              << std::endl;

    for (int i = 2; i <= 12; i++)
      std::cout << i << ": " << rollCount[i - 2] << std::endl;

    // Restart logic
    char restartChar;
    std::cout << "Do you want to play again? (y/n): ";

    while (!(std::cin >> restartChar) ||
           (restartChar != 'n' && restartChar != 'y')) {
      std::cout << "Invalid option! Please enter again: ";
      std::cin.clear();
      std::cin.ignore(1000, '\n');
    }

    if (restartChar == 'y')
      restart = true;

  } while (restart);
  return 0;
}

// Roll dice and return info
RollInfo rollDie(int rollCount[11]) {
  RollInfo roll;

  roll.diceValues[0] = rand() % 6 + 1;
  roll.diceValues[1] = rand() % 6 + 1;

  roll.doubles = (roll.diceValues[0] == roll.diceValues[1]);

  roll.total = roll.diceValues[0] + roll.diceValues[1];

  rollCount[roll.total - 2]++;

  return roll;
}

// Move the player by a set spaces and perform any necessary checks
void movePlayer(Player players[MAX_PLAYERS], int playerCount, int currentPlayer,
                int spaces) {
  // Movement specifics logic
  if (players[currentPlayer].position + spaces <= 0) {
    std::cout << players[currentPlayer].name
              << " tried to move backwards before the starting space and fell "
                 "off the board!"
              << std::endl;
    players[currentPlayer].position = 0;
    return;
  } else if (players[currentPlayer].position + spaces > FINAL_SPACE) {
    std::cout << players[currentPlayer].name
              << " tried to move past the final space, but they failed!"
              << std::endl;
    return;
  }

  players[currentPlayer].position += spaces;

  std::cout << players[currentPlayer].name << " moved " << spaces << " spaces!"
            << std::endl;

  // Player lands on other player logic
  for (int i = 0; i < playerCount; i++) {
    if (i == currentPlayer)
      continue;

    if (players[i].position == players[currentPlayer].position) {
      players[i].position = 0;

      std::cout << players[i].name << " was kicked off the board by "
                << players[currentPlayer].name << "!" << std::endl;
    }
  }
}

void displayBoard(Player players[MAX_PLAYERS], int playerCount) {
  // Clear screen on all OSes. system("clear") only works in unix
  for (int i = 0; i < 60; i++)
    std::cout << std::endl;

  // Display spaces and put players on correct spots
  for (int i = 0; i < 60; i++) {
    int player = -1;
    for (int j = 0; j < playerCount; j++) {
      if (players[j].position - 1 == i)
        player = j;
    }

    if (player != -1)
      std::cout << player + 1 << " ";
    else
      std::cout << "☐ ";
  }

  std::cout << std::endl << std::endl;

  // Display player list and easier to read position values
  for (int i = 0; i < playerCount; i++) {
    std::cout << "P" << i + 1 << ") " << players[i].name << ": "
              << players[i].position << std::endl;
  }

  std::cout << std::endl;
}

void runDiceAction(RollInfo roll, Player players[MAX_PLAYERS], int playerCount,
                   int currentPlayer) {
  // Custom movement logic if player is not on board
  if (players[currentPlayer].position == 0) {
    if (roll.doubles) {
      movePlayer(players, playerCount, currentPlayer, roll.total);
      std::cout << players[currentPlayer].name
                << " rolled doubles and landed on the board!" << std::endl;
    }

    return;
  }

  // Play logic for players on the board
  switch (roll.total) {
  case 4:
    movePlayer(players, playerCount, currentPlayer, -1);
    break;
  case 5:
    movePlayer(players, playerCount, currentPlayer, -3);
    break;
  case 7:
    swapPlayers(players, currentPlayer, getLastPlayer(players, playerCount));
    break;
  case 8:
    movePlayer(players, playerCount, currentPlayer, 0);
    break;
  case 11:
    swapPlayers(players, currentPlayer, getFirstPlayer(players, playerCount));
    break;
  case 12:
    std::cout << players[currentPlayer].name << " was sent off the board!"
              << std::endl;
    players[currentPlayer].position = 0;
    break;
  default:
    movePlayer(players, playerCount, currentPlayer, roll.total);
    break;
  }
}

// Get index of player in first on the board
int getFirstPlayer(Player players[MAX_PLAYERS], int playerCount) {
  int playerIndex = -1;

  for (int i = 0; i < playerCount; i++) {
    if (players[i].position >
        ((playerIndex == -1) ? 0 : players[playerIndex].position))
      playerIndex = i;
  }

  return playerIndex;
}

// Get index of player in last on the board
int getLastPlayer(Player players[MAX_PLAYERS], int playerCount) {
  int playerIndex = -1;

  for (int i = 0; i < playerCount; i++) {
    if ((playerIndex == -1)
            ? (players[i].position > 0)
            : (players[i].position > 0 &&
               players[i].position < players[playerIndex].position))
      playerIndex = i;
  }

  return playerIndex;
}

// Swap player A and player B
void swapPlayers(Player players[MAX_PLAYERS], int playerA, int playerB) {
  // Stop if nobody is on the board to swap with
  if (playerB == -1) {
    std::cout << players[playerA].name
              << " tried to swap places with someone, but there was nobody on "
                 "the board!"
              << std::endl;
    return;
  }

  // Stop if player A and B are the same
  if (playerA == playerB) {
    std::cout << players[playerA].name
              << " tried to swap places with themselves, but they failed!"
              << std::endl;
    return;
  }

  int playerAPos = players[playerA].position;

  players[playerA].position = players[playerB].position;
  players[playerB].position = playerAPos;

  std::cout << players[playerA].name << " swapped positions with "
            << players[playerB].name << "!" << std::endl;
}