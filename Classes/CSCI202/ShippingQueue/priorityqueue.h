#pragma once

#include <iostream>
#include <string>

#ifndef NODE
#define NODE

template <class T> class Node {
public:
  T item;
  Node<T> *next;

  Node(const T item) : item(item), next(nullptr) {}
};

#endif

template <class T> class PriorityQueue {
private:
  // Properties
  Node<T> *head = nullptr;
  Node<T> *tail = nullptr;
  unsigned int count = 0;
  unsigned int capacity;

public:
  // Getters
  int size() { return this->count; }
  int maxCapacity() { return this->capacity; }

  // Methods
  void push(T item) {
    if (capacity != 0 && count == capacity)
      throw std::overflow_error("Queue is already full");

    Node<T> *temp = new Node<T>(item);

    if (this->count == 0) {
      this->head = temp;
      this->count++;

      return;
    } else if (this->tail == nullptr) {
      if (temp->item > this->head->item) {
        this->tail = this->head;
        this->head = temp;
        this->head->next = this->tail;
      } else {
        this->head->next = temp;
        this->tail = temp;
      }

      this->count++;

      return;
    }

    if (temp->item > this->head->item) {
      temp->next = this->head;
      this->head = temp;
      count++;

      return;
    }

    if (!(temp->item > this->tail->item)) {
      this->tail->next = temp;
      this->tail = temp;
      count++;

      return;
    }

    Node<T> *current = this->head;

    Node<T> *next = this->head->next;

    while (current->next != nullptr) {
      if (!(current->item > next->item) || current->item > temp->item) {
        current = next;
        next = current->next;

        continue;
      }

      current->next = temp;
      temp->next = next;

      break;
    }

    if (next == nullptr) {
      current->next = temp;
      this->tail = temp;

      std::cout << "HMAMAMAMA";
    }

    this->count++;
  }

  T value() { return this->head->item; }

  T pop() {
    if (count == 0 || this->head == nullptr)
      throw std::underflow_error("Queue is already empty");

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
  ~PriorityQueue() { purge(); }

  PriorityQueue<T> &operator=(const PriorityQueue<T> &other) { return *this; }

  // Constructors
  PriorityQueue(unsigned int capacity = 0) { this->capacity = capacity; }

  PriorityQueue(const PriorityQueue<T> &other) {
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

    this->tail = current;
  }
};
