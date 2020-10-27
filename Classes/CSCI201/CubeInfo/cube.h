#ifndef CUBE_H
#define CUBE_H
#include <string>

using std::string;

class Cube {
private:
  // Properties
  int length;
  int width;
  int height;
  string color;

public:
  // Getters
  int getLength();
  int getWidth();
  int getHeight();
  string getColor();

  // Setters
  void setLength(int);
  void setWidth(int);
  void setHeight(int);
  void setColor(string);

  // Methods
  int calculateVolume();

  // Constructors
  Cube();
  Cube(int, int, int, string);
};

#endif
