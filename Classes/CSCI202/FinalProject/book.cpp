#include "book.h"
#include <cmath>
#include <string>

// Getters
unsigned long long Book::getISBN() const { return this->ISBN; }
std::string Book::getName() const { return this->name; }
std::string Book::getAuthor() const { return this->author; }
unsigned short Book::getPages() const { return this->pages; }

// Methods
std::string Book::toString() const {
  return std::to_string(this->ISBN) + " - " + this->name + " - " +
         this->author + " - " + std::to_string(this->pages);
}

// Overrides
bool Book::operator<(const Book &o) const { return this->ISBN < o.getISBN(); };

// Statics
bool Book::isValidISBN(unsigned long long ISBN) {
  return std::trunc(std::log10(ISBN)) + 1 == 13;
}

// Constructors
Book::Book(unsigned long long ISBN, std::string name, std::string author,
           unsigned short pages)
    : name(name), author(author), pages(pages) {
  if (!isValidISBN(ISBN))
    throw std::invalid_argument("ISBN must be 13 digits!");

  this->ISBN = ISBN;
}
