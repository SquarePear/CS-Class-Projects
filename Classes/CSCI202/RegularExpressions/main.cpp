/*
 *  Program name: Regular Expressions
 *  Author: Jeffrey Harmon
 *  Date created: May 10, 2021
 *  Date last updated: May 10, 2021
 *  Purpose: Detect information in a file using regex
 */

// #include <boost>
#include <fstream>
#include <iostream>
#include <regex>
#include <string>
#include <vector>

using namespace std;

vector<string> loadLines(string filename);

int main() {
  string pause;
  vector<string> lines = loadLines("input.txt");
  vector<string> patterns = loadLines("patterns.txt");

  // Main patterns
  for (string pattern : patterns) {
    cout << endl << pattern << endl;

    for (string line : lines)
      if (regex_match(line, regex(pattern)))
        cout << "  - " << line << endl;

    getline(cin, pause);
  }

  // Lowercase vowels
  regex vowelsPattern("(A|E|I|O|U)");

  cout << "Lowercase Vowels" << endl;
  for (string line : lines) {
    // Skip if not matched
    if (!regex_search(line, vowelsPattern))
      continue;

    // Replace all occurrances
    smatch match;
    while (regex_search(line, match, vowelsPattern))
      line.replace(match.position(1), 1,
                   string(1, static_cast<char>(tolower(match.str(1)[0]))));

    cout << "  - " << line << endl;
  }

  getline(cin, pause);

  // Lowercase vowels
  regex digitsPattern("([0-9])");
  string digitWords[10]{"zero", "one", "two",   "three", "four",
                        "five", "six", "seven", "eight", "nine"};

  cout << "Digits to Words" << endl;
  for (string line : lines) {
    // Skip if not matched
    if (!regex_search(line, digitsPattern))
      continue;

    // Replace all occurrances
    smatch match;
    while (regex_search(line, match, digitsPattern))
      line.replace(match.position(1), 1, digitWords[match.str(1)[0] - '0']);

    cout << "  - " << line << endl;
  }

  getline(cin, pause);

  return 0;
}

vector<string> loadLines(string filename) {
  vector<string> lines;
  ifstream file(filename);

  if (!file)
    throw runtime_error("File does not exist!");

  while (!file.eof()) {
    string line;

    getline(file, line);

    if (line != "")
      lines.push_back(line);
  }

  file.close();

  return lines;
}
