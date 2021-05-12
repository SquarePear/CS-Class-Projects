#pragma once

#include <set>
#include <string>

class Book {
private:
  // Properties
  unsigned long long ISBN;
  std::string name;
  std::string author;
  unsigned short pages;

public:
  // Getters
  unsigned long long getISBN() const;
  std::string getName() const;
  std::string getAuthor() const;
  unsigned short getPages() const;

  // Methods
  std::string toString() const;

  // Overrides
  bool operator<(const Book &) const;

  // Statics
  static bool isValidISBN(unsigned long long);

  // Constructors
  Book(unsigned long long ISBN, std::string name, std::string author,
       unsigned short pages);
};
