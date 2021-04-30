#pragma once

#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>

template <class K, class T> class Graph {
private:
  class Node {
  public:
    K key;
    T data;
    std::set<K> *edges;

    Node(const K key, const T &data) : key(key), data(data) {
      this->edges = new std::set<K>();
    }
  };

  // Properties
  std::map<K, Node *> *nodes = new std::map<K, Node *>();

public:
  // Methods
  unsigned int size() { return this->nodes->size(); }

  bool empty() { return this->nodes->empty(); }

  void addNode(K key, const T &data) {
    this->nodes->insert({key, new Node(key, data)});
  }

  void addEdge(K key, K toKey) { (*this->nodes)[key]->edges->insert(toKey); }

  Node *getNode(K key) { return (*this->nodes)[key]; }

  bool *getEdge(K key, K toKey) {
    return (*this->nodes)[key]->edges->contains(toKey);
  }

  void print() {
    if (this->empty())
      return;

    // Go through map and print each node
    for (std::pair<K, Node *> el : *this->nodes) {
      std::cout << el.second->key << " : " << el.second->data << " | ";

      // Print nodes edges
      for (K edge : *el.second->edges) {
        std::cout << edge << ", ";
      }

      std::cout << std::endl;
    }
  }

  void printBreadthFirst(K startKey) {
    if (this->empty())
      return;

    std::set<K> visited;
    std::queue<Node *> queue;

    // Add starting node
    queue.push(this->getNode(startKey));
    visited.insert(startKey);

    // Run until queue empty
    while (!queue.empty()) {
      Node *current = queue.front();

      // Check each edge
      for (K key : *current->edges) {
        if (visited.contains(key))
          continue;

        // Add key to queue
        visited.insert(key);
        queue.push(this->getNode(key));
      }

      std::cout << current->key << ", ";

      queue.pop();
    }

    std::cout << std::endl;
  }

  void printDepthFirst(K startKey) {
    if (this->empty())
      return;

    std::set<K> visited;
    std::stack<Node *> stack;

    // Add starting node
    stack.push(this->getNode(startKey));
    visited.insert(startKey);

    std::cout << startKey << ", ";

    // Run until stack empty
    while (!stack.empty()) {
      Node *current = stack.top();

      bool done = true;

      // Check each edge
      for (K key : *current->edges) {
        if (visited.contains(key))
          continue;

        // Add key to stack
        visited.insert(key);
        std::cout << key << ", ";
        stack.push(this->getNode(key));

        done = false;

        break;
      }

      if (done)
        stack.pop();
    }

    std::cout << std::endl;
  }

  void clear() {
    if (this->empty())
      return;

    this->nodes.clear();
  }
};
