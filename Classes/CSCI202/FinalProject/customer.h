#pragma once

#include <set>
#include <string>

class Customer {
private:
  // Properties
  unsigned short ID;
  std::string name;

public:
  // Getters
  unsigned int getID() const;
  std::string getName() const;

  // Methods
  std::string toString() const;

  // Overrides
  bool operator<(const Customer &) const;

  // Constructors
  Customer(unsigned short ID, std::string name);
};
