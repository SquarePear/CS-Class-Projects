#include "beverage.h"
#include "coffee.h"
#include "energydrink.h"
#include "iostream"
#include "soda.h"
#include "tea.h"

using namespace std;

int main() {
  // Create class instances
  Beverage hotChocolate("Hot Chocolate", "Chocolatey Goodness", 240, 200, 199);
  Coffee espresso("Espresso", "Small but Powerful", 40, 100, 199, ESPRESSO,
                  true, true, false, false);
  EnergyDrink monsterEnergy("Energy", "Bigger and More Powerful", 240, 210, 399,
                            "Monster", CAFFEINE, true);
  Soda sprite("Sprite", "Perfection", 360, 140, 99, "Coca-Cola", LEMON_LIME,
              false);
  Tea earlGrey("Earl Grey", "\"Earl Grey, Hot\"", 240, 100, 299, EARL_GREY,
               true, false, false, false);

  // Display information
  cout << hotChocolate.toString() << endl;
  cout << espresso.toString() << endl;
  cout << monsterEnergy.toString() << endl;
  cout << sprite.toString() << endl;
  cout << earlGrey.toString() << endl;

  return 0;
}
