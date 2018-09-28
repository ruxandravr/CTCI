#include "Graphs.h"

Graph::Graph(int n, int m)
{
  nodes = n;
  edges = m;
  adjList = std::vector<std::vector<int> >(nodes + 1);
  visited = std::vector<bool>(n + 1, false);
  visitedState = std::vector<int>(n + 1, 0);
  inDegrees = std::vector<int>(n + 1, 0);

  sVisited = std::vector<bool>(n + 1, false);
  dVisited = std::vector<bool>(n + 1, false);
  sParents = std::vector<int>(n + 1, -1);
  dParents = std::vector<int>(n + 1, -1);
}

/* Insert an edge in the undirected graph. */
void Graph::insertUndirected(int x, int y)
{
  adjList[x].push_back(y);
  adjList[y].push_back(x);
}

/* Insert an edge in the directed graph. */
void Graph::insertDirected(int x, int y)
{
  adjList[x].push_back(y);
  inDegrees[y]++;
}

/* Check if there is a path from x to y in the graph by doing a bfs search from
x and checking if y is in the path. */
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

/* Topological sort the nodes by doing a dfs. */
void Graph::sort()
{
  for (int i = 1; i <= nodes; ++i) {
    if (visitedState[i] == 0) {
      dfsTopsort(i, topsort);
    }
  }
  std::reverse(topsort.begin(), topsort.end());
}


void Graph::dfsTopsort(int node, std::vector<int> &topsort)
{
  visitedState[node] = 1;
  for (auto neigh : adjList[node]) {
    if (visitedState[neigh] == 0) { // unvisited node
      dfsTopsort(neigh, topsort);
    }
    /* If we encounter a node in the state of visiting it means the graph has
    a cycle. */
    if (visitedState[neigh] == 1) {
      std::cout << "Cycle\n";
      break;
    }
  }
  /* Visited node, we push it to the sorted vector. */
  visitedState[node] = 2;
  topsort.push_back(node);
}

std::vector<int> Graph::getTopsort()
{
  return topsort;
}

/* Sort the nodes by using the khan algorithm. */
void Graph::khan()
{
  std::queue<int> q;
  for (int i = 1; i <= nodes; ++i) {
    if (inDegrees[i] == 0) {
      q.push(i);
    }
  }

  while (!q.empty()) {
    int node = q.front();
    q.pop();
    topsort.push_back(node);
    for (auto neigh : adjList[node]) {
      inDegrees[neigh]--;
      if (inDegrees[neigh] == 0) {
        q.push(neigh);
      }
    }
  }
  /* If the topsort vector doesn't contain all the nodes, there was a cycle. */
  if (topsort.size() != nodes) {
    std::cout << "Cycle\n";
  }
}

/* One step of the BFS search: visit a node and all its neighbours, update
their parents */
void Graph::BFSstep(std::queue<int> &q, std::vector<bool> &visited,
                    std::vector<int> &parent)
{
  int node = q.front();
  q.pop();

  for (auto neigh : adjList[node]) {
    if (!visited[neigh]) {
      visited[neigh] = true;
      parent[neigh] = node;
      q.push(neigh);
    }
  }
}

int Graph::isIntersecting()
{
  for (int i = 1; i <= nodes; ++i) {
    if (sVisited[i] && dVisited[i]) {
      return i;
    }
  }
  return -1;
}


/* Bidirectional BFS: take one step gradually fom both source and destination
and verify if the paths intersect. */
bool Graph::biBFS(int s, int d)
{
  std::queue<int> sQueue;
  std::queue<int> dQueue;


  sVisited = std::vector<bool>(nodes + 1, false);
  dVisited = std::vector<bool>(nodes + 1, false);
  sParents = std::vector<int>(nodes + 1, -1);
  dParents = std::vector<int>(nodes + 1, -1);

  sQueue.push(s);
  dQueue.push(d);

  while (!sQueue.empty() && !dQueue.empty()) {
    BFSstep(sQueue, sVisited, sParents);
    int intersecting = isIntersecting();
    if (intersecting != -1) {
      // printPath(s, d);
      return true;
    }
    BFSstep(dQueue, dVisited, dParents);

    intersecting = isIntersecting();

    if (intersecting != -1) {
      // printPath(s, d);
      return true;
    }
  }
  return false;
}

/* Print the path taken from source to destination by using parents vectors. */
void Graph::printPath(int s, int d)
{
  std::vector<int> path;
  int intersecting = isIntersecting();
  path.push_back(intersecting);

  int i = intersecting;
  while (s != i) {
    path.push_back(sParents[i]);
    i = sParents[i];
  }

  std::reverse(path.begin(), path.end());

  i = intersecting;
  while (d != i) {
    path.push_back(dParents[i]);
    i = dParents[i];
  }

  for (auto elem : path) {
    std::cout << elem << " ";
  }
  std::cout << "\n";
}