/*
 *  Program name: Copy Stack
 *  Author: Jeffrey Harmon
 *  Date created: Feb. 24, 2021
 *  Date last updated: Feb. 24, 2021
 *  Purpose: Copy a stack externally
 */

#include "queue.h"
#include "stack.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
  Stack<char> charStack;
  Queue<char> charQueue;

  string input;
  string outputStack;
  string outputQueue;

  cout << "Enter a string to see if it is a palindrome!" << endl;
  getline(cin, input);

  try {
    for (int i = 0; i < input.length(); i++) {
      char character = toupper(input[i]);

      charStack.push(character);
      charQueue.push(character);
    }

    while (!charQueue.empty()) {
      outputStack += charStack.pop();
      outputQueue += charQueue.pop();
    }
  } catch (const std::exception &e) {
    cout << e.what() << endl;
    cin.clear();
    cin.ignore(1000, '\n');
  }

  cout << endl << endl;

  bool isPalindrome = outputQueue == outputStack;

  cout << input << " is " << ((isPalindrome) ? "" : "not ") << "a palindrome!"
       << endl;

  return 0;
}
