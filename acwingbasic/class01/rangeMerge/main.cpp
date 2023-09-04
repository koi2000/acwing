#include "bits/stdc++.h"

#define ll long long
using namespace std;
typedef pair<int, int> pii;
const int N = 1e+10;
vector<pii> segs;
int n;

void merge(vector<pii> &segs) {
    vector<pii> res;
    sort(segs.begin(), segs.end());
    int st = -2e9, ed = -2e9;
    for (auto seg: segs) {
        if (ed < seg.first) {
            if (st != -2e9) {
                res.push_back({st, ed});
            }
            st = seg.first, ed = seg.second;
        } else {
            ed = max(ed, seg.second);
        }
    }
    if (st != -2e9) {
        res.push_back({st,ed});
    }
    segs = res;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int l, r;
        cin >> l >> r;
        segs.push_back({l, r});
    }
    merge(segs);
    cout << segs.size() << endl;
    return 0;
}
