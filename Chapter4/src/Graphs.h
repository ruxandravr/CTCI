#ifndef CTCI_GRAPHS_H
#define CTCI_GRAPHS_H

#include <iostream>
#include <vector>
#include <queue>

class Graph
{
private:
  int nodes, edges;
  std::vector<bool> visited;

public:
  Graph(int n, int m);
  void insert(int x, int y);
  std::vector<std::vector<int> > adjList;
  bool isPath(int x, int y);
};

Graph::Graph(int n, int m)
{
  nodes = n;
  edges = m;
  adjList = std::vector<std::vector<int> >(nodes + 1);
  visited = std::vector<bool>(n + 1, false);
}

void Graph::insert(int x, int y)
{
  adjList[x].push_back(y);
  adjList[y].push_back(x);
}

bool Graph::isPath(int x, int y)
{
  if (x == y) {
    return true;
  }
  visited = std::vector<bool>(nodes + 1, false);
  visited[x] = true;

  std::queue<int> q;
  q.push(x);

  while(!q.empty()) {
    int node = q.front();
    q.pop();
    for (auto neigh : adjList[node]) {
      if (neigh == y) {
        return true;
      }
      if (visited[neigh] == false) {
        q.push(neigh);
        visited[neigh] = true;
      }
    }
  }
  return false;
}

#endif