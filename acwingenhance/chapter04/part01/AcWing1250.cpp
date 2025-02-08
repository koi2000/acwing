//
// Created by DELL on 2025/1/31.
//
#include <bits/stdc++.h>

using namespace std;
const int MAXN = 2e2 + 10;
typedef pair<int, int> pii;
pii father[MAXN][MAXN];
int n, m;

pii find(pii k) {
  if (k == father[k.first][k.second]) {
    return k;
  } else {
    father[k.first][k.second] = find(father[k.first][k.second]);
    return father[k.first][k.second];
  }
}

void merge(pii x, pii y) {
  pii fx = find(x);
  pii fy = find(y);
  father[fx.first][fx.second] = fy;
}

pii k1, k2;
int main() {
  ios::sync_with_stdio(0);
  cin >> n >> m;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      father[i][j].first = i;
      father[i][j].second = j;
    }
  }
  for (int i = 1; i <= m; i++) {
    char s;
    int x, y;
    cin >> x >> y >> s;
    if (s == 'D') {
      k1 = find(father[x][y]);
      k2 = find(father[x + 1][y]);
    } else {
      k1 = find(father[x][y]);
      k2 = find(father[x][y + 1]);
    }
    if (k1.first == k2.first && k1.second == k2.second) {
      cout << i;
      return 0;
    } else {
      merge(k1, k2);
    }
  }
  cout << "draw";
  return 0;
}