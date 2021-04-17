#pragma once

#include <iostream>
#include <string>

template <class K, class T> class HashMap {
private:
  class Node {
  public:
    K key;
    T item;
    Node *next;

    Node(const K key, const T &item, Node *next = nullptr)
        : key(key), item(item), next(next) {}
  };

  // Properties
  Node **list = nullptr;
  unsigned int (*hashFunction)(K) = nullptr;
  unsigned int length = 0;
  unsigned int count = 0;

  unsigned int getIndex(K key) {
    unsigned int hash = hashFunction(key);
    return hash % this->length;
  }

  Node *getRoot(K key) {
    unsigned int index = getIndex(key);
    return this->list[index];
  }

  Node *setRoot(K key, T &item) {
    unsigned int index = getIndex(key);
    Node *current = this->list[index];

    this->list[index] =
        new Node(key, item, (current == nullptr) ? nullptr : current);

    return this->list[index];
  }

public:
  // Getters
  unsigned int size() { return this->count; }

  // Methods
  void insert(K key, T &item) {
    this->setRoot(key, item);
    this->count++;
  }

  Node *get(K key) {
    Node *current = getRoot(key);

    if (current == nullptr)
      return nullptr;

    while (current->next != nullptr && current->key != key)
      current = current->next;

    if (current->key == key)
      return current;

    return nullptr;
  }

  void print() {
    if (this->count == 0)
      return;

    std::cout << "Total entries: " << this->count << std::endl;
    std::cout << std::endl;

    for (int i = 0; i < this->length; i++) {
      int num = 0;
      std::cout << i << ": ";

      Node *current = this->list[i];

      while (current != nullptr) {
        std::cout << current->item << ", ";
        current = current->next;
        num++;
      }

      std::cout << num << std::endl;
    }
  }

  void empty() {
    if (this->count == 0)
      return;

    for (int i = 0; i < this->length; i++) {

      Node *current = this->list[i];
      Node *temp;

      if (current == nullptr)
        continue;

      while (current != nullptr) {
        temp = current->next;

        delete current;

        current = temp;
      }

      this->list[i] = nullptr;
    }
  }

  // Overrides
  ~HashMap() {
    empty();

    delete[] this->list;
  }

  // Constructor
  HashMap(unsigned int size, unsigned int (*hashFunction)(K)) {
    this->length = size;
    this->list = new Node *[size];
    this->hashFunction = hashFunction;
  }
};
