#pragma once

#include <sstream>
#include <string>

struct Resolution {
  unsigned int width;
  unsigned int height;
};

class Television {
private:
  // Properties
  std::string manufacturer;
  std::string model;
  double screenSize;
  Resolution resolution;
  unsigned int refreshRate;
  unsigned int numInputs;
  double price;
  bool power;
  unsigned int channel;
  unsigned int volume;

public:
  // Getters
  std::string getManufacturer();
  std::string getModel();
  double getScreenSize();
  Resolution getResolution();
  unsigned int getRefreshRate();
  unsigned int getNumInputs();
  double getPrice();
  bool getPower();
  unsigned int getChannel();
  unsigned int getVolume();

  // Setters
  void setChannel(unsigned int);
  void setVolume(unsigned int);

  // Methods
  std::string toString();
  std::string getName();
  bool togglePower();
  unsigned int channelUp();
  unsigned int channelDown();
  unsigned int volumeUp();
  unsigned int volumeDown();

  // Overrides
  ~Television();

  // Constructors
  Television(std::string, std::string, double, Resolution, unsigned int,
             unsigned int, double);
};
