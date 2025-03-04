#include <algorithm>
#include <iostream>

#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;

const int N = 50010;

int n;
int f[N];
PII p[N];

int main() {
  // input
  cin >> n;
  for (int i = 1; i <= n; ++i)
    cin >> p[i].x >> p[i].y;
  // sort
  sort(p + 1, p + n + 1);
  // dp
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < i; ++j) {
      if (p[j].y < p[i].y)
        f[i] = max(f[i], f[j] + 1);
    }
  }
  // find result
  int res = 0;
  for (int i = 1; i <= n; ++i)
    res = max(res, f[i]);
  // output
  cout << res << endl;
  return 0;
}
