#include "computer.h"

// Maps
map<int, string> ManufacturerName{
    std::pair<int, string>(Self, "Self"),
    std::pair<int, string>(Dell, "Dell"),
    std::pair<int, string>(Microsoft, "Microsoft"),
    std::pair<int, string>(HP, "HP"),
    std::pair<int, string>(Gateway, "Gateway"),
    std::pair<int, string>(Lenovo, "Lenovo")};

map<int, string> FormFactorName{std::pair<int, string>(Desktop, "Desktop"),
                                std::pair<int, string>(Laptop, "Laptop")};

map<int, string> ProcessorName{std::pair<int, string>(i3, "Intel i3"),
                               std::pair<int, string>(i5, "Intel i5"),
                               std::pair<int, string>(i7, "Intel i7"),
                               std::pair<int, string>(i9, "Intel i9"),
                               std::pair<int, string>(Ryzen3, "AMD Ryzen 3"),
                               std::pair<int, string>(Ryzen5, "AMD Ryzen 5"),
                               std::pair<int, string>(Ryzen7, "AMD Ryzen 7"),
                               std::pair<int, string>(Ryzen9, "AMD Ryzen 9")};

map<int, string> StorageTypeName{
    std::pair<int, string>(UFS, "UFS"),
    std::pair<int, string>(HDD, "HDD"),
    std::pair<int, string>(SSD, "SSD"),
};

// Getters
Manufacturer Computer::getManufacturer() { return manufacturer; }

FormFactor Computer::getFormFactor() { return formFactor; }

string Computer::getSerialNumber() { return serialNumber; }

Processor Computer::getProcessor() { return processor; }

int Computer::getRam() { return ram; }

StorageType Computer::getStorageType() { return storageType; }

int Computer::getStorageSize() { return storageSize; }

// Setters
void Computer::setRam(int ram) {
  if (ram <= 0)
    throw std::range_error("Invalid amount of ram.");

  this->ram = ram;
}

void Computer::setStorageType(StorageType storageType) {
  this->storageType = storageType;
}

void Computer::setStorageSize(int storageSize) {
  if (storageSize <= 0)
    throw std::range_error("Invalid size of storage.");

  this->storageSize = storageSize;
}

// Methods
string Computer::toString() {
  string out =
      ManufacturerName[manufacturer] + " " + FormFactorName[formFactor] + ":\n";

  out += "  SN: " + serialNumber + "\n";
  out += "  Processor: " + ProcessorName[processor] + "\n";
  out += "  Installed RAM: " + std::to_string(ram) + "GB\n";
  out += "  Storage:\n";
  out += "    Type: " + StorageTypeName[storageType] + "\n";
  out += "    Capacity: " + std::to_string(storageSize) + "GB\n";

  return out;
}

// Constructors
Computer::Computer(Manufacturer manufacturer, FormFactor formFactor,
                   string serialNumber, Processor processor, int ram,
                   StorageType storageType, int storageSize) {
  this->manufacturer = manufacturer;
  this->formFactor = formFactor;

  if (!(serialNumber.size() == 10))
    throw std::range_error("Serial number must be 10 characters.");

  this->serialNumber = serialNumber;

  this->processor = processor;

  this->storageType = storageType;

  setRam(ram);

  setStorageSize(storageSize);
}
