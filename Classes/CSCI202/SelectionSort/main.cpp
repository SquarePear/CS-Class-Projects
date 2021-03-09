/*
 *  Program name: Selection Sort
 *  Author: Jeffrey Harmon
 *  Date created: Mar. 9, 2021
 *  Date last updated: Mar. 9, 2021
 *  Purpose: Selection sort some integers
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

  for (int i = 0; i < list.size() - 1; i++) {
    pair<int, int> pick = {i, list[i]};

    for (int j = i; j < list.size(); j++)
      if (list[j] < pick.second)
        pick = {j, list[j]};

    list[pick.first] = list[i];
    list[i] = pick.second;

    for (int item : list)
      cout << item << " ";
    cout << endl;
  }

  return list;
}
