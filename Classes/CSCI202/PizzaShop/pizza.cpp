#include "pizza.h"

// Getters
PizzaSize Pizza::getSize() const { return this->size; }

PizzaStyle Pizza::getStyle() const { return this->style; }

std::set<PizzaTopping> Pizza::getToppings() const { return this->toppings; }

PizzaSpecialty Pizza::getSpecialty() const { return this->specialty; }

double Pizza::getPrice() const {
  return (PizzaSizePrice.find(this->size)->second +
          this->toppings.size() * 50) /
         100.0;
}

// Setters
void Pizza::setSize(PizzaSize size) { this->size = size; }

void Pizza::setStyle(PizzaStyle style) { this->style = style; }

void Pizza::setSpecialty(PizzaSpecialty specialty) {
  this->specialty = specialty;
  this->toppings = PizzaSpecialtyToppings.find(specialty)->second;
}

// Methods
std::string Pizza::toString() const {
  std::stringstream stringOut;

  stringOut << PizzaSpecialtyName.find(this->specialty)->second
            << " pizza:" << std::endl;

  stringOut << "  Size: " << PizzaSizeName.find(this->size)->second
            << std::endl;
  stringOut << "  Style: " << PizzaStyleName.find(this->style)->second
            << std::endl;

  stringOut << "  Toppings: " << std::endl;

  if (this->toppings.size() == 0)
    stringOut << "   - None" << std::endl;
  else
    for (auto it = this->toppings.begin(); it != this->toppings.end(); it++)
      stringOut << "   - " << PizzaToppingName.find(*it)->second << std::endl;

  stringOut << std::endl;

  stringOut << "Price: $" << this->getPrice() << std::endl;

  return stringOut.str();
}

void Pizza::addTopping(PizzaTopping topping) {
  if (this->toppings.size() >= 7)
    throw std::overflow_error("Too many toppings!");

  this->toppings.insert(topping);
  this->specialty = CUSTOM;
}

void Pizza::removeTopping(PizzaTopping topping) {
  this->toppings.erase(topping);
  this->specialty = CUSTOM;
}

// Overrides
std::ostream &operator<<(std::ostream &o, const Pizza &pizza) {
  return o << pizza.toString();
}
