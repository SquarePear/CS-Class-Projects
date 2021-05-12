#pragma once

#include "library.h"

using namespace std;

class Menu {
private:
  Library *library;

public:
  bool run();

  Menu(Library *library) : library(library){};
};
