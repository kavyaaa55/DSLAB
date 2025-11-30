#include <bits/stdc++.h>
using namespace std;

void readGraph(vector<vector<int>> &graph, int n, int m) {
  graph.assign(n, {});
  cout << "Edges (" << m << "):" << endl;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    graph[u].push_back(v);
    // graph[v].push_back(u);  // uncomment for undirected
  }
}

void bfs(vector<vector<int>> &graph, int start) {
  vector<bool> visited(graph.size(), false);
  queue<int> q;

  visited[start] = true;
  q.push(start);

  while (!q.empty()) {
    int u = q.front();
    q.pop();
    cout << u << " ";

    for (int v : graph[u]) {
      if (!visited[v]) {
        visited[v] = true;
        q.push(v);
      }
    }
  }
}

int main() {
#ifndef ONLINE_JUDGE
  cout << "Debug mode" << endl;
#endif

  int n, m;
  cout << "Nodes, Edges: ";
  cin >> n >> m;

  vector<vector<int>> graph;
  readGraph(graph, n, m);

  cout << "BFS from 0: ";
  bfs(graph, 0);
  cout << endl;

  return 0;
}
