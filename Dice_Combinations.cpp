#include <bits/stdc++.h>
#include <iostream>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;
const int N = 1e6;

// int rec(int i) {
//   int ans = 0;
//   if (i == 0)
//     ans = 1;
//   else {
//     for (int d = 1; d <= 6; d++) {
//       if (i - d >= 0) {
//         ans += rec(i - d);
//       }
//     }
//   }
//   return ans;
// }

int main() {
  int n;
  cin >> n;
  int dp[N + 1];
  memset(dp, -1, sizeof(dp));
  for (int i = 0; i <= n; i++) {
    ll ans = 0;
    if (i == 0)
      ans = 1;
    else {
      for (int d = 1; d <= 6; d++) {
        if (i - d >= 0) {
          ans += dp[i - d];
          ans %= mod;
        }
      }
    }
    dp[i] = ans;
  }
  cout << dp[n];

  return 0;
}