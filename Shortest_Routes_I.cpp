#include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int N = 1e5 + 5;
using ll = long long int;
vector<vector<pair<ll, ll>>> g;
vector<ll> cost(N);

void dks() {
  priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
  cost[1] = 0;
  pq.push({1, 0});
  while (!pq.empty()) {
    ll u = pq.top().first; // top node
    ll c = pq.top().second;
    pq.pop();
    for (auto e : g[u]) {
      int v = e.first;
      int cst = e.second;
      if (cost[v] < cst + c)
        continue;
      cost[v] = cst + c;
      pq.push({v, cost[v]});
    }
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  g.resize(n + 1);
  fill(cost.begin(), cost.end(), 1e15);
  for (int i = 0; i < m; i++) {
    ll u, v, c;
    cin >> u >> v >> c;
    g[u].push_back(make_pair(v, c));
  }
  dks();
  for (int i = 1; i <= n; i++) {
    cout << cost[i] << " ";
  }

  return 0;
}