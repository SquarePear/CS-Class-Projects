#pragma once

#include "library.h"

using namespace std;

class Menu {
private:
  // Properties
  Library *library;

public:
  // Methods
  bool run();

  // Constructors
  Menu(Library *library) : library(library){};
};
