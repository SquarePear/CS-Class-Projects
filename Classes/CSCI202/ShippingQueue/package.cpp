#include "package.h"

// Getters
PostalClass Package::getPostalClass() { return this->postalClass; }

Address Package::getAddress() { return this->address; }

// Setters
void Package::setPostalClass(PostalClass postalClass) {
  this->postalClass = postalClass;
}

void Package::setAddress(Address address) { this->address = address; }

// Methods
std::string Package::toString() const {
  std::stringstream stringOut;

  stringOut << "Package Info:" << std::endl;

  stringOut << "Class: " << this->postalClass << std::endl;

  stringOut << this->address.line1 << std::endl;
  if (this->address.line2.length() > 0)
    stringOut << this->address.line2 << std::endl;
  stringOut << this->address.city << ", " << this->address.state << " "
            << this->address.postalCode << std::endl;
  stringOut << this->address.country << std::endl;

  return stringOut.str();
}

// Overrides
bool Package::operator>(Package &other) {
  return this->postalClass < other.postalClass;
}

bool Package::operator==(Package &other) {
  return this->postalClass == other.postalClass;
}

std::ostream &operator<<(std::ostream &o, const Package &customer) {
  return o << customer.toString();
}

// Constructors
Package::Package(PostalClass postalClass, Address address) {
  this->postalClass = postalClass;
  this->address = address;
}
