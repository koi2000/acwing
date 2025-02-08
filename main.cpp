#include <stdio.h>
#include <stdlib.h>
int main() {
  int n, a, b;
  scanf("%d", &n);
  int x[n + 1];
  long long m;

  scanf("%d", &x[0]);
  scanf("%d %d", &a, &b);
  scanf("%lld", &m);
  for (int i = 1; i <= n; i++) {
    x[i] = (a * x[i-1] + b) % m;
    printf("%d ", x[i]);
  }
  return 0;
}