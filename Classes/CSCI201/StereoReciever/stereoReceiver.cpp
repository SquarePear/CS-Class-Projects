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

void StereoReceiver::setBand(bandType b) {
  band = b;

  setFrequency(getFrequency());
}

void StereoReceiver::setFrequency(double f) {
  bandType b = getBand();

  if (b == AM) {
    f = round(f);

    if (f <= 535)
      frequency = 535;
    else if (f >= 1605)
      frequency = 1605;
    else
      frequency = f;
  } else {
    if (f <= 88.1)
      frequency = 88.1;
    else if (f >= 107.9)
      frequency = 107.9;
    else
      frequency = f;
  }
}

void StereoReceiver::setVolume(int v) {
  if (v <= 0)
    volume = 0;
  else if (v >= 10)
    volume = 10;
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

  serialNumber.resize(10);

  setBand(FM);
  setFrequency(88.1);
  setVolume(1);
  setPower(false);
}
