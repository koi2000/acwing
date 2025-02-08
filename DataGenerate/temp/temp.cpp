//
// Created by DELL on 2023/10/31.
//
#include "bits/stdc++.h"
using namespace std;

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    double res = (3 * i * i + 4 * i + 5.0) / (7 * i + 13.0);
    printf("%.5f ", res);
  }
  return 0;
}