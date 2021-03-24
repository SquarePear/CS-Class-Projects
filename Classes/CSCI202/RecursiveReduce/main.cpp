/*
 *  Program name: Recursive Reduce
 *  Author: Jeffrey Harmon
 *  Date created: Mar. 24, 2021
 *  Date last updated: Mar. 24, 2021
 *  Purpose: Recursively reduce an integer and a string
 */

#include <iostream>
#include <string>

using namespace std;

string reduce(string);
unsigned long int reduce(unsigned long int);

int main() {
  string str;
  unsigned long int num;

  cout << "Enter a string to reduce: ";
  getline(cin, str);
  cout << reduce(str) << endl;

  cout << endl;

  cout << "Enter an integer to reduce: ";
  cin >> num;
  cout << reduce(num) << endl;

  return 0;
}

string reduce(string str) {
  if (str.length() == 1)
    return str;

  char a = str[0];
  char b = str[1];

  string result = reduce(str.substr(1, str.length() - 1));

  return ((a == b) ? "" : str.substr(0, 1)) + result;
}

unsigned long int reduce(unsigned long int num) {
  if (num < 10)
    return num;

  int a = num % 10;
  int b = (num / 10) % 10;

  unsigned long int result = reduce(num / 10) * 10;

  return (a == b) ? result / 10 : result + a;
}
