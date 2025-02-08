#include<iostream>
#include<cstring>
using namespace std;

const int N = 15;

int n, r, c, num;
int f[N + N][N][N], w[N][N];

int main() {
  cin >> n;
  while(cin >> r >> c >> num, r || c || num) {
    w[r][c] = num;
  }

  //k表示其中两条路径长度的总和
  for(int k = 2; k <= n + n; k++) {
    for(int i1 = 1; i1 <= n; i1++) {
      for(int i2 = 1; i2 <= n; i2++) {
        int j1 = k - i1, j2 = k - i2;
        if(j1 < 1 || j1 > n || j2 < 1 || j2 > n) continue;

        //要走的路径
        int t = w[i1][j1];
        if(i1 != i2) t += w[i2][j2];

        int& x = f[k][i1][i2];
        x = max(x, t + f[k - 1][i1 - 1][i2 - 1]);       //上一个状态的两条路径分别往下走一格
        x = max(x, t + f[k - 1][i1][i2 - 1]);
        x = max(x, t + f[k - 1][i1 - 1][i2]);
        x = max(x, t + f[k - 1][i1][i2]);
      }
    }
  }

  cout << f[n + n][n][n] << endl;

  return 0;
}