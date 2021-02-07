#include "television.h"

// Getters
std::string Television::getManufacturer() { return this->manufacturer; }

std::string Television::getModel() { return this->model; }

double Television::getScreenSize() { return this->screenSize; }

Resolution Television::getResolution() { return this->resolution; }

unsigned int Television::getRefreshRate() { return this->refreshRate; }

unsigned int Television::getNumInputs() { return this->numInputs; }

double Television::getPrice() { return this->price; }

bool Television::getPower() { return this->power; }

unsigned int Television::getChannel() { return this->channel; }

unsigned int Television::getVolume() { return this->volume; }

// Setters
void Television::setChannel(unsigned int channel) {
  if (channel > 70)
    throw std::out_of_range("Channel can not be more than 70!");
  if (channel < 1)
    throw std::out_of_range("Channel can not be less than 1!");

  this->channel = channel;
}

void Television::setVolume(unsigned int volume) {
  if (volume > 10)
    throw std::out_of_range("Volume can not be more than 10!");
  if (volume < 0)
    throw std::out_of_range("Volume can not be less than 0!");

  this->volume = volume;
}

// Methods
std::string Television::toString() {
  std::stringstream stringOut;

  stringOut << this->manufacturer << " " << this->model << std::endl;

  stringOut << "Screen size (inches): " << std::to_string(this->screenSize)
            << "\"" << std::endl;

  stringOut << "Resolution (pixels): " << std::endl;
  stringOut << "  width: " << std::to_string(this->resolution.width) << "px"
            << std::endl;
  stringOut << "  height: " << std::to_string(this->resolution.height) << "px"
            << std::endl;

  stringOut << "Refresh rate: " << std::to_string(this->refreshRate) << "hz"
            << std::endl;

  stringOut << "Number of inputs: " << std::to_string(this->numInputs)
            << std::endl;

  stringOut << "Price (USD): $" << std::to_string(this->price) << std::endl;

  stringOut << "Power: " << (this->power ? "On" : "Off") << std::endl;

  if (!this->power)
    return stringOut.str();

  stringOut << "Channel: " << std::to_string(this->channel) << std::endl;
  stringOut << "Volume: " << std::to_string(this->volume) << std::endl;

  return stringOut.str();
}

std::string Television::getName() {
  return this->manufacturer + " " + this->model;
}

bool Television::togglePower() {
  this->power = !this->power;

  return this->power;
}

unsigned int Television::channelUp() {
  if (this->channel >= 70)
    throw std::out_of_range("Channel can not be more than 70!");

  return ++this->channel;
}

unsigned int Television::channelDown() {
  if (this->channel <= 1)
    throw std::out_of_range("Channel can not be less than 1!");

  return --this->channel;
}

unsigned int Television::volumeUp() {
  if (this->volume >= 10)
    throw std::out_of_range("Volume can not be more than 10!");

  return ++this->volume;
}

unsigned int Television::volumeDown() {
  if (this->volume <= 0)
    throw std::out_of_range("Volume can not be less than 0!");

  return --this->volume;
}

// Overrides
Television::~Television() {}

// Constructors
Television::Television(std::string manufacturer, std::string model,
                       double screenSize, Resolution resolution,
                       unsigned int refreshRate, unsigned int numInputs,
                       double price) {
  this->manufacturer = manufacturer;

  this->model = model;

  if (screenSize <= 0)
    throw std::out_of_range("Screen size must be more than 0\"!");
  this->screenSize = screenSize;

  if (resolution.width <= 0)
    throw std::out_of_range("Resolution width must be more than 0px!");
  if (resolution.height <= 0)
    throw std::out_of_range("Resolution height must be more than 0px!");
  this->resolution = resolution;

  if (refreshRate <= 0)
    throw std::out_of_range("Refresh rate must be more than 0hz!");
  this->refreshRate = refreshRate;

  if (numInputs <= 0)
    throw std::out_of_range("At least one input is required!");
  this->numInputs = numInputs;

  if (price <= 0)
    throw std::out_of_range("Price must be more than $0!");
  this->price = price;

  this->power = false;

  this->channel = 34;

  this->volume = 5;
}
