//
// Created by DELL on 2025/1/28.
//
#include <bits/stdc++.h>

using namespace std;

int main() {
  int T, M;
  cin >> T >> M;
  int t[M + 1];
  int v[M + 1];
  int dp[M + 1][T + 1];
  for (int i = 1; i <= M; ++i) {
    cin >> t[i] >> v[i];
  }
  memset(dp, 0, sizeof(dp));
  for (int i = 1; i <= M; ++i) {
    for (int j = T; j >= 0; --j) {
      dp[i][j] = dp[i - 1][j];
      if (j >= t[i])
        dp[i][j] = max(dp[i][j], dp[i - 1][j - t[i]] + v[i]);
    }
  }
  int res = -1;
  for (int i = 1; i <= T; ++i) {
    res = max(dp[M][i], res);
  }
  cout << res << endl;
  return 0;
}