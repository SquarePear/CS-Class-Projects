/*
 *  Program name: Pizza Shop
 *  Author: Jeffrey Harmon
 *  Date created: Mar. 4, 2021
 *  Date last updated: Mar. 4, 2021
 *  Purpose: Order some pizzas from a virtual shop
 */

#include "pizza.h"
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

void setSize(Pizza &);
void setStyle(Pizza &);
void setSpecialty(Pizza &);
void addTopping(Pizza &);
void removeTopping(Pizza &);

int main() {
  vector<Pizza> pizzas;
  char sentinel = 'y';

  try {
    do {
      Pizza pizza;

      unsigned int selection;

      do {
        try {
          cout << pizza << endl;
          cout << endl;

          cout << "1: Set size" << endl;
          cout << "2: Set style" << endl;
          cout << "3: Set specialty" << endl;
          cout << "4: Add Topping" << endl;
          cout << "5: Remove Topping" << endl;
          cout << "6: Finish" << endl;
          cout << endl << "Choice: ";

          if (!(cin >> selection) || selection <= 0 || selection > 6)
            throw out_of_range("Invalid selection!");

          cout << endl;

          cin.clear();
          cin.ignore(1000, '\n');

          switch (selection) {
          case 1:
            setSize(pizza);
            break;
          case 2:
            setStyle(pizza);
            break;
          case 3:
            setSpecialty(pizza);
            break;
          case 4:
            addTopping(pizza);
            break;
          case 5:
            removeTopping(pizza);
            break;
          case 6:
          default:
            continue;
          }

          cout << endl;
        } catch (const std::exception &e) {
          cout << e.what() << endl;
          cin.clear();
          cin.ignore(1000, '\n');
        }

      } while (selection != 6);

      pizzas.push_back(pizza);

      cout << "Add another pizza? (y/n): ";
      if (!(cin >> sentinel))
        throw runtime_error("Invalid input");
    } while (sentinel == 'y');
  } catch (const std::exception &e) {
    cout << e.what() << endl;
    cin.clear();
    cin.ignore(1000, '\n');
  }

  cout << endl << endl;

  cout << "Your Order:" << endl;

  double totalPrice = 0;

  for (auto it = pizzas.begin(); it != pizzas.end(); it++) {
    cout << *it << endl;

    totalPrice += it->getPrice();
  }

  cout << endl << endl;

  cout << "  SUBTOTAL: $" << totalPrice << endl;
  cout << "       TAX: $" << floor(totalPrice * 7) * 0.01 << endl;
  cout << "  GRATUITY: $" << floor(totalPrice * 20) * 0.01 << endl;
  cout << " TOTAL DUE: $" << floor(totalPrice * 127) * 0.01 << endl;

  return 0;
}

void setSize(Pizza &pizza) {
  string selection;

  cout << "Pick a size:" << endl;

  for (auto it = PizzaSizeName.begin(); it != PizzaSizeName.end(); it++)
    cout << " - " << it->second << endl;

  cout << endl << "Choice: ";

  getline(cin, selection);

  PizzaSize size;
  bool valid = false;

  for (auto it = PizzaSizeName.begin(); it != PizzaSizeName.end(); it++) {
    if (it->second == selection) {
      size = it->first;
      valid = true;
      break;
    }
  }

  if (!valid)
    return;

  pizza.setSize(size);
}

void setStyle(Pizza &pizza) {
  string selection;

  cout << "Pick a style:" << endl;

  for (auto it = PizzaStyleName.begin(); it != PizzaStyleName.end(); it++)
    cout << " - " << it->second << endl;

  cout << endl << "Choice: ";

  getline(cin, selection);

  PizzaStyle style;
  bool valid = false;

  for (auto it = PizzaStyleName.begin(); it != PizzaStyleName.end(); it++) {
    if (it->second == selection) {
      style = it->first;
      valid = true;
      break;
    }
  }

  if (!valid)
    return;

  pizza.setStyle(style);
}

void setSpecialty(Pizza &pizza) {
  string selection;

  cout << "Pick a specialty:" << endl;

  for (auto it = ++PizzaSpecialtyName.begin(); it != PizzaSpecialtyName.end();
       it++)
    cout << " - " << it->second << endl;

  cout << endl << "Choice: ";

  getline(cin, selection);

  PizzaSpecialty specialty;
  bool valid = false;

  for (auto it = PizzaSpecialtyName.begin(); it != PizzaSpecialtyName.end();
       it++) {
    if (it->second == selection) {
      specialty = it->first;
      valid = true;
      break;
    }
  }

  if (!valid)
    return;

  pizza.setSpecialty(specialty);
}

void addTopping(Pizza &pizza) {
  string selection;

  cout << "Pick a topping:" << endl;

  set<PizzaTopping> currentToppings = pizza.getToppings();

  for (auto it = PizzaToppingName.begin(); it != PizzaToppingName.end(); it++)
    if (currentToppings.find(it->first) == currentToppings.end())
      cout << " - " << it->second << endl;

  cout << endl << "Choice: ";

  getline(cin, selection);

  PizzaTopping topping;
  bool valid = false;

  for (auto it = PizzaToppingName.begin(); it != PizzaToppingName.end(); it++) {
    if (currentToppings.find(it->first) != currentToppings.end())
      continue;

    if (it->second == selection) {
      topping = it->first;
      valid = true;
      break;
    }
  }

  if (!valid)
    return;

  pizza.addTopping(topping);
}

void removeTopping(Pizza &pizza) {
  string selection;

  cout << "Pick a topping:" << endl;

  set<PizzaTopping> currentToppings = pizza.getToppings();

  for (auto it = PizzaToppingName.begin(); it != PizzaToppingName.end(); it++)
    if (currentToppings.find(it->first) != currentToppings.end())
      cout << " - " << it->second << endl;

  cout << endl << "Choice: ";

  getline(cin, selection);

  PizzaTopping topping;
  bool valid = false;

  for (auto it = PizzaToppingName.begin(); it != PizzaToppingName.end(); it++) {
    if (currentToppings.find(it->first) == currentToppings.end())
      continue;

    if (it->second == selection) {
      topping = it->first;
      valid = true;
      break;
    }
  }

  if (!valid)
    return;

  pizza.removeTopping(topping);
}
