#pragma once

#include <iostream>
#include <string>

template <class T> class BinaryTree {
private:
  class Node {
  public:
    T item;
    Node *left;
    Node *right;

    Node(const T &item) : item(item), left(nullptr), right(nullptr) {}

    void print() {
      if (this->left != nullptr)
        this->left->print();

      std::cout << this->item << std::endl;

      if (this->right != nullptr)
        this->right->print();
    }

    ~Node() {
      if (this->left != nullptr)
        delete this->left;
      if (this->right != nullptr)
        delete this->right;
    }
  };

  // Properties
  Node *head = nullptr;
  int count = 0;

public:
  // Getters
  int size() { return count; }

  // Methods
  void insert(T &item) {
    Node *tmp = new Node(item);
    this->count++;

    // Add to head if empty
    if (this->head == nullptr) {
      this->head = tmp;

      return;
    }

    // Sort into tree
    Node *current = nullptr;
    Node *next = this->head;

    while (next != nullptr) {
      if (next->item == tmp->item)
        throw std::runtime_error("No duplicates allowed!");

      current = next;

      next = (current->item > tmp->item) ? current->left : current->right;
    }

    if (current->item > tmp->item)
      current->left = tmp;
    else
      current->right = tmp;
  }

  // Works the first time, but everything breaks after for some reason
  T get(unsigned int index) {
    if (this->count == 0)
      throw std::out_of_range("Tree is empty.");

    // Get object by
    unsigned int traversedNodes = 1;
    Node *current = this->head;

    while (current != nullptr) {
      if (current->item == index) {
        std::cout << "Nodes traversed: " << traversedNodes << std::endl;
        return current->item;
      }

      current = (current->item > index) ? current->left : current->right;
      traversedNodes++;
    }

    std::cout << "Nodes traversed: " << traversedNodes << std::endl;
    throw std::runtime_error("Not found.");
  }

  void print() {
    // Print every node recursively
    this->head->print();
  }

  void empty() {
    // Delete every node recursively
    if (this->head != nullptr)
      delete this->head;

    this->count = 0;
  }

  // Overrides
  ~BinaryTree() { empty(); }
};
