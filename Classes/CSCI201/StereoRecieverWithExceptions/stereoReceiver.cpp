#include "stereoReceiver.h"
#include <math.h>

// Getters

string StereoReceiver::getManufacturer() const { return manufacturer; }
string StereoReceiver::getModel() const { return model; }
string StereoReceiver::getSerialNumber() const { return serialNumber; }
int StereoReceiver::getWattage() const { return wattage; }
int StereoReceiver::getNumberOfChannels() const { return numberOfChannels; }
bandType StereoReceiver::getBand() const { return band; }
double StereoReceiver::getFrequency() const { return frequency; }
int StereoReceiver::getVolume() const { return volume; }
bool StereoReceiver::getPower() const { return power; }
string StereoReceiver::getColor() const { return color; }
double StereoReceiver::getWeight() const { return weight; }

// Setters

void StereoReceiver::setBand(bandType b) { band = b; }

void StereoReceiver::setFrequency(double f) {
  bandType b = getBand();

  if (b == AM) {
    f = round(f);

    if (f < 535 || f > 1605)
      throw string("Inappropriate value for Frequency");
    else
      frequency = f;
  } else {
    if (f < 88.1 || f > 107.9)
      throw string("Inappropriate value for Frequency");
    else
      frequency = f;
  }
}

void StereoReceiver::setVolume(int v) {
  if (v < 0)
    throw string("Invalid value - volume cannot be below 0");
  else if (v > 10)
    throw string("Invalid value - volume cannot exceed 10");
  else
    volume = v;
}

void StereoReceiver::setPower(bool p) { power = p; }

// Methods

void StereoReceiver::togglePower() { setPower(!getPower()); }

void StereoReceiver::increaseVolume() {
  if (getVolume() < 10)
    setVolume(getVolume() + 1);
}

void StereoReceiver::decreaseVolume() {
  if (getVolume() > 0)
    setVolume(getVolume() - 1);
}

// Constructors

StereoReceiver::StereoReceiver(string man, string mod, string s, int w, int num,
                               string c, double weigh) {
  manufacturer = man;
  model = mod;
  serialNumber = s;
  wattage = w;
  numberOfChannels = num;
  color = c;
  weight = weigh;

  if (!(serialNumber.length() == 10))
    throw string("Serial Number needs 10 digits");

  if (!(wattage >= 20 && wattage <= 200))
    throw string("The wattage must be between 20 and 200.");

  if (!(numberOfChannels >= 5 && numberOfChannels <= 13))
    throw string("The number of channels must be between 5 and 13.");

  setBand(FM);
  setFrequency(88.1);
  setVolume(1);
  setPower(false);
}
