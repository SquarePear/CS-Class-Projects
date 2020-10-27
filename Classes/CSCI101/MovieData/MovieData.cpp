/*
 *  Program name: Movie Data Formatter
 *  Author: Jeffrey Harmon
 *  Date created: Apr. 29, 2020
 *  Date last updated: Jun. 07, 2020
 *  Purpose: Format entered movie data
 */

#include <stdlib.h>

#include <iostream>

#define NUM_MOVIES 2

struct MovieData {
  std::string title;
  std::string genre;
  std::string director;
  int yearReleased;
  int runningTime;
};

void getMovieData(MovieData &movie);
void displayMovieData(MovieData movie);

int main() {
  // Clear the terminal (Only works in macOS/Linux)
  system("clear");

  MovieData movies[NUM_MOVIES];

  // Get user input for all movies
  for (int i = 0; i < NUM_MOVIES; i++) {
    getMovieData(movies[i]);
  }

  std::cout << std::endl;

  // Display all movies in the terminal
  for (int i = 0; i < NUM_MOVIES; i++) {
    displayMovieData(movies[i]);
  }
}

// Get user input for movie data
void getMovieData(MovieData &movie) {
  // Fixes a bug with entering multiple movies
  std::cin.clear();
  std::cin.ignore(1000, '\n');

  std::cout << "Enter information about the movie." << std::endl;

  std::cout << "Title: ";
  while (!getline(std::cin, movie.title)) {
    std::cout << "Invalid input! Please enter again: ";
    std::cin.clear();
    std::cin.ignore(1000, '\n');
  }

  std::cout << "Genre: ";
  while (!getline(std::cin, movie.genre)) {
    std::cout << "Invalid input! Please enter again: ";
    std::cin.clear();
    std::cin.ignore(1000, '\n');
  }

  std::cout << "Director: ";
  while (!getline(std::cin, movie.director)) {
    std::cout << "Invalid input! Please enter again: ";
    std::cin.clear();
    std::cin.ignore(1000, '\n');
  }

  std::cout << "Release Year: ";
  while (!(std::cin >> movie.yearReleased)) {
    std::cout << "Invalid input! Please enter again: ";
    std::cin.clear();
    std::cin.ignore(1000, '\n');
  }

  std::cout << "Running Time (minutes): ";
  while (!(std::cin >> movie.runningTime) || movie.runningTime <= 0) {
    std::cout << "Invalid input! Please enter again: ";
    std::cin.clear();
    std::cin.ignore(1000, '\n');
  }

  std::cout << std::endl;
}

// Display movie data in an easy to read format
void displayMovieData(MovieData movie) {
  std::cout << movie.title << " (" << movie.yearReleased << ")" << std::endl;
  std::cout << "A(n) " << movie.genre << " film";
  std::cout << " directed by " << movie.director << std::endl;
  std::cout << "Running time: " << movie.runningTime << " minutes" << std::endl;
  std::cout << std::endl;
}