/*
 *  Program name: Final Project - Library
 *  Author: Jeffrey Harmon
 *  Date created: Apr. 28, 2021
 *  Date last updated: May 5, 2021
 *  Purpose: Perform and manage common functions of a library
 */

#include "library.h"
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;

void importBooks(Library *library, string path = "data/books.csv");
void importCustomers(Library *library, string path = "data/customers.csv");
void importViews(Library *library, string path = "data/views.csv");

int main() {
  Library library("IvyBooks");

  // Import data from files
  importBooks(&library);
  importCustomers(&library);
  importViews(&library);

  cout << "Welcome to " << library.getName() << endl;
  cout << endl;

  // TODO: Menu for control

  // TODO: Save to file

  return 0;
}

void importBooks(Library *library, string path) {
  ifstream file(path);

  // Ignore header
  string tmp;
  getline(file, tmp);

  while (!file.eof()) {
    char comma;
    unsigned long long ISBN;
    string name, author;
    unsigned short pages;

    file >> ISBN >> comma;

    getline(file, name, ',');
    getline(file, author, ',');

    file >> pages;

    library->addBook(ISBN, name, author, pages);
  }
}

void importCustomers(Library *library, string path) {
  ifstream file(path);

  // Ignore header
  string tmp;
  getline(file, tmp);

  while (!file.eof()) {
    char comma;
    unsigned short ID;
    string name;

    file >> ID >> comma;

    getline(file, name);

    library->addCustomer(ID, name);
  }
}

void importViews(Library *library, string path) {
  ifstream file(path);

  // Ignore header
  string tmp;
  getline(file, tmp);

  while (!file.eof()) {
    char comma;
    unsigned long long ISBN;
    unsigned short ID;
    unsigned long timestamp;

    file >> ISBN >> comma >> ID >> comma >> timestamp;

    library->addView(ISBN, ID, timestamp);
  }
}
