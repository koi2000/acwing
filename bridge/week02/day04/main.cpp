#include "bits/stdc++.h"

#define ll long long
using namespace std;
const int N = 1e6 + 10;


int n;
ll m;
int a[N], q[N];
ll f[N];

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        if (a[i] > m) {
            cout << -1 << endl;
            return 0;
        }
    }
    int hh = 0;
    int tt = 0;
    int sum = 0;
    for (int i = 1,j =0; i <= n; ++i) {
        sum += a[i];
        while (sum > m) {
            sum-=a[++j];
        }
        while (hh<=tt&&q[hh]<j){
            hh++;
        }
        while (a[q[tt]]<=a[i]){
            tt--;
        }
    }
    return 0;
}
