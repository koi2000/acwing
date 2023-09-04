#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 10;

int n;
double ave, sq, a[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i], ave += a[i];
    }
    ave /= n;
    for (int i = 1; i <= n; i++) {
        sq += (a[i] - ave) * (a[i] - ave);
    }
    sq /= n;
    for (int i = 1; i <= n; i++) {
        printf("%lf\n", (a[i] - ave) / sqrt(sq));
    }
    return 0;
}