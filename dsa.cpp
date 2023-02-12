#include <bits/stdc++.h>
#include <iostream>
using namespace std;
const int N = 1e3;
int dp[N][N];

int rec(int n1, int n2, string &s1, string &s2) {
  if (n1 == 0)
    return 0;
  if (n2 == 0)
    return 0;
  int ans = 0;
  if (dp[n1][n2] != -1)
    return dp[n1][n2];
  if (s1[n1 - 1] == s2[n2 - 1]) {
    ans = rec(n1 - 1, n2 - 1, s1, s2) + 1;
  } else {
    ans = max(rec(n1 - 1, n2, s1, s2), rec(n1, n2 - 1, s1, s2));
  }
  dp[n1][n2] = ans;
}

int main() {
  memset(dp, -1, sizeof(dp));
  return 0;
}