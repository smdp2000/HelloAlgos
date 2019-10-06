/*
** BFS Traversal of an undirected and unweighted graph.
**Idea is to implement the adjacency list as an array of vectors:*/
#include <bits/stdc++.h>
using namespace std;

void createAndAddEdge(vector <int> adjList[], int u, int v){
  adjList[u].push_back(v);
  adjList[v].push_back(u); // do this because undirected graph
}

void BFS(vector <int> adjList[], vector <bool> visitedVertex, int source){
  queue <int> Q; //set up Queue for BFS
  int v;
  Q.push(source);
  while (!Q.empty()){      // While Queue is not empty
    v = Q.front();
    visitedVertex.at(v) = true;
    Q.pop();
    cout << v << " "; // Print Vertex
    for (vector<int>::iterator it = adjList[v].begin(); it != adjList[v].end(); it++) // Visit all children
      if (!visitedVertex.at(*it)){    // if not visited
        Q.push(*it); // Push unvisted vertex onto the queue
        visitedVertex.at(*it) = true;
      }
  }
  cout << endl;
}

int main (void){
  const int numVertices = 5;
  int source = 0;
  vector<int> adjList[numVertices];
  vector <bool> visitedVertex(numVertices, false);
  createAndAddEdge(adjList, 0, 1);
  createAndAddEdge(adjList, 0, 2);
  createAndAddEdge(adjList, 1, 2);
  createAndAddEdge(adjList, 1, 3);
  createAndAddEdge(adjList, 1, 4);
  createAndAddEdge(adjList, 2, 3);
  createAndAddEdge(adjList, 3, 4);
  BFS(adjList, visitedVertex, source); // Perform BFS given graph G and a source s
  //should print: 0 1 2 3 4
}
