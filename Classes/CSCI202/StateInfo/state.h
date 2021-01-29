#pragma once

#include <string>

struct Person {
  std::string firstName;
  char middleInitial;
  std::string lastName;
};

struct State {
  std::string name;
  std::string abbreviation;
  Person governor;
  Person lieutenantGovernor;
  std::string capitol;
  std::string flower;
  int representatives;
  int order;
  int year;
};
