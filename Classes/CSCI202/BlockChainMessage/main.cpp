/*
 *  Program name: Block Chain Message
 *  Author: Jeffrey Harmon
 *  Date created: May 3, 2021
 *  Date last updated: May 3, 2021
 *  Purpose: Blockchain message digest
 */

#include "blockchain.h"
#include <iostream>
#include <string>

using namespace std;

void addBlock(BlockChain &);
void removeBlock(BlockChain &);
void validateChain(BlockChain &);
void hackBlock(BlockChain &);

int main() {
  BlockChain blockChain;
  unsigned int choice;

  while (true) {

    try {
      cout << "1) Add block" << endl;
      cout << "2) Remove block" << endl;
      cout << "3) Validate chain" << endl;
      cout << "4) Print chain" << endl;
      cout << "5) Hack block" << endl;
      cout << "6) Exit" << endl;

      cout << "Choice: ";
      if (!(cin >> choice) || choice <= 0 || choice > 6)
        throw out_of_range("Invalid choice");

      cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

      cout << endl;

      switch (choice) {
      case 1:
        addBlock(blockChain);
        break;
      case 2:
        removeBlock(blockChain);
        break;
      case 3:
        validateChain(blockChain);
        break;
      case 4:
        blockChain.print();
        break;
      case 5:
        hackBlock(blockChain);
        break;
      default:
        goto ENDLOOP;
        break;
      }
    } catch (const std::exception &e) {
      cin.clear();
      cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      cout << e.what() << endl;
    }

    cout << endl;
  }

ENDLOOP:

  blockChain.print();

  return 0;
}

void addBlock(BlockChain &blockChain) {
  string data;

  cout << "Enter blocks data: ";
  getline(cin, data);

  blockChain.addBlock(data);

  cout << "Block #" << blockChain.size() - 1 << " added!" << endl;
}

void removeBlock(BlockChain &blockChain) {
  blockChain.removeBlock();

  cout << "Block #" << blockChain.size() << " removed!" << endl;
}

void validateChain(BlockChain &blockChain) {
  cout << "Chain valid: " << std::boolalpha << blockChain.validate() << endl;
}

void hackBlock(BlockChain &blockChain) {
  if (blockChain.size() == 0)
    return;

  unsigned int number;
  string data;

  cout << "Which block would you like to hack?: ";
  if (!(cin >> number) || number < 0 || number >= blockChain.size())
    throw out_of_range("Invalid input!");

  cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  cout << "Enter new data for block #" << number << ": ";
  getline(cin, data);

  blockChain.hackBlock(number, data);

  cout << "Block #" << number << " hacked!" << endl;
}
