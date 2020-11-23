#include "nerfgun.h"

string nerfGun::getModel() { return this->model; }

unsigned int nerfGun::getRange() { return this->range; }

unsigned int nerfGun::getCapacity() { return this->capacity; }

unsigned int nerfGun::getDartCount() { return this->dartCount; }

// Setters

// Methods
string nerfGun::toString() const {
  return this->model + " - " + std::to_string(this->range) + "m range - " +
         std::to_string(this->dartCount) + "/" + std::to_string(this->capacity);
}

void nerfGun::fire() {
  if (this->dartCount == 0)
    throw std::underflow_error("No more darts!");

  this->dartCount--;
}

void nerfGun::reload(unsigned int quantity) {
  if (this->dartCount + quantity > this->capacity)
    throw std::overflow_error("Too many darts!");
}

// Overrides
bool nerfGun::operator==(nerfGun &other) {
  return this->dartCount == other.getDartCount();
}

bool nerfGun::operator<(nerfGun &other) {
  return this->dartCount < other.getDartCount();
}

bool nerfGun::operator>(nerfGun &other) {
  return this->dartCount > other.getDartCount();
}

ostream &operator<<(ostream &o, const nerfGun &nerfgun) {
  return o << nerfgun.toString();
}

nerfGun &nerfGun::operator+=(unsigned int quantity) {
  this->reload(quantity);

  return *this;
}

// Pre-increment
nerfGun &nerfGun::operator++() {
  this->reload(1);

  return *this;
}

nerfGun &nerfGun::operator--() {
  this->fire();

  return *this;
}

// Post-increment
nerfGun &nerfGun::operator++(int) {
  nerfGun tmp(this->model, this->range, this->capacity);

  this->operator++();

  return tmp;
}

nerfGun &nerfGun::operator--(int) {
  nerfGun tmp(this->model, this->range, this->capacity);

  this->operator--();

  return tmp;
}

// Constructors
nerfGun::nerfGun(string model, unsigned int range, unsigned int capacity) {
  this->model = model;
  this->range = range;

  if (capacity > MAX_DARTS)
    throw std::out_of_range("Cannot have capacity of greater than 144!");

  this->capacity = capacity;
  this->dartCount = capacity;
}
