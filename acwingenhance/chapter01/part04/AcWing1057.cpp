//
// Created by DELL on 2025/1/29.
//
#include <cstring>
#include <iostream>

using namespace std;

const int N = 1e5 + 10, M = 110;

int n, k;
int w[N];
int f[N][M][2];

int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; ++i)
    cin >> w[i];

  memset(f, -0x3f, sizeof f);
  f[0][0][0] = 0; //初始状态f[0][0][0]

  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= k; ++j) {
      f[i][j][0] = f[i - 1][j][0];
      if (j > 0)
        f[i][j][0] = max(f[i][j][0], f[i - 1][j - 1][1] + w[i]);
      f[i][j][1] = max(f[i - 1][j][1], f[i - 1][j][0] - w[i]);
    }
  }

  int res = 0;
  for (int j = 0; j <= k; ++j)
    res = max(res, f[n][j][0]);

  cout << res << endl;

  return 0;
}
