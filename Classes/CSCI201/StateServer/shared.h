#pragma once

#include <string>

struct request {
  // Two character state abbreviation
  std::string stateabbrv;
};

struct response {
  // Full state name
  std::string statelong;

  // Return true if state not found
  bool failed = false;
};
