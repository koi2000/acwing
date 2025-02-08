//
// Created by DELL on 2025/1/27.
//
#include <bits/stdc++.h>

using namespace std;

int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    int arr[n + 1];
    for (int i = 1; i <= n; ++i) {
      cin >> arr[i];
    }
    int dp[n + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; ++i) {
      dp[i] = 1;
      for (int j = 1; j <= i; ++j) {
        if (arr[i] < arr[j]) {
          dp[i] = max(dp[i], dp[j] + 1);
        }
      }
    }
    int maxx1 = -1;
    for (int i = 1; i <= n; ++i) {
      maxx1 = max(maxx1, dp[i]);
    }
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; ++i) {
      dp[i] = 1;
      for (int j = 1; j <= i; ++j) {
        if (arr[i] > arr[j]) {
          dp[i] = max(dp[i], dp[j] + 1);
        }
      }
    }
    for (int i = 1; i <= n; ++i) {
      maxx1 = max(maxx1, dp[i]);
    }
    cout << maxx1 << endl;
  }
  return 0;
}