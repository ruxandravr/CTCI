#ifndef CTCI_GRAPHS_H
#define CTCI_GRAPHS_H

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

class Graph
{
private:
  int nodes, edges;
  std::vector<bool> visited;
  std::vector<int> visitedState;
  std::vector<int> topsort;
  std::vector<int> inDegrees;

public:
  Graph(int n, int m);
  void insertUndirected(int x, int y);
  void insertDirected(int x, int y);
  std::vector<std::vector<int> > adjList;
  bool isPath(int x, int y);
  void dfsTopsort(int node, std::vector<int> &topsort);
  void sort();
  void khan();
  std::vector<int> getTopsort();
};

#endif