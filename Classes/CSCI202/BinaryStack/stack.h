#pragma once

#include <iostream>
#include <string>

template <class T> class Node {
public:
  T item;
  Node<T> *next;

  Node(const T item) : item(item), next(nullptr) {}
};

template <class T> class Stack {
private:
  // Properties
  Node<T> *head = nullptr;
  unsigned int count = 0;
  unsigned int capacity;

public:
  // Getters
  int size() { return count; }

  // Methods
  void push(T item) {
    if (capacity != 0 && count == capacity)
      throw std::overflow_error("");

    Node<T> *temp = new Node<T>(item);

    temp->next = this->head;

    this->head = temp;

    this->count++;
  }

  T value() { return this->head->item; }

  T pop() {
    if (count == 0 || this->head == nullptr)
      throw std::underflow_error("");

    T temp = this->head->item;

    this->head = this->head->next;

    this->count--;

    return temp;
  }

  void purge() {
    Node<T> *temp;

    while (this->head != nullptr) {
      temp = this->head->next;
      delete this->head;

      this->head = temp;
    }

    this->count = 0;
  }

  bool empty() { return this->count == 0; }

  // Overrides
  ~Stack() { purge(); }

  Stack<T> &operator=(const Stack<T> &other) { return *this; }

  // Constructors
  Stack(unsigned int capacity = 0) { this->capacity = capacity; }

  Stack(const Stack<T> &other) {
    this->purge();

    this->count = other.count;
    this->capacity = other.capacity;

    if (other.head == nullptr)
      return;

    Node<T> *temp = other.head;
    Node<T> *current = new Node<T>(temp->item);
    this->head = current;

    while (temp->next != nullptr) {
      temp = temp->next;
      current->next = new Node<T>(temp->item);

      current = current->next;
    }
  }
};
