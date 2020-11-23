/*
 *  Program name: Nerf Manager
 *  Author: Jeffrey Harmon
 *  Date created: Nov. 20, 2020
 *  Date last updated: Nov. 20, 2020
 *  Purpose: Create, display, and manage a list of nerf guns
 */

#include "nerfgun.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>

using namespace std;

int main() {
  vector<nerfGun> nerfGuns;

  nerfGuns.push_back(nerfGun("Firestrike", 23, 3));
  nerfGuns.push_back(nerfGun("Strongarm", 23, 6));
  nerfGuns.push_back(nerfGun("Jolt", 21, 1));
  nerfGuns.push_back(nerfGun("Magnus", 25, 3));

  nerfGun mostAmmo = *nerfGuns.begin();

  for (int i = 0; i < nerfGuns.size(); i++) {
    cout << nerfGuns[i] << endl;

    if (nerfGuns[i] > mostAmmo)
      mostAmmo = nerfGuns[i];
  }

  cout << endl;
  cout << "Most Ammo:" << endl;
  cout << mostAmmo << endl;

  cout << endl;
  cout << "Random time:" << endl;

  try {
    srand(time(NULL));

    while (true) {
      nerfGun randomGun = nerfGuns[rand() % nerfGuns.size()];

      if (rand() % 2 == 1)
        randomGun.fire();
      else
        randomGun.reload(rand() % randomGun.getCapacity());

      cout << randomGun << endl;
    }

  } catch (const exception &e) {
    cerr << endl << e.what() << endl;
  }

  return 0;
}