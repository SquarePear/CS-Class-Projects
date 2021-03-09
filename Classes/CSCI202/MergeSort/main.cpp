/*
 *  Program name: Merge Sort
 *  Author: Jeffrey Harmon
 *  Date created: Mar. 9, 2021
 *  Date last updated: Mar. 9, 2021
 *  Purpose: Merge sort some integers
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
  if (list.size() <= 1)
    return list;

  vector<int> left;
  vector<int> right;

  for (int i = 0; i < list.size(); i++)
    if (i < list.size() / 2)
      left.push_back(list[i]);
    else
      right.push_back(list[i]);

  // for (int item : left)
  //   cout << item << " ";
  // cout << endl;
  // for (int item : right)
  //   cout << item << " ";
  // cout << endl;

  sort(left);
  sort(right);

  list.clear();

  while (!left.empty() && !right.empty()) {
    if (left.front() <= right.front()) {
      list.push_back(left.front());
      left.erase(left.begin());
    } else {
      list.push_back(right.front());
      right.erase(right.begin());
    }
  }

  while (!left.empty()) {
    list.push_back(left.front());
    left.erase(left.begin());
  }

  while (!right.empty()) {
    list.push_back(right.front());
    right.erase(right.begin());
  }

  for (int item : list)
    cout << item << " ";
  cout << endl;

  return list;
}
