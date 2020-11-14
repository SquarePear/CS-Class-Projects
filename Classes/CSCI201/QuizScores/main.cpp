/*
 *  Program name: Quiz Scores
 *  Author: Jeffrey Harmon
 *  Date created: Nov. 9, 2020
 *  Date last updated: Nov. 13, 2020
 *  Purpose: Display information about a list of quiz scores
 */

#include <array>
#include <iostream>

using namespace std;

template <class T, int S> array<T, S> getData();
template <class T, size_t S> int averageScore(array<T, S> list);
template <class T, size_t S> int highScore(array<T, S> list);
template <class T, size_t S> int lowScore(array<T, S> list);

int main() {
  array<int, 16> scores = getData<int, 16>();

  cout << "Fall 2020 Quiz Grades:" << endl;

  for (int i = 0; i < scores.size(); i++)
    cout << "	Module " << i + 1 << ": " << scores[i] << endl;

  cout << "Average Grade: " << averageScore(scores) << endl;

  int low = lowScore(scores);
  int high = highScore(scores);

  cout << "Your lowest score was in Module " << low + 1 << " with "
       << scores[low] << endl;
  cout << "Your highest score was in Module " << high + 1 << " with "
       << scores[high] << endl;

  return 0;
}

template <class T, int S> array<T, S> getData() {
  array<T, S> scores;

  for (int i = 0; i < scores.size(); i++) {
    bool valid = true;

    if (!(cin >> scores[i])) {
      cout << "There was something entered that is not a number! ";

      cin.clear();
      cin.ignore(1000, '\n');
      valid = false;
    } else if (scores[i] < 0) {
      cout << "The score cannot be less than 0. ";
      valid = false;
    } else if (scores[i] > 100) {
      cout << "The score cannot be greater than 100. ";
      valid = false;
    }

    if (!valid) {
      cout << "Setting the score to 0." << endl;
      scores[i] = 0;
    }
  }

  return scores;
}

template <class T, size_t S> int averageScore(array<T, S> list) {
  T total = 0;

  for (int i = 0; i < list.size(); i++)
    total += list[i];

  return total / list.size();
}

template <class T, size_t S> int highScore(array<T, S> list) {
  int highest = 0;

  for (int i = 0; i < list.size(); i++)
    if (list[highest] < list[i])
      highest = i;

  return highest;
}

template <class T, size_t S> int lowScore(array<T, S> list) {
  int lowest = 0;

  for (int i = 0; i < list.size(); i++)
    if (list[lowest] > list[i])
      lowest = i;

  return lowest;
}
