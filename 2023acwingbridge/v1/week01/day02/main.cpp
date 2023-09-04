#include "bits/stdc++.h"

#define ll long long
using namespace std;
const int maxn = 1e6 + 10;

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    vector<int> arr;
    int num = 0;
    while (T--) {
        int n;
        cin >> n;
        int a[n + 1];
        memset(a, 0, sizeof a);
        int flag = 0;
        for (int i = 1; i <= n; ++i) {
            int tp;
            cin >> tp;
            tp = min(tp, i);
            int l = i - tp + 1;
            int r = i;
            a[l]++;
            a[r + 1]--;
        }
        for (int i = 1; i <= n; ++i) {
            a[i] += a[i - 1];
        }
        for (int i = 1; i <= n; ++i) {
            cout << (a[i] >= 1) << " ";
        }
        cout << "\n";
    }
    return 0;
}
