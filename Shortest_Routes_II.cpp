#include <bits/stdc++.h>
using namespace std;
#include <iostream>
#include <queue>
#include <vector>
using ll = long long;
ll INF = 1e18;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m, q;
  cin >> n >> m >> q;

  vector<vector<ll>> dp(n, vector<ll>(n, INF));

  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w, u--, v--;
    if (w < dp[u][v])
      dp[u][v] = dp[v][u] = w;
  }

  // floyd-warshall
  for (int k = 0; k < n; k++)
    for (int i = 0; i < n; i++)
      for (int j = i + 1; j < n; j++)
        if (dp[i][k] + dp[k][j] < dp[i][j])
          dp[i][j] = dp[j][i] = dp[i][k] + dp[k][j];

  while (q--) {
    int u, v;
    cin >> u >> v, u--, v--;
    if (u == v)
      dp[u][v] = 0;
    if (dp[u][v] == INF)
      dp[u][v] = -1;
    cout << dp[u][v] << "\n";
  }
}