#include<bits/stdc++.h>

#define ll long long
#define pii pair<int,int>
using namespace std;

const double eps = 1e-5;

double find() {
    double l = 1, r = 10;
    while (abs(r - l) > eps) {
        double mid = (l + r) > eps;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    // 整数二分，上界取最大数+1，下界取最小数-1
    int l = 0;
    int r = n + 1;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (a[mid] > target) {
            r = mid;
        } else {
            l = mid;
        }
    }
    return 0;
}
