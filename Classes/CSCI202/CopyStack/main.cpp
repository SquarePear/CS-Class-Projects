/*
 *  Program name: Copy Stack
 *  Author: Jeffrey Harmon
 *  Date created: Feb. 18, 2021
 *  Date last updated: Feb. 19, 2021
 *  Purpose: Copy a stack externally
 */

#include "stack.h"
#include <iostream>
#include <string>

using namespace std;

template <class T> Stack<T> copyStack(Stack<T> &);

int main() {
  Stack<string> names;
  char sentinel = 'y';

  cout << "Enter names to add to the list!" << endl;

  do {
    try {
      string name;

      // Display current index
      cout << "Name #" << names.size() + 1 << ": ";

      // Get user input (string)
      getline(cin, name);

      // Push name to stack
      names.push(name);

      cout << "Would you like to add another name? (y/N): ";
      if (!(cin >> sentinel))
        throw runtime_error("Invalid input!");

      cin.clear();
      cin.ignore(1000, '\n');

    } catch (const std::exception &e) {
      cout << e.what() << endl;
      cin.clear();
      cin.ignore(1000, '\n');
    }
  } while (tolower(sentinel) == 'y');

  cout << endl << endl;

  Stack<string> namesCopy = copyStack(names);

  while (!names.empty())
    cout << names.pop() << " | " << namesCopy.pop() << endl;

  return 0;
}

template <class T> Stack<T> copyStack(Stack<T> &other) {
  Stack<T> stackCopy(other.maxCapacity());
  Stack<T> temp;

  // Move all values reversed to a temporary stack
  while (!other.empty())
    temp.push(other.pop());

  // Move all values back to both stacks in the correct order
  while (!temp.empty()) {
    other.push(temp.value());
    stackCopy.push(temp.pop());
  }

  return stackCopy;
}
