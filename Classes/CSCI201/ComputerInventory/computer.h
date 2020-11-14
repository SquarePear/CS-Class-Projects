#ifndef COMPUTER_H
#define COMPUTER_H

#include <map>
#include <string>

using std::map;
using std::string;

enum Manufacturer {
  Self,
  Dell,
  Microsoft,
  HP,
  Gateway,
  Lenovo,
  ManufacturerLength = 6
};
enum FormFactor { Desktop, Laptop, FormFactorLength = 2 };
enum Processor {
  i3,
  i5,
  i7,
  i9,
  Ryzen3,
  Ryzen5,
  Ryzen7,
  Ryzen9,
  ProcessorLength = 8
};
enum StorageType { UFS, HDD, SSD, StorageTypeLength = 3 };

class Computer {
private:
  // Properties
  Manufacturer manufacturer;
  FormFactor formFactor;
  string serialNumber;
  Processor processor;
  int ram;
  StorageType storageType;
  int storageSize;

public:
  // Getters
  Manufacturer getManufacturer();
  FormFactor getFormFactor();
  string getSerialNumber();
  Processor getProcessor();
  int getRam();
  StorageType getStorageType();
  int getStorageSize();

  // Setters
  void setRam(int);
  void setStorageType(StorageType);
  void setStorageSize(int);

  // Methods
  string toString();

  // Constructors
  Computer(Manufacturer, FormFactor, string, Processor, int, StorageType, int);
};

extern map<int, string> ManufacturerName;
extern map<int, string> FormFactorName;
extern map<int, string> ProcessorName;
extern map<int, string> StorageTypeName;

#endif
