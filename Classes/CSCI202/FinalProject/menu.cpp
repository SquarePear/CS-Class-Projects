#include "menu.h"
#include <chrono>
#include <iostream>

using namespace std;

void printMostViewed(Library *library) {
  auto books = library->getMostViewedBooks(10);

  while (!books.empty()) {
    cout << books.front()->toString() << endl;

    books.pop();
  }
}

void printLeastViewed(Library *library) {
  auto books = library->getLeastViewedBooks(10);

  while (!books.empty()) {
    cout << books.front()->toString() << endl;

    books.pop();
  }
}

void printBookViewCount(Library *library) {
  unsigned long long ISBN;

  cout << "Enter the book's ISBN: ";
  if (!(cin >> ISBN) || !Book::isValidISBN(ISBN))
    throw runtime_error("ISBN must be 13 digits!");

  Book *book = library->getBookByISBN(ISBN);

  if (book == nullptr)
    throw runtime_error("Book not found!");

  for (auto customer : library->getCustomersByBookISBN(ISBN))
    cout << customer->toString() << endl;
}

void printCustomerViews(Library *library) {
  unsigned short ID;

  cout << "Enter the customers's ID: ";
  if (!(cin >> ID) || !Customer::isValidID(ID))
    throw runtime_error("ID must be 4 digits!");

  Customer *customer = library->getCustomerByID(ID);

  if (customer == nullptr)
    throw runtime_error("Customer not found!");

  for (auto book : library->getBooksByCustomerID(ID))
    cout << book->toString() << endl;
}

void printCustomers(Library *library) {
  for (auto customer : library->getCustomers())
    cout << customer->toString() << endl;
}

void printBooks(Library *library) {
  for (auto book : library->getBooks())
    cout << book->toString() << endl;
}

void addCustomer(Library *library) {
  unsigned short ID;
  string name;

  cout << "Enter the customers's Details: " << endl;

  cout << "ID: ";
  if (!(cin >> ID) || !Customer::isValidID(ID))
    throw runtime_error("ID must be 4 digits!");

  cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  cout << "Name: ";
  getline(cin, name);

  library->addCustomer(ID, name);
}

void addBook(Library *library) {
  unsigned long long ISBN;
  string name, author;
  unsigned short pages;

  cout << "Enter the books's Details: " << endl;

  cout << "ISBN: ";
  if (!(cin >> ISBN) || !Book::isValidISBN(ISBN))
    throw runtime_error("ISBN must be 13 digits!");

  cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  cout << "Name: ";
  getline(cin, name);

  cout << "Author: ";
  getline(cin, author);

  cout << "Pages: ";
  if (!(cin >> pages))
    throw runtime_error("Invalid page count!");

  library->addBook(ISBN, name, author, pages);
}

void addView(Library *library) {
  unsigned long long ISBN;
  unsigned short ID;
  unsigned long long timestamp;

  cout << "Enter the view's Details: " << endl;

  cout << "Book ISBN: ";
  if (!(cin >> ISBN) || !Book::isValidISBN(ISBN))
    throw runtime_error("ISBN must be 13 digits!");

  cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  cout << "Customer ID: ";
  if (!(cin >> ID) || !Customer::isValidID(ID))
    throw runtime_error("ID must be 4 digits!");

  timestamp = chrono::duration_cast<std::chrono::seconds>(
                  chrono::system_clock::now().time_since_epoch())
                  .count();

  library->addView(ISBN, ID, timestamp);
}

bool Menu::run() {
  try {
    cout << "What do you want to do?" << endl;
    cout << "   1: Most viewed books" << endl;
    cout << "   2: Least viewed books" << endl;
    cout << "   3: Customers by viewed book" << endl;
    cout << "   4: Books viewed by customer" << endl;
    cout << "   5: List of customers" << endl;
    cout << "   6: List of books" << endl;
    cout << "   7: Add customer" << endl;
    cout << "   8: Add book" << endl;
    cout << "   9: Add view" << endl;
    cout << "  10: Exit" << endl;
    cout << endl;

    cout << "Choice: ";
    unsigned int choice;

    if (!(cin >> choice) || choice < 1 || choice > 10)
      throw out_of_range("Invalid choice.");

    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cout << endl;

    switch (choice) {
    case 1:
      printMostViewed(this->library);
      break;
    case 2:
      printLeastViewed(this->library);
      break;
    case 3:
      printBookViewCount(this->library);
      break;
    case 4:
      printCustomerViews(this->library);
      break;
    case 5:
      printCustomers(this->library);
      break;
    case 6:
      printBooks(this->library);
      break;
    case 7:
      addCustomer(this->library);
      break;
    case 8:
      addBook(this->library);
      break;
    case 9:
      addView(this->library);
      break;
    default:
      return false;
      break;
    }
  } catch (const std::exception &e) {
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cout << e.what() << endl;
  }

  cout << endl;

  return true;
}