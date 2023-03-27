//
// Created by csp on 2023/3/19.
//
#include"bits/stdc++.h"

#define ll long long
#define pii pair<int,int>
using namespace std;
vector<pii > area;
int n, m, k;

bool check(int d) {
    int tpm = m;
    for (int i = 0; i < area.size(); ++i) {
        if (area[i].first > d) {
            tpm -= (area[i].first - d) * area[i].second;
        }
        if (tpm < 0)return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);

    cin >> n >> m >> k;
    int r = -1;
    for (int i = 0; i < n; ++i) {
        int t, c;
        cin >> t >> c;
        area.push_back({t, c});
        r = max(r, t);
    }
    r += 1;
    int l = k - 1;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    cout << r << endl;
    return 0;
}
