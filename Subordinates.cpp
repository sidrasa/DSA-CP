#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;
const int N = 2e5 + 5;
vector<int> g[N];
vector<int> sz(N);

void dfsSize(int node) {
  sz[node] = 1;
  for (auto e : g[node]) {
    dfsSize(e);
    sz[node] += sz[e];
  }
}

int main() {
  int n;
  cin >> n;
  for (int i = 2; i <= n; i++) {
    int x;
    cin >> x;
    g[x].push_back(i);
  }
  dfsSize(1);
  for (int i = 1; i <= n; i++) {
    cout << sz[i] - 1 << " ";
  }

  return 0;
}