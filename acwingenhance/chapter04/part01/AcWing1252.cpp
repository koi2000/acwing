#include <iostream>
using namespace std;
const int N = 10010;
int n, k, m;
int p[N];
int w[N], v[N];
int dp[N];
int find(int x) {
  if (p[x] != x)
    p[x] = find(p[x]);
  return p[x];
}
int main() {
  cin >> n >> k >> m;
  for (int i = 1; i <= n; i++) {
    p[i] = i;
    cin >> w[i] >> v[i];
  }
  while (k--) {
    int a, b;
    cin >> a >> b;
    a = find(a), b = find(b);
    if (a != b)
      p[a] = b;
  }
  for (int i = 1; i <= n; i++) {
    if (p[i] == i)
      continue;
    int x = find(i);
    w[x] += w[i];
    v[x] += v[i];
  }
  for (int i = 1; i <= n; i++) {
    if (p[i] != i)
      continue;
    for (int j = m; j >= w[i]; j--) {
      dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
    }
  }
  cout << dp[m] << endl;
  return 0;
}