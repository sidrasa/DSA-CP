#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;
string g[8];
bool sum[15], dif[15], c[8];
int ans = 0;

void rec(int r = 0) {
  if (r == 8) {
    ans++;
    return;
  }
  for (int i = 0; i < 8; i++) {
    if (g[r][i] == '.' && !c[i] && !sum[i + r] && !dif[i - r + 7]) {
      c[i] = sum[i + r] = dif[i - r + 7] = true;
      rec(r + 1);
      c[i] = sum[i + r] = dif[i - r + 7] = false;
    }
  }
}

int main() {

  for (int i = 0; i < 8; i++) {
    cin >> g[i];
  }
  rec();
  cout << ans;

  return 0;
}
