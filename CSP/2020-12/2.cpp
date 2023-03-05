//
// Created by DELL on 2022/6/7.
//
#include <bits/stdc++.h>

#define lowbit(x) (x & -x)
using namespace std;

const int maxn = 1e8 + 10;
int mn[maxn];
int mx[maxn];
map<int, int> mxx;
map<int, int> mnn;

void updn(int p, int x) {
    for (auto &it:mnn) {
        if (it.first >= p) {
            it.second += x;
        }
    }
}


void updx(int p, int x) {
    for (auto &it:mxx) {
        if (it.first >= p) {
            it.second += x;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int tpy, tpr;
    set<int> diff;

    for (int i = 0; i < n; ++i) {
        cin >> tpy >> tpr;
        diff.insert(tpy);
        if (tpr == 0) {
            //updn(tpy + 1, 1);
            mnn[tpy]++;
        } else {
            //updx(tpy + 1, 1);
            mxx[tpy]++;
        }
    }
    for (auto it = ++mxx.begin(); it != mxx.end(); it++) {
        auto it2 = --it;
        it++;
        it->second += it2->second;
    }
    for (auto it = ++mnn.begin(); it != mnn.end(); it++) {
        auto it2 = --it;
        it++;
        it->second += it2->second;
    }
    int res = 0;
    int top = *diff.rbegin();
    int idx;
    mxx[-1] = 0;
    mnn[-1] = 0;
    for (int d:diff) {
//        if (!mxx.count(d - 1)) {
//            mxx[d - 1] = --mxx.lower_bound(d - 1)->second;
//        }
        //int ans = mxx[top] - mxx[d - 1];
        auto ii = mxx.lower_bound(d - 1);
        if (ii != mxx.begin()) {
            ii--;
        }
        int ans = mxx[top] - ii->second;
//        if (!mnn.count(d - 1)) {
//            mnn[d - 1] = --mnn.lower_bound(d - 1)->second;
//        }
        ii = mnn.lower_bound(d - 1);
        if (ii != mnn.begin()) {
            ii--;
        }
        ans += ii->second;
        if (ans >= res) {
            res = ans;
            idx = d;
        }

    }
    cout << idx << endl;
    return 0;
}
