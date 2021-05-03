#pragma once

#include <functional>
#include <iostream>
#include <string>
#include <time.h>
#include <vector>

class BlockChain {
private:
  class Block {
  private:
    // Properties
    unsigned int number;
    unsigned int nonce;
    std::string data;
    std::string previousHash;
    std::string hash;

  public:
    // Getters
    unsigned int getNumber() { return this->number; }
    unsigned int getNonce() { return this->nonce; }
    std::string getData() { return this->data; }
    std::string getHash() { return this->hash; }
    std::string getPreviousHash() { return this->previousHash; }

    // Methods
    void hack(std::string newData) {
      this->data = newData;
      this->hash = this->genHash();
    }

    std::string genHash(std::string previousHash = "") {
      if (previousHash.empty())
        previousHash = this->previousHash;

      std::hash<std::string> str_hash;

      return std::to_string(str_hash(std::to_string(this->number) +
                                     std::to_string(this->nonce) + this->data +
                                     previousHash));
    }

    bool validate(std::string previousHash) {
      return hash == this->genHash(previousHash);
    }

    void print(std::string previousHash) {
      std::cout << "Block #" << this->number << std::endl;
      std::cout << "Data: " << this->data << std::endl;
      std::cout << "Hash: " << this->hash << std::endl;
      std::cout << "Previous Hash: " << this->previousHash << std::endl;
      std::cout << "Valid: " << std::boolalpha << this->validate(previousHash)
                << std::endl;
    }

    // Constructors
    Block(unsigned int number, std::string data, std::string previousHash = "")
        : number(number), data(data), previousHash(previousHash) {
      this->nonce = std::time(NULL);
      this->hash = this->genHash();
    }
  };

  // Properties
  std::vector<Block> blocks;

public:
  // Getters
  unsigned int size() { return this->blocks.size(); }

  // Methods
  bool validate() {
    if (this->blocks.size() == 0)
      return true;

    std::string previousHash;

    for (Block block : this->blocks) {
      if (!block.validate(previousHash))
        return false;

      previousHash = block.getHash();
    }

    return true;
  }

  Block addBlock(std::string data) {
    if (!this->validate())
      throw std::runtime_error("Invalid chain!");

    std::string previousHash =
        (this->blocks.size() == 0)
            ? ""
            : this->blocks[this->blocks.size() - 1].getHash();

    Block block(this->blocks.size(), data, previousHash);

    this->blocks.push_back(block);

    return block;
  }

  Block removeBlock() {
    if (this->blocks.size() == 0)
      throw std::out_of_range("No blocks to remove!");

    Block block = *this->blocks.end();

    this->blocks.pop_back();

    return block;
  }

  Block getBlock(unsigned int number) {
    if (number < 0 || number >= this->blocks.size())
      throw std::out_of_range("No block #" + std::to_string(number) + "!");

    return this->blocks[number];
  }

  void hackBlock(unsigned int number, std::string data) {
    if (number < 0 || number >= this->blocks.size())
      throw std::out_of_range("No block #" + std::to_string(number) + "!");

    this->blocks[number].hack(data);
  }

  void print() {
    if (this->blocks.size() == 0)
      return;

    std::string previousHash;

    for (Block block : this->blocks) {
      block.print(previousHash);
      std::cout << std::endl;

      previousHash = block.genHash(previousHash);
    }
  }
};
