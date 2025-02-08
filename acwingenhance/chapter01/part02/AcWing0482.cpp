//
// Created by DELL on 2025/1/27.
//
#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  int a[n + 1];
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  int dp[n + 1][2];
  memset(dp, 0, sizeof(dp));
  for (int i = 1; i <= n; ++i) {
    dp[i][0] = 1;
    dp[i][1] = 1;
    for (int j = 1; j < i; ++j) {
      if (a[j] < a[i]) {
        dp[i][1] = max(dp[i][1], dp[j][1] + 1);
      }
      if (a[j] > a[i]) {
        dp[i][0] = max(dp[i][0], max(dp[j][0], dp[j][1]) + 1);
      }
    }
  }
  int res = 0;
  for (int i = 1; i <= n; ++i)
    res = max(res, max(dp[i][0], dp[i][1]));
  cout << n - res << endl;
  return 0;
}