#include <iostream>
using namespace std;
const int N = 20010;
int n,m;
int f[N];
int main () {
  cin >> m >> n;
  for (int i = 1;i <= n;i++) {
    int x;
    cin >> x;
    for (int j = m;j >= x;j--) f[j] = max (f[j],f[j - x] + x);
  }
  cout << m - f[m] << endl;
  return 0;
}