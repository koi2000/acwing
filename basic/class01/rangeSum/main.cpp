#include "bits/stdc++.h"

#define ll long long
using namespace std;
#define lowbit(x) (x&-x)
const int N = 1e6 + 10;
typedef pair<int, int> ptt;

int n, m;
int a[N], s[N];

vector<int> all;
vector<ptt> add, query;

int find(int x) {
    int l = 0, r = all.size() - 1;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (all[mid] >= x) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return r + 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        int x, c;
        cin >> x >> c;
        add.push_back({x, c});
        all.push_back(x);
    }
    for (int i = 0; i < m; ++i) {
        int l, r;
        cin >> l >> r;
        query.push_back({l, r});
        all.push_back(l);
        all.push_back(r);
    }
    sort(all.begin(), all.end());
    all.erase(unique(all.begin(), all.end()), all.end());
    for (auto item: add) {
        int x = find(item.first);
        a[x] += item.second;
    }
    for (int i = 1; i <= all.size(); i++) {
        s[i] = s[i - 1] + a[i];
    }
    for (auto item: query) {
        int l = find(item.first), r = find(item.second);
        cout << s[r] - s[l - 1] << endl;
    }
    return 0;
}
