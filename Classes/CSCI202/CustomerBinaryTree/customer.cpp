#include "customer.h"

// Getters
std::string Customer::getName() { return this->name; }

unsigned int Customer::getID() { return this->ID; }

Address Customer::getAddress() { return this->address; }

std::string Customer::getPhoneNumber() { return this->phoneNumber; }

// Setters
void Customer::setName(std::string name) { this->name = name; }

void Customer::setAddress(Address address) { this->address = address; }

void Customer::setPhoneNumber(std::string phoneNumber) {
  this->phoneNumber = phoneNumber;
}

// Methods
std::string Customer::toString() const {
  std::stringstream stringOut;

  stringOut << "Customer #" << this->ID << ":" << std::endl;

  stringOut << this->name << std::endl;

  stringOut << this->address.line1 << std::endl;
  if (this->address.line2.length() > 0)
    stringOut << this->address.line2 << std::endl;
  stringOut << this->address.city << ", " << this->address.state << " "
            << this->address.postalCode << std::endl;
  stringOut << this->address.country << std::endl;

  stringOut << this->phoneNumber << std::endl;

  return stringOut.str();
}

// Overrides
bool Customer::operator>(Customer &other) { return this->ID > other.ID; }

bool Customer::operator==(Customer &other) { return this->ID == other.ID; }

bool Customer::operator>(unsigned int ID) { return this->ID > ID; }

bool Customer::operator==(unsigned int ID) { return this->ID == ID; }

std::ostream &operator<<(std::ostream &o, const Customer &customer) {
  return o << customer.toString();
}

// Constructors
Customer::Customer(std::string name, unsigned int ID, Address address,
                   std::string phoneNumber) {
  this->name = name;
  this->ID = ID;
  this->address = address;
  this->phoneNumber = phoneNumber;
}
