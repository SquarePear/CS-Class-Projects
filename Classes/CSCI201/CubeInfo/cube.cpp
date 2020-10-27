#include "cube.h"

// Getters

int Cube::getLength() { return length; }

int Cube::getWidth() { return width; }

int Cube::getHeight() { return height; }

string Cube::getColor() { return color; }

// Setters

void Cube::setLength(int l) {
  if (l <= 0)
    length = 1;
  else
    length = l;
}

void Cube::setWidth(int w) {
  if (w <= 0)
    width = 1;
  else
    width = w;
}

void Cube::setHeight(int h) {
  if (h <= 0)
    height = 1;
  else
    height = h;
}

void Cube::setColor(string c) { color = c; }

// Methods

int Cube::calculateVolume() { return length * width * height; }

// Constructors

Cube::Cube() {}

Cube::Cube(int l, int w, int h, string c) {
  setLength(l);
  setWidth(w);
  setHeight(h);
  setColor(c);
}
