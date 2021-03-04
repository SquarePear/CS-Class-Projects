#pragma once

#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>

enum PizzaSize { PERSONAL, MEDIUM, LARGE, FAMILY };

enum PizzaStyle { DEEP, THIN, BROOKLYN, TRADITIONAL };

enum PizzaTopping {
  PEPPERONI,
  SAUSAGE,
  BEEF,
  CHICKEN,
  HAM,
  PINEAPPLE,
  OLIVE,
  PARMESAN,
  REDPEPPER,
  GREENPEPPER,
  JALAPENO
};

enum PizzaSpecialty { CUSTOM, MEAT, VEGGIE, SPICY, HAWAII, CHEESY };

class Pizza {
private:
  // Properties
  PizzaSize size = MEDIUM;
  PizzaStyle style = TRADITIONAL;
  std::set<PizzaTopping> toppings = {};
  PizzaSpecialty specialty = CUSTOM;

public:
  // Getters
  PizzaSize getSize() const;
  PizzaStyle getStyle() const;
  std::set<PizzaTopping> getToppings() const;
  PizzaSpecialty getSpecialty() const;
  double getPrice() const;

  // Setters
  void setSize(PizzaSize);
  void setStyle(PizzaStyle);
  void setSpecialty(PizzaSpecialty);

  // Methods
  std::string toString() const;
  void addTopping(PizzaTopping);
  void removeTopping(PizzaTopping);

  // Overrides
  friend std::ostream &operator<<(std::ostream &, const Pizza &);
};

// Maps

const std::map<PizzaSize, unsigned int> PizzaSizePrice = {
    {PERSONAL, 599}, {MEDIUM, 699}, {LARGE, 1299}, {FAMILY, 1499}};

const std::map<PizzaSpecialty, std::set<PizzaTopping>> PizzaSpecialtyToppings =
    {{MEAT, {PEPPERONI, SAUSAGE, BEEF, CHICKEN, HAM}},
     {VEGGIE, {OLIVE, REDPEPPER, GREENPEPPER, JALAPENO}},
     {SPICY, {PEPPERONI, SAUSAGE, JALAPENO}},
     {HAWAII, {HAM, PINEAPPLE}},
     {CHEESY, {PARMESAN}}};

const std::map<PizzaSize, std::string> PizzaSizeName = {{PERSONAL, "Personal"},
                                                        {MEDIUM, "Medium"},
                                                        {LARGE, "Large"},
                                                        {FAMILY, "Family"}};
const std::map<PizzaStyle, std::string> PizzaStyleName = {
    {DEEP, "Deep Dish"},
    {THIN, "This Crust"},
    {BROOKLYN, "Brooklyn"},
    {TRADITIONAL, "Traditional"}};
const std::map<PizzaTopping, std::string> PizzaToppingName = {
    {PEPPERONI, "Pepperoni"},
    {SAUSAGE, "Sausage"},
    {BEEF, "Beef"},
    {CHICKEN, "Chicken"},
    {HAM, "Ham"},
    {PINEAPPLE, "Pineapple"},
    {OLIVE, "Olive"},
    {PARMESAN, "Parmesan"},
    {REDPEPPER, "Red Pepper"},
    {GREENPEPPER, "Green Pepper"},
    {JALAPENO, "Jalapeño"}};
const std::map<PizzaSpecialty, std::string> PizzaSpecialtyName = {
    {CUSTOM, "Custom"}, {MEAT, "Meat Lovers"}, {VEGGIE, "Veggie"},
    {SPICY, "Spicy"},   {HAWAII, "Hawaiian"},  {CHEESY, "Cheesy"}};
