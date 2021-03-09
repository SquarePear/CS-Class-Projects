/*
 *  Program name: Insertion Sort
 *  Author: Jeffrey Harmon
 *  Date created: Mar. 9, 2021
 *  Date last updated: Mar. 9, 2021
 *  Purpose: Insertion sort some integers
 */

#include <iostream>
#include <vector>

using namespace std;

vector<int> sort(vector<int> &list);

int main() {
  vector<int> listOne = {37, 26, 45, 17, 5, 55, 22, 18, 2, 12, 8, 15};
  vector<int> listTwo = {48, 36, 55, 37, 35, 13, 85, 12, 23, 6, 15, 1, 10};

  sort(listOne);

  cout << endl << endl;

  sort(listTwo);

  return 0;
}

vector<int> sort(vector<int> &list) {
  vector<int> unsortedList = list;

  list.clear();

  while (!unsortedList.empty()) {
    pair<int, int> greatest = {0, unsortedList[0]};

    for (int i = 1; i < unsortedList.size(); i++)
      if (unsortedList[i] < greatest.second)
        greatest = {i, unsortedList[i]};

    list.push_back(greatest.second);
    unsortedList.erase(unsortedList.begin() + greatest.first);

    for (int item : list)
      cout << item << " ";
    for (int item : unsortedList)
      cout << item << " ";
    cout << endl;
  }

  return list;
}
