//
// Created by DELL on 2025/1/27.
//
#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  while (T--) {
    int R, C;
    cin >> R >> C;
    int arr[R + 1][C + 1];
    for (int i = 1; i <= R; ++i) {
      for (int j = 1; j <= C; ++j) {
        cin >> arr[i][j];
      }
    }
    int dp[R + 1][C + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= R; ++i) {
      for (int j = 1; j <= C; ++j) {
        dp[i][j] = max(dp[i - 1][j] + arr[i][j], dp[i][j - 1] + arr[i][j]);
      }
    }
    cout << dp[R][C] << endl;
  }
  return 0;
}