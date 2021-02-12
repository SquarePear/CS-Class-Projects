#pragma once

#include <iostream>
#include <sstream>
#include <string>

struct Address {
  std::string line1;
  std::string line2;
  std::string city;
  std::string state;
  unsigned int postalCode;
  std::string country;
};

class Customer {
private:
  // Properties
  std::string name;
  unsigned int ID;
  Address address;
  std::string phoneNumber;

public:
  // Getters
  std::string getName();
  unsigned int getID();
  Address getAddress();
  std::string getPhoneNumber();

  // Setters
  void setName(std::string);
  void setAddress(Address);
  void setPhoneNumber(std::string);

  // Methods
  std::string toString() const;

  // Overrides
  bool operator>(Customer &);
  bool operator==(Customer &);
  friend std::ostream &operator<<(std::ostream &, const Customer &);

  // Constructors
  Customer(std::string, unsigned int, Address, std::string);
};
