#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(vector<vector<pair<int, int>>> &graph, int src) {
  int n = graph.size();
  vector<int> dist(n, INT_MAX);
  dist[src] = 0;
  vector<bool> visited(n, false);

  // Repeat V times (for all nodes)
  for (int count = 0; count < n; count++) {
    // Find unvisited node with minimum distance
    int u = -1;
    int minDist = INT_MAX;

    for (int v = 0; v < n; v++) {
      if (!visited[v] && dist[v] < minDist) {
        minDist = dist[v];
        u = v;
      }
    }

    if (u == -1)
      break; // All remaining nodes unreachable
    visited[u] = true;

    // Update distances to neighbors (relaxation)
    for (auto &edge : graph[u]) {
      int v = edge.second;
      int weight = edge.first;

      if (!visited[v] && dist[u] + weight < dist[v]) {
        dist[v] = dist[u] + weight;
      }
    }
  }
  return dist;
}

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<pair<int, int>>> graph(n);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    graph[u].push_back({w, v});
  }

  vector<int> dist = dijkstra(graph, 0);
  for (int i = 0; i < n; i++) {
    cout << dist[i] << " ";
  }
  cout << endl;

  return 0;
}
