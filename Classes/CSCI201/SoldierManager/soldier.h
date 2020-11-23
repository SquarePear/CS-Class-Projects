#ifndef SOLDIER_H
#define SOLDIER_H

#include <iostream>
#include <map>
#include <string>

using namespace std;

enum Classification { Enlisted, Warrent, Officer };
typedef std::pair<Classification, unsigned int> ClassRank;

class Soldier {
private:
  // Properties
  string name;
  unsigned int rank;
  Classification classification;

public:
  // Properties
  const static map<Classification, string> classificationName;
  const static map<ClassRank, string> rankName;
  const static map<ClassRank, unsigned int> rankPay;
  const static map<Classification, unsigned int> rankMax;

  // Getters
  string getName();
  unsigned int getRank();
  Classification getClassification();

  // Setters
  void setRank(unsigned int);

  // Methods
  string toString();
  unsigned int pay();

  // Overrides
  bool operator==(Soldier &);
  bool operator<(Soldier &);
  bool operator>(Soldier &);
  friend ostream &operator<<(ostream &, Soldier &);
  // Pre-increment
  Soldier &operator++();
  Soldier &operator--();
  // Post-increment
  Soldier &operator++(int);
  Soldier &operator--(int);

  // Constructors
  Soldier(string, Classification, unsigned int);
};

#endif
