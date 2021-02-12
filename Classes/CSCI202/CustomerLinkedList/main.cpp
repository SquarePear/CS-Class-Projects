/*
 *  Program name: Customer Linked List
 *  Author: Jeffrey Harmon
 *  Date created: Feb. 11, 2021
 *  Date last updated: Feb. 12, 2021
 *  Purpose: Input and display information about customers stored in a linked
 *           list
 */

#include "customer.h"
#include "linkedlist.h"
#include <iostream>
#include <string>

using namespace std;

unsigned int intLength(unsigned int);
Customer *getCustomer(unsigned int ID);
Address getAddress();
void removeCustomer(LinkedList<Customer> &);

int main() {
  LinkedList<Customer> customers;
  char sentinel = 'y';

  do {
    try {
      cout << "What do you want to do?" << endl;
      cout << "  1: Add customer" << endl;
      cout << "  2: Remove customer" << endl;
      cout << "  3: Exit" << endl;
      cout << endl;

      cout << "Choice: ";
      unsigned int choice;

      if (!(cin >> choice) || choice < 1 || choice > 3)
        throw out_of_range("Invalid choice.");

      cin.clear();
      cin.ignore(1000, '\n');

      switch (choice) {
      case 1:
        customers.insert(*getCustomer(customers.size() + 1));
        break;
      case 2:
        removeCustomer(customers);
        break;
      case 3:
      default:
        sentinel = 'n';
        break;
      }

      if (sentinel == 'n')
        break;

      cout << endl;

      cout << "Would you like to perform another operation? (y/N): ";
      if (!(cin >> sentinel))
        throw runtime_error("Invalid input.");

    } catch (const std::exception &e) {
      cout << e.what() << endl;
      cin.clear();
      cin.ignore(1000, '\n');
    }
  } while (tolower(sentinel) == 'y');

  if (customers.size() == 0)
    return 0;

  cout << endl << endl;

  customers.print();

  return 0;
}

unsigned int intLength(unsigned int num) {
  int total = 0;

  while (num > 0) {
    num *= 0.1;
    total++;
  }

  return total;
}

Customer *getCustomer(unsigned int ID) {
  string name;
  Address address;
  std::string phoneNumber;

  cout << "Customer #" << ID << endl;

  cout << "  Name: ";
  if (!getline(cin, name))
    throw runtime_error("Invalid name.");

  cout << "  Address: " << endl;
  address = getAddress();

  cout << " Phone number: ";
  if (!getline(cin, phoneNumber) || phoneNumber.length() < 10)
    throw runtime_error("Invalid phone number.");

  return new Customer(name, ID, address, phoneNumber);
}

Address getAddress() {
  Address address;

  cout << "    Line 1: ";
  if (!getline(cin, address.line1))
    throw runtime_error("Invalid line.");

  cout << "    Line 2 (n): ";
  if (!getline(cin, address.line2))
    throw runtime_error("Invalid line.");

  if (address.line2 == "n")
    address.line2 = "";

  cout << "    City: ";
  if (!getline(cin, address.city))
    throw runtime_error("Invalid city.");

  cout << "    State: ";
  if (!getline(cin, address.state))
    throw runtime_error("Invalid state.");

  cout << "    Postal Code: ";
  if (!(cin >> address.postalCode) || intLength(address.postalCode) != 5)
    throw runtime_error("Invalid postal code.");

  cin.clear();
  cin.ignore(1000, '\n');

  cout << "    Country: ";
  if (!getline(cin, address.country))
    throw runtime_error("Invalid country.");

  return address;
}

void removeCustomer(LinkedList<Customer> &customers) {
  unsigned int ID;

  if (customers.size() == 0)
    throw out_of_range("List is empty.");

  cout << endl;

  customers.print();

  cout << endl;

  cout << "Which customer would you like to remove? #";
  if (!(cin >> ID) || ID < 1 || ID > customers.size())
    throw out_of_range("Invalid ID.");

  cin.clear();
  cin.ignore(1000, '\n');

  customers.remove(customers.get(ID - 1));
}
