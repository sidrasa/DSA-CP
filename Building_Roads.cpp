#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#define pb push_back
using namespace std;
const int N = 1e5 + 5;
vector<int> g[N];
int vis[N];

void dfs(int s) {
  vis[s] = 1;
  for (auto e : g[s]) {
    if (!vis[e]) {
      dfs(e);
    }
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    g[x].pb(y);
    g[y].pb(x);
  }
  int cc = 0;
  vector<int> v;
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      dfs(i);
      v.pb(i);
      cc++;
    }
  }
  cout << cc - 1 << "\n";
  for (int i = 0; i < v.size() - 1; i++) {
    cout << v[i] << " " << v[i + 1] << "\n";
  }

  return 0;
}