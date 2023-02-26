//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
#include <iostream>

// } Driver Code Ends
// User function Template for C++

const int N = 6;
class Solution {
public:
  vector<int> bestPrice(int n, vector<vector<int>> p, int k, int nq,
                        vector<vector<int>> q) {
    // code here
    vector<int> ans;
    vector<int> f(N, 0);
    for (int i = 0; i < n; i++) {
      int l = p[i][0], r = p[i][1];
      f[l]++, f[r + 1]--;
    }
    for (auto e : f) {
      cout << e << " ";
    }
    cout << "\n";
    for (int i = 1; i < n; i++) {
      f[i] += f[i - 1];
    }
    for (auto e : f) {
      cout << e << " ";
    }
    cout << "\n";
    for (int i = 1; i < n; i++) {
      f[i] += f[i - 1];
    }
    for (auto e : f) {
      cout << e << " ";
    }
    cout << "\n";
    for (int i = 0; i < nq; i++) {
      int l = q[i][0], r = q[i][1];
      ans.push_back(f[r] - f[l - 1]);
    }
    return ans;
  }
};

//{ Driver Code Starts.

int main() {
  int t;
  scanf("%d ", &t);
  while (t--) {

    int n;
    scanf("%d", &n);

    vector<vector<int>> price(n, vector<int>(2, 0));
    for (int i = 0; i < n; i++) {
      cin >> price[i][0] >> price[i][1];
    }
    int k;
    cin >> k;
    int q;
    scanf("%d", &q);

    vector<vector<int>> queries(q, vector<int>(2, 0));
    for (int i = 0; i < q; i++) {
      cin >> queries[i][0] >> queries[i][1];
    }

    Solution obj;
    vector<int> res = obj.bestPrice(n, price, k, q, queries);
    for (int i : res)
      cout << i << " ";
    cout << endl;
  }
}

// } Driver Code Ends