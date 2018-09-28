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

  /* Bidirectional BFS members */
  std::vector<bool> sVisited;  // visited nodes from source
  std::vector<bool> dVisited;  // visited nodes from destination
  std::vector<int> sParents;
  std::vector<int> dParents;
  void BFSstep(std::queue<int> &q, std::vector<bool> &visited, std::vector<int> &parent);
  int isIntersecting();
  void printPath(int s, int d);


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
  bool biBFS(int s, int d);
};

#endif