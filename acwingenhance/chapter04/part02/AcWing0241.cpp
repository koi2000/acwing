//
// Created by DELL on 2025/1/31.
//
#include <bits/stdc++.h>

using namespace std;

const int N = 2e6 + 10;

typedef long long ll;

int n;
int a[N], p[N];
int lr[N], gr[N];
int lowbit(int x) { return x & -x; }

void add(int x, int k) {
  for (int i = x; i <= n; i += lowbit(i)) {
    p[i] += k;
  }
}

int ask(int x) {
  int sum = 0;
  for (int i = x; i; i -= lowbit(i)) {
    sum += p[i];
  }
  return sum;
}

int main() {
  ios::sync_with_stdio(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    int y = a[i];
    lr[i] = ask(y - 1);
    gr[i] = ask(n) - ask(y);

    add(y, 1);
  }

  memset(p, 0, sizeof p);

  ll resA = 0, resV = 0;
  for (int i = n; i >= 1; i--) {
    int y = a[i];
    resA += (ll)lr[i] * ask(y - 1);
    resV += (ll)gr[i] * (ask(n) - ask(y));

    add(y, 1);
  }

  printf("%lld %lld\n", resV, resA);
  return 0;
}