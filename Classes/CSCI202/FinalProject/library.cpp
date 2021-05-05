#include "library.h"
#include "book.h"
#include "customer.h"
#include <queue>
#include <string>

// Getters
std::string Library::getName() { return this->name; };

Book *Library::getBookByISBN(unsigned long long ISBN) {
  return this->booksByISBN[ISBN];
}

Book *Library::getBookByName(std::string name) {
  return this->booksByName[name];
}

Customer *Library::getCustomerByID(unsigned short ID) {
  return this->customersByID[ID];
}

Customer *Library::getCustomerByName(std::string name) {
  return this->customersByName[name];
}

std::queue<Book *> Library::getMostViewedBooks(unsigned short count) {
  if (count > this->books.size())
    throw std::out_of_range("Count cannot be greater than number of books!");

  std::sort(this->books.begin(), this->books.end(),
            [this](Book *const &a, Book *const &b) {
              return this->viewsOfBook(a->getISBN()) >
                     this->viewsOfBook(b->getISBN());
            });

  std::queue<Book *> books;
  auto book = this->books.begin();

  for (int i = 0; i < count; i++) {
    books.push(*book);

    book++;
  }

  return books;
}

std::queue<Book *> Library::getLeastViewedBooks(unsigned short count) {
  if (count > this->books.size())
    throw std::out_of_range("Count cannot be greater than number of books!");

  std::sort(this->books.begin(), this->books.end(),
            [this](Book *const &a, Book *const &b) {
              return this->viewsOfBook(a->getISBN()) >
                     this->viewsOfBook(b->getISBN());
            });

  std::queue<Book *> books;
  auto book = this->books.rbegin();

  for (int i = 0; i < count; i++) {
    books.push(*book);

    book++;
  }

  return books;
}

unsigned short Library::viewsOfBook(unsigned long long ISBN) {
  return this->viewsByBook.count(ISBN);
}

// Methods
void Library::addBook(unsigned long long ISBN, std::string name,
                      std::string author, unsigned short pages) {
  if (this->booksByISBN.contains(ISBN) || this->booksByName.contains(name))
    throw std::runtime_error("Book already exists!");

  Book *book = new Book(ISBN, name, author, pages);

  this->books.push_back(book);

  this->booksByISBN.emplace(ISBN, book);
  this->booksByName.emplace(name, book);
}

void Library::addCustomer(unsigned short ID, std::string name) {
  if (this->customersByID.contains(ID) || this->customersByName.contains(name))
    throw std::runtime_error("Customer already exists!");

  Customer *customer = new Customer(ID, name);

  this->customers.push_back(customer);

  this->customersByID.emplace(ID, customer);
  this->customersByName.emplace(name, customer);
}

void Library::addView(unsigned long long ISBN, unsigned short ID,
                      unsigned long timestamp) {
  View *view = new View(ISBN, ID, timestamp);

  this->views.push_back(view);

  this->viewsByBook.emplace(ISBN, view);
  this->viewsByCustomer.emplace(ID, view);
}

std::string Library::toString() const { return this->name; }
