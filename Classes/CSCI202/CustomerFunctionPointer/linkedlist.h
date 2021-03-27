#pragma once

#include <iostream>
#include <string>

template <class T> class Node {
public:
  T item;
  Node<T> *next;

  Node(const T &item) : item(item), next(nullptr) {}
};

template <class T> bool compare(T a, T b) { return a > b; }

template <class T> class LinkedList {
private:
  // Properties
  Node<T> *head = nullptr;
  bool (*comparator)(T, T) = nullptr;
  int count = 0;

public:
  // Getters
  int size() { return count; }

  // Methods
  void insert(T &item) {
    this->count++;

    Node<T> *node = new Node<T>(item);

    // Add node to head if empty
    if (this->head == nullptr) {
      this->head = node;

      return;
    }

    // Handle node in front of head
    if (comparator(node->item, this->head->item)) {
      node->next = this->head;
      this->head = node;

      return;
    }

    // Place node in correct spot
    Node<T> *current = this->head;

    while (current->next != nullptr) {

      std::cout << 4 << std::endl;
      if (comparator(node->item, current->next->item)) {
        node->next = current->next;
        current->next = node;

        return;
      }

      current = current->next;
    }

    // Place node at tail if not sorted
    current->next = node;
  }

  T get(unsigned int index) {
    if (this->count == 0)
      throw std::out_of_range("List is empty.");

    if (index >= this->count || index < 0)
      throw std::out_of_range("Invalid index.");

    // Get object by index
    Node<T> *current = this->head;

    for (int i = 1; i < index; i++) {
      current = current->next;
    }

    return current->item;
  }

  void remove(T item) {
    if (this->count == 0)
      throw std::out_of_range("List is empty.");

    // Special case if head is item
    if (this->head->item == item) {
      this->head = this->head->next;
      delete this->head;

      this->count--;

      return;
    }

    // Find and update first instance of an item
    Node<T> *current = this->head->next;
    Node<T> *temp = this->head;

    while (current->item != item && current->next != nullptr) {
      temp = current;
      current = current->next;
    }

    if (current->item != item)
      return;

    temp->next = current->next;
    delete current;

    this->count--;
  }

  void print() {
    // Print every item
    Node<T> *current = this->head;

    while (current != nullptr) {
      std::cout << current->item << std::endl;
      current = current->next;
    }
  }

  void empty() {
    // Delete all items

    if (this->count == 0)
      return;

    Node<T> *current = this->head;
    Node<T> *temp;

    do {
      temp = current;
      current = current->next;
      delete temp;
    } while (current != nullptr);

    this->count = 0;
  }

  // Overrides
  ~LinkedList() { empty(); }

  // Constructors
  LinkedList() { this->comparator = &compare; }
  LinkedList(bool (*comparator)(T, T)) { this->comparator = comparator; }
};
