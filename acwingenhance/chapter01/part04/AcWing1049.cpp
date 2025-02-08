//
// Created by DELL on 2025/1/29.
//
#include <bits/stdc++.h>

using namespace std;

int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    int money[n + 1];
    for (int i = 1; i <= n; ++i) {
      cin >> money[i];
    }
    int dp[n + 1][2];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; ++i) {
      dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
      dp[i][1] = max(money[i], dp[i - 1][0] + money[i]);
    }
    cout << max(dp[n][0], dp[n][1]) << endl;
  }
  return 0;
}