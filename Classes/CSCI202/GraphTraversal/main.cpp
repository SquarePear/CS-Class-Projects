/*
 *  Program name: Graph Traversal
 *  Author: Jeffrey Harmon
 *  Date created: Apr. 28, 2021
 *  Date last updated: Apr. 29, 2021
 *  Purpose: Input and display a graph and its edges
 */

#include "graph.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main() {
  Graph<string, string> graph;
  string first;

  ifstream file("graph.txt");

  try {
    while (!file.eof()) {
      string in;

      getline(file, in);

      stringstream line;

      line << in;

      string key;
      string data;

      // Read node and its data
      getline(line, key, ' ');
      getline(line, data, ' ');

      if (first == "")
        first = key;

      graph.addNode(key, data);

      string edgeKey;

      // Read each edge
      while (getline(line, edgeKey, ' ')) {
        graph.addEdge(key, edgeKey);
      }
    }
  } catch (const std::exception &e) {
  }

  file.close();

  graph.print();

  cout << endl << "Breadth First:" << endl;
  graph.printBreadthFirst(first);

  cout << endl << "Depth First:" << endl;
  graph.printDepthFirst(first);

  return 0;
}
