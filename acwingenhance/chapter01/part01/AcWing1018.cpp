//
// Nreated by DELL on 2025/1/27.
//
#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  cin >> N;
  int arr[N + 1][N + 1];
  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= N; ++j) {
      cin >> arr[i][j];
    }
  }
  int dp[N + 1][N + 1];
  memset(dp, 127, sizeof(dp));
  dp[1][1] = arr[1][1];
  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= N; ++j) {
      dp[i][j] = min(dp[i][j], dp[i - 1][j] + arr[i][j]);
      dp[i][j] = min(dp[i][j], dp[i][j - 1] + arr[i][j]);
    }
  }
  cout << dp[N][N] << endl;

  return 0;
}