#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;
const int N = 1e5 + 5;
vector<int> g[N];
vector<int> vis(N);
bool ok = 1;

void dfs(int s, int c = 1) {
  vis[s] = c;
  for (auto e : g[s]) {
    if (!vis[e]) {
      // not assigned a color
      int nc;
      if (c == 1)
        nc = 2;
      else
        nc = 1;
      dfs(e, nc);
    } else {
      // it has some color
      if (vis[e] == vis[s]) // same color
        ok = 0;
    }
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      dfs(i);
    }
  }
  if (ok) {
    for (int i = 1; i <= n; i++) {
      cout << vis[i] << " ";
    }
  } else {
    cout << "IMPOSSIBLE";
  }

  return 0;
}