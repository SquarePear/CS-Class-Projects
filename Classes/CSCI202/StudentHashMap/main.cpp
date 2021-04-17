/*
 *  Program name: Student Hash Map
 *  Author: Jeffrey Harmon
 *  Date created: Apr. 14, 2021
 *  Date last updated: Apr. 18, 2021
 *  Purpose: Input and display information about customers stored in a linked
 *           list
 */

#include "hashmap.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Student {
public:
  string ID;
  string name;
  string email;

  friend ostream &operator<<(std::ostream &, const Student &);
};

template <class K> unsigned int hashFunction(K);

int main() {
  HashMap<string, Student> students(25, &hashFunction);

  Student search;

  unsigned int lines;

  cout << "How many entries would you like to enter from the file? (<=0 for "
          "all): ";
  if (!(cin >> lines))
    lines = 0;

  cout << endl;

  ifstream file("StudentList.txt");

  try {
    if (!file.is_open())
      goto LOOPEND;

    while (!file.eof()) {
      if (lines > 0 && students.size() >= lines)
        goto LOOPEND;
      Student student;
      string input;
      vector<string> output;

      getline(file, input);

      stringstream ss(input);

      while (ss.good()) {
        string substr;
        getline(ss, substr, ',');
        output.push_back(substr);
      }

      student.ID = output[0];
      student.name = output[1];
      student.email = output[2];

      if (students.size() == 48)
        search = student;

      students.insert(student.ID, student);
    }

  } catch (const std::exception &e) {
  }

LOOPEND:

  file.close();

  students.print();

  string ID;

  cout << endl << endl;

  cout << "Enter an ID to search: ";
  cin >> ID;

  auto node = students.get(ID);

  if (node != nullptr)
    cout << endl << node->key << " - " << node->item << endl;
  else
    cout << "ID not found." << endl;

  return 0;
}

template <class K> unsigned int hashFunction(K key) {
  unsigned int total = 0;

  for (int i = 0; i < key.length(); i++)
    total += int(key[i]) * int('9') * i;

  return total;
}

ostream &operator<<(std::ostream &o, const Student &student) {
  return o << student.name;
}