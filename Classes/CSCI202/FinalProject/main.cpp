/*
 *  Program name: Final Project - Library
 *  Author: Jeffrey Harmon
 *  Date created: Apr. 28, 2021
 *  Date last updated: May 12, 2021
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
void exportBooks(Library *library, string path = "data/books.csv");
void exportCustomers(Library *library, string path = "data/customers.csv");
void exportViews(Library *library, string path = "data/views.csv");

int main() {
  Library library("IvyBooks");

  // Import data from files
  importBooks(&library);
  importCustomers(&library);
  importViews(&library);

  cout << "Welcome to " << library.getName() << endl;
  cout << endl;

  // TODO: Menu for control

  exportBooks(&library);
  exportCustomers(&library);
  exportViews(&library);

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

  file.close();
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

  file.close();
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

  file.close();
}

void exportBooks(Library *library, string path) {
  ofstream file(path);
  file << "ISBN,name,author,pages" << endl;

  auto books = library->getBooks();

  for (Book const *book : books) {
    file << book->getISBN() << "," << book->getName() << ","
         << book->getAuthor() << "," << book->getPages();

    if (book != *--books.end())
      file << endl;
  }

  file.close();
}

void exportCustomers(Library *library, string path) {
  ofstream file(path);
  file << "ID,name" << endl;

  auto customers = library->getCustomers();

  for (Customer const *customer : customers) {
    file << customer->getID() << "," << customer->getName();

    if (customer != *--customers.end())
      file << endl;
  }

  file.close();
}

void exportViews(Library *library, string path) {
  ofstream file(path);
  file << "ISBN,ID,timestamp" << endl;

  auto views = library->getViews();

  for (View const *view : views) {
    file << get<0>(*view) << "," << get<1>(*view) << "," << get<2>(*view);

    if (view != *--views.end())
      file << endl;
  }

  file.close();
}
