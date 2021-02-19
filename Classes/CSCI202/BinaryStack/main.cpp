/*
 *  Program name: Binary Stack
 *  Author: Jeffrey Harmon
 *  Date created: Feb. 17, 2021
 *  Date last updated: Feb. 19, 2021
 *  Purpose: Convert binary to decimal using a custom stack class
 */

#include "stack.h"
#include <iostream>
#include <math.h>
#include <string>

using namespace std;

unsigned long long binaryToDecimal(Stack<bool> &);

int main() {
  Stack<bool> bits;
  bool done = false;

  cout << "Enter your data one bit at a time!" << endl;

  do {
    try {
      bool bit;

      // Display current index
      cout << "index " << bits.size() << ": ";

      // Get user input (1 or 0)
      if (!(cin >> bit))
        throw runtime_error("Invalid input!");

      // Push bit to stack
      bits.push(bit);

    } catch (const std::exception &e) {
      // cout << e.what() << endl;
      cin.clear();
      cin.ignore(1000, '\n');
      done = true;
    }
  } while (!done);

  cout << endl << endl;

  cout << "Decimal value: " << binaryToDecimal(bits) << endl;

  return 0;
}

unsigned long long binaryToDecimal(Stack<bool> &bits) {
  unsigned int i = 0;
  unsigned long long value = 0;

  // For each bit add 2^i to value if true. Then increment i.
  while (!bits.empty())
    value += bits.pop() * pow(2, i++);

  return value;
}
