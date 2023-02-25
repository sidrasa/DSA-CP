#include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int N = 1e5 + 5;
vector<int> g[N];
vector<int> vis(N);

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  queue<int> q;
  q.push(1);
  while (!q.empty()) {
    int f = q.front();
    vis[f] = 1;
    q.pop();
    for (auto e : g[f]) {
      if (!vis[e]) {
        q.push(e);
      }
    }
  }

  return 0;
}