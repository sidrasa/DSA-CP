#include <bits/stdc++.h>
#include <iostream>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;
const int N = 1e3;
int a[N][N];
int dp[N][N];

bool safe(int x, int y, int n) {
  if (x < 0 || y < 0 || x >= n || y >= n)
    return false;
  return true;
}

int rec(int x, int y, int n) {
  if (dp[x][y] != -1) {
    return dp[x][y];
  }
  ll ans = 0;
  int rx = x;
  int ry = y + 1;
  int dx = x + 1, dy = y;
  // base case -> smallest possible case
  // start=end
  if (x == n - 1 && y == n - 1 && dp[x][y]) {
    ans = 1;
  } else {
    if (safe(rx, ry, n) && a[rx][ry]) {
      ans += rec(rx, ry, n);
      ans %= mod;
    }
    if (safe(dx, dy, n) && a[dx][dy]) {
      ans += rec(dx, dy, n);
      ans %= mod;
    }
  }
  dp[x][y] = ans;
  return ans;
}

int main() {
  int n;
  cin >> n;
  memset(dp, -1, sizeof(dp));
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < n; j++) {
      if (s[j] == '.') {
        a[i][j] = 1;
      } else {
        a[i][j] = 0;
      }
    }
  }
  cout << rec(0, 0, n);
  return 0;
}