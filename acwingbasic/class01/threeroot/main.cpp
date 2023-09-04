//
// Created by Administrator on 2023年01月08日0008.
//
#include "bits/stdc++.h"

#define ll long long
using namespace std;
const int N = 1e5 + 10;

int arr[N];
int tmp[N];

int main() {
//    ios::sync_with_stdio(false);
    double n;
    cin >> n;
    double l = -10000;
    double r = 10000;
    while (r - l > 0.0000001) {
        double mid = (l + r) / 2;
        if (mid * mid * mid > n) {
            r = mid;
        } else if (mid * mid * mid < n) {
            l = mid;
        } else {
            break;
        }
    }
    printf("%.6f", l);
    return 0;
}