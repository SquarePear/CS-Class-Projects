#include "soldier.h"

const map<Classification, string> Soldier::classificationName = {
    {Enlisted, "Enlisted"}, {Warrent, "Warrent"}, {Officer, "Officer"}};

const map<ClassRank, string> Soldier::rankName = {
    {make_pair(Enlisted, 1), "Private"},
    {make_pair(Enlisted, 2), "Private Second Class"},
    {make_pair(Enlisted, 3), "Private First Class"},
    {make_pair(Enlisted, 4), "Corporal"},
    {make_pair(Enlisted, 5), "Sergeant"},
    {make_pair(Enlisted, 6), "Staff Sergeant"},
    {make_pair(Enlisted, 7), "Sergeant First Class"},
    {make_pair(Enlisted, 8), "Master Sergeant"},
    {make_pair(Enlisted, 9), "Sergeant Major"},
    {make_pair(Warrent, 1), "Warrant Officer 1"},
    {make_pair(Warrent, 2), "Chief Warrant Officer 2"},
    {make_pair(Warrent, 3), "Chief Warrant Officer 3"},
    {make_pair(Warrent, 4), "Chief Warrant Officer 4"},
    {make_pair(Warrent, 5), "Chief Warrant Officer 5"},
    {make_pair(Officer, 1), "Second Lieutenant"},
    {make_pair(Officer, 2), "First Lieutenant"},
    {make_pair(Officer, 3), "Captain"},
    {make_pair(Officer, 4), "Major"},
    {make_pair(Officer, 5), "Lieutenant Colonel"},
    {make_pair(Officer, 6), "Colonel"},
    {make_pair(Officer, 7), "Brigadier General"},
    {make_pair(Officer, 8), "Major General"},
    {make_pair(Officer, 9), "Lieutenant General"},
    {make_pair(Officer, 10), "General"}};

const map<ClassRank, unsigned int> Soldier::rankPay = {
    {make_pair(Enlisted, 1), 20796}, {make_pair(Enlisted, 2), 23316},
    {make_pair(Enlisted, 3), 24512}, {make_pair(Enlisted, 4), 27151},
    {make_pair(Enlisted, 5), 29610}, {make_pair(Enlisted, 6), 32324},
    {make_pair(Enlisted, 7), 37372}, {make_pair(Enlisted, 8), 53762},
    {make_pair(Enlisted, 9), 65675}, {make_pair(Warrent, 1), 38556},
    {make_pair(Warrent, 2), 43927},  {make_pair(Warrent, 3), 49644},
    {make_pair(Warrent, 4), 54360},  {make_pair(Warrent, 5), 96656},
    {make_pair(Officer, 1), 39445},  {make_pair(Officer, 2), 45450},
    {make_pair(Officer, 3), 52600},  {make_pair(Officer, 4), 59825},
    {make_pair(Officer, 5), 69336},  {make_pair(Officer, 6), 83174},
    {make_pair(Officer, 7), 109681}, {make_pair(Officer, 8), 131994},
    {make_pair(Officer, 9), 186552}, {make_pair(Officer, 10), 197304}};

const map<Classification, unsigned int> Soldier::rankMax = {
    {Enlisted, 9},
    {Warrent, 5},
    {Officer, 10},
};

// Getters
string Soldier::getName() { return this->name; }

unsigned int Soldier::getRank() { return this->rank; }

Classification Soldier::getClassification() { return this->classification; }

// Setters

void Soldier::setRank(unsigned int rank) {
  if (rank < 1 || rank > this->rankMax.find(this->classification)->second)
    throw out_of_range("Invalid rank! " + this->toString());

  this->rank = rank;
}

// Methods
string Soldier::toString() {
  return this->classificationName.find(this->classification)->second + " - " +
         this->rankName.find(make_pair(this->classification, this->rank))
             ->second +
         " " + this->name + " - $" + to_string(this->pay()) + " per year";
}

unsigned int Soldier::pay() {
  return this->rankPay.find(make_pair(this->classification, this->rank))
      ->second;
}

// Overrides
bool Soldier::operator==(Soldier &other) {
  if (this->classification != other.getClassification())
    return false;
  if (this->rank != other.getRank())
    return false;

  return true;
}

bool Soldier::operator>(Soldier &other) {
  if (this->classification < other.getClassification())
    return false;
  if (this->rank <= other.getRank())
    return false;

  return true;
}

bool Soldier::operator<(Soldier &other) {
  if (this->classification > other.getClassification())
    return false;
  if (this->rank >= other.getRank())
    return false;

  return true;
}

ostream &operator<<(ostream &o, Soldier &soldier) {
  o << soldier.toString();

  return o;
}

// Pre-increment
Soldier &Soldier::operator++() {
  this->setRank(this->rank + 1);

  return *this;
}

Soldier &Soldier::operator--() {
  this->setRank(this->rank - 1);

  return *this;
}

// Post-increment
Soldier &Soldier::operator++(int) {
  Soldier tmp(this->name, this->classification, this->rank);

  this->operator++();

  return tmp;
}

Soldier &Soldier::operator--(int) {
  Soldier tmp(this->name, this->classification, this->rank);

  this->operator--();

  return tmp;
}

// Constructors
Soldier::Soldier(string name, Classification classification,
                 unsigned int rank) {
  this->name = name;
  this->classification = classification;

  this->setRank(rank);
}
