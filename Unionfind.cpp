#include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <vector>
using ll = long long;
using namespace std;
const int N = 2e5;
vector<int> uf(N);
int leader(int n) {
  if (uf[n] == n)
    return n;
  return uf[n] = leader(uf[n]);
}

void add(int x, int y) {
  x = leader(x);
  y = leader(y);
  if (x != y) {
    uf[x] = y;
  }
}

bool same(int x, int y) {
  x = leader(x);
  y = leader(y);
  if (x != y) {
    return 0;
  }
  return 1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, q;
  cin >> n >> q;
  for (int i = 0; i < n; i++) {
    // everyone is lookibng after itself
    uf[i] = i;
  }
  while (q--) {
    int t, x, y;
    cin >> t >> x >> y;
    if (t) {
      // If vertices u,v are connected, print 1 else 0
      cout << same(x, y) << "\n";
    } else {
      // Add an edge
      add(x, y);
    }
  }

  return 0;
}