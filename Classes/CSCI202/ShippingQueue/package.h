#pragma once

#include <iostream>
#include <sstream>
#include <string>

enum PostalClass {
  PriorityMailExpress,
  PriorityMail,
  FirstClassMail,
  Periodicals,
  USPSMarketingMail,
  PackageServices,
  USPSRetailGround,
};

struct Address {
  std::string line1;
  std::string line2;
  std::string city;
  std::string state;
  unsigned int postalCode;
  std::string country;
};

class Package {
private:
  // Properties
  PostalClass postalClass;
  Address address;

public:
  // Getters
  PostalClass getPostalClass();
  Address getAddress();

  // Setters
  void setPostalClass(PostalClass);
  void setAddress(Address);

  // Methods
  std::string toString() const;

  // Overrides
  bool operator>(Package &);
  bool operator==(Package &);
  friend std::ostream &operator<<(std::ostream &, const Package &);

  // Constructors
  Package(PostalClass, Address);
};
