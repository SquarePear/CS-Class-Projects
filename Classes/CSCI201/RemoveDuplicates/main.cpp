/*
 *  Program name: Remove Duplicates
 *  Author: Jeffrey Harmon
 *  Date created: Nov. 15, 2020
 *  Date last updated: Nov. 15, 2020
 *  Purpose: Read a file and output all non duplicate lines
 */

#include <fstream>
#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
  set<string> words;
  set<string>::iterator wordsIt;

  string fileName;
  cin >> fileName;

  ifstream fileIn;
  fileIn.open(fileName);

  while (!fileIn.eof()) {
    string word;
    fileIn >> word;
    words.insert(word);
  }

  for (wordsIt = words.begin(); wordsIt != words.end(); wordsIt++)
    cout << *wordsIt << endl;

  return 0;
}