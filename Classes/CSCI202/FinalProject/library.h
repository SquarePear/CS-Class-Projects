#pragma once

#include "book.h"
#include "customer.h"
#include <map>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

typedef std::tuple<unsigned long long, unsigned short, unsigned long long> View;

class Library {
private:
  // Properties
  std::string name;

  std::vector<Book *> books;
  std::vector<Customer *> customers;
  std::vector<View *> views;

  std::map<unsigned long long, Book *> booksByISBN;
  std::unordered_map<std::string, Book *> booksByName;

  std::map<unsigned short, Customer *> customersByID;
  std::unordered_map<std::string, Customer *> customersByName;

  std::multimap<unsigned long long, View *> viewsByBook;
  std::multimap<unsigned short, View *> viewsByCustomer;

public:
  // Getters
  std::string getName();

  Book *getBookByISBN(unsigned long long ISBN);
  Book *getBookByName(std::string name);
  std::set<Book const *> getBooksByCustomerID(unsigned short ID);

  Customer *getCustomerByID(unsigned short ID);
  Customer *getCustomerByName(std::string name);
  std::set<Customer const *> getCustomersByBookISBN(unsigned long long ISBN);

  std::queue<Book *> getMostViewedBooks(unsigned short count);
  std::queue<Book *> getLeastViewedBooks(unsigned short count);

  unsigned short viewsOfBook(unsigned long long ISBN);

  std::vector<Book const *> getBooks();
  std::vector<Customer const *> getCustomers();
  std::vector<View const *> getViews();

  // Methods
  void addBook(unsigned long long ISBN, std::string name, std::string author,
               unsigned short pages);
  void addCustomer(unsigned short ID, std::string name);
  void addView(unsigned long long ISBN, unsigned short ID,
               unsigned long long timestamp);
  std::string toString() const;

  // Constructors
  Library(std::string name = "Library") : name(name){};
};
