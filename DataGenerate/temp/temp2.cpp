//
// Created by DELL on 2023/10/31.
//
#include "stdio.h"
#include <math.h>
int main() {
  int n;
  scanf("%d", &n);
  if (n < -2) {
    printf("%d", 2 * n - 1);
  }
  if (-2 <= n && n < 0) {
    printf("%d", n*n);
  }
  if (n >= 0) {
    printf("%d", (int)sqrt(n));
  }
  return 0;
}