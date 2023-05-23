#include <iostream>
#include <climits>
using namespace std;

#define V 6
#define INF INT_MAX

int G[V][V] = {
  {0, 3, 0, 0, 0, 1},
  {3, 0, 2, 1, 10, 0},
  {0, 2, 0, 3, 0, 5},
  {0, 1, 3, 0, 5, 0},
  {0, 10, 0, 5, 0, 4},
  {1, 0, 5, 0, 4, 0}
};

int findMinKey(int key[], bool mstSet[]) {
  int minKey = INF, minIndex;
  for (int v = 0; v < V; v++) {
    if (!mstSet[v] && key[v] < minKey) {
      minKey = key[v];
      minIndex = v;
    }
  }
  return minIndex;
}

void printMST(int parent[]) {
  cout << "Edge : Weight\n";
  for (int i = 1; i < V; i++) {
    cout << parent[i] << " - " << i << " : " << G[i][parent[i]] << "\n";
  }
}

void primMST() {
  int parent[V];
  int key[V];
  bool mstSet[V];

  for (int i = 0; i < V; i++) {
    key[i] = INF;
    mstSet[i] = false;
  }

  key[0] = 0;
  parent[0] = -1;

  for (int count = 0; count < V - 1; count++) {
    int u = findMinKey(key, mstSet);
    mstSet[u] = true;

    for (int v = 0; v < V; v++) {
      if (G[u][v] && !mstSet[v] && G[u][v] < key[v]) {
        parent[v] = u;
        key[v] = G[u][v];
      }
    }
  }

  printMST(parent);
}

int main() {
  primMST();
  return 0;
}
