//
// Created by DELL on 2023/1/13.
//
#include "bits/stdc++.h"

#define ll long long
using namespace std;
const int N = 1000010;
int primes[N], cnt;
bool vis[N];

void get_primes1(int n) {
    for (int i = 2; i <= n; ++i) {
        if (vis[i])continue;
        primes[cnt++] = i;
        for (int j = i + i; j <= n; j += i) {
            vis[j] = true;
        }
    }
}

void get_primes2(int n) {
    for (int i = 2; i <= n; ++i) {
        if (!vis[i]) primes[cnt++] = i;
        for (int j = 0; primes[j] <= n / i; j++) {
            vis[primes[j] * i] = true;
            if (i % primes[j] == 0)break;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    get_primes1(n);
    cout << cnt;
    return 0;
}

