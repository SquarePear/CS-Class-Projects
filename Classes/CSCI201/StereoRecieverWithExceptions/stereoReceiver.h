#ifndef STEREO_H
#define STEREO_H
#include <string>

using std::string;

enum bandType { AM, FM };

class StereoReceiver {
private:
  // Properties
  string manufacturer;
  string model;
  string serialNumber;
  int wattage;
  int numberOfChannels;
  bandType band;
  double frequency;
  int volume;
  bool power;
  string color;
  double weight;

public:
  // Getters
  string getManufacturer() const;
  string getModel() const;
  string getSerialNumber() const;
  int getWattage() const;
  int getNumberOfChannels() const;
  bandType getBand() const;
  double getFrequency() const;
  int getVolume() const;
  bool getPower() const;
  string getColor() const;
  double getWeight() const;

  // Setters
  void setBand(bandType);
  void setFrequency(double);
  void setVolume(int);
  void setPower(bool);

  // Methods
  void togglePower();
  void increaseVolume();
  void decreaseVolume();

  // Constructors
  StereoReceiver(string, string, string, int, int, string = "red", double = 10);
};

#endif
