#include "beverage.h"

// Getters
std::string Beverage::getName() { return this->name; }

std::string Beverage::getDescription() { return this->description; }

unsigned int Beverage::getServingSize() { return this->servingSize; }

unsigned int Beverage::getCalories() { return this->calories; }

unsigned int Beverage::getPrice() { return this->price; }

// Setters
void Beverage::setPrice(unsigned int price) {
  if (price <= 0)
    throw std::out_of_range("Price too low!");

  this->price = price;
}

// Methods
std::string Beverage::toString() {
  std::stringstream ss;

  ss << this->name << " ~ " << this->description << " | $"
     << this->price / 100.0 << " | " << this->servingSize << "ml | "
     << this->calories << " cal";

  return ss.str();
}

// Constructors
Beverage::Beverage(std::string name, std::string description,
                   unsigned int servingSize, unsigned int calories,
                   unsigned int price) {
  this->name = name;
  this->description = description;
  this->servingSize = servingSize;
  this->calories = calories;

  this->setPrice(price);
}
