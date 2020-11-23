#ifndef NERFGUN_H
#define NERFGUN_H

#define MAX_DARTS 144

#include <iostream>
#include <string>

using std::ostream;
using std::string;

class nerfGun {
private:
  // Properties
  string model;
  unsigned int range;
  unsigned int capacity;
  unsigned int dartCount;

public:
  // Getters
  string getModel();
  unsigned int getRange();
  unsigned int getCapacity();
  unsigned int getDartCount();

  // Setters

  // Methods
  string toString() const;
  void fire();
  void reload(unsigned int);

  // Overrides
  bool operator==(nerfGun &);
  bool operator<(nerfGun &);
  bool operator>(nerfGun &);
  friend ostream &operator<<(ostream &, const nerfGun &);
  nerfGun &operator+=(unsigned int);
  // Pre-increment
  nerfGun &operator++();
  nerfGun &operator--();
  // Post-increment
  nerfGun &operator++(int);
  nerfGun &operator--(int);

  // Constructors
  nerfGun(string, unsigned int, unsigned int);
};

#endif
