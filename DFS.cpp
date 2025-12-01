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

// Recursive DFS
void dfsRecursive(vector<vector<int>> &graph, int u, vector<bool> &visited) {
  visited[u] = true;
  cout << u << " ";

  for (int v : graph[u]) {
    if (!visited[v]) {
      dfsRecursive(graph, v, visited);
    }
  }
}

// Iterative DFS using stack
void dfsIterative(vector<vector<int>> &graph, int start) {
  vector<bool> visited(graph.size(), false);
  stack<int> st;

  st.push(start);

  while (!st.empty()) {
    int u = st.top();
    st.pop();

    if (!visited[u]) {
      visited[u] = true;
      cout << u << " ";

      for (int i = graph[u].size() - 1; i >= 0; i--) {
        int v = graph[u][i];
        if (!visited[v]) {
          st.push(v);
        }
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

  cout << "Recursive DFS from 0: ";
  vector<bool> visited(graph.size(), false);
  dfsRecursive(graph, 0, visited);
  cout << endl;

  cout << "Iterative DFS from 0: ";
  dfsIterative(graph, 0);
  cout << endl;

  return 0;
}

// 4 4
// 0 1
// 1 2
// 2 0
// 2 3

