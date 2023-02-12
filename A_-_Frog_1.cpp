#include <bits/stdc++.h>
#include <iostream>
using namespace std;
const int N = 1e5 + 5;
int dp[N];

int rec(int n, int a[]) {
  if (n == 1)
    return 0;
  if (dp[n] != -1)
    return dp[n];
  int ans = INT_MAX;
  if ((n - 1) >= 1) { // can I take 1 step
    ans = min(ans, rec(n - 1, a) + abs(a[n - 2] - a[n - 1]));
  }
  if ((n - 2) >= 1) { // can I take 2 step
    ans = min(ans, rec(n - 2, a) + abs(a[n - 3] - a[n - 1]));
  }
  dp[n] = ans;
  return ans;
}

int main() {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i <= n; i++) {
    dp[i] = -1;
  }
  cout << rec(n, a) << "\n";

  return 0;
}