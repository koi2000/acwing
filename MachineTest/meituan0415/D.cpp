#include<bits/stdc++.h>

#define ll long long
#define pii pair<int,int>
using namespace std;
const int N = 100010;
int a[N];
int b[N];
int c[N];
struct tpi {
    int id, a, b, c;
};
tpi tps[N];

bool cmp(tpi &x, tpi &y) {
    return x.a > y.a;
}

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        //tps[i].id = i;
        cin >> tps[i].a;
    }
    for (int i = 0; i < n; ++i) {
        cin >> tps[i].b;
    }
    for (int i = 0; i < n; ++i) {
        cin >> tps[i].c;
    }
    set<pii > b2tpi;
//    map<int, tpi> b2tpi;
    sort(tps, tps + n, cmp);
    for (int i = 0; i < n; ++i) {
        b2tpi.insert({tps[i].b, i});
    }
    set<int> st;
    int res = 0;
    for (int i = 0; i < n; ++i) {
        int tpa = tps[i].a;
        auto it = b2tpi.lower_bound({tpa, 0});
        if (it != b2tpi.end()) {
            st.insert(it->second);
            res += (it->first - tpa) * tps[it->second].c;
            b2tpi.erase(it);
        }
    }
    for (auto it:b2tpi) {
        res += tps[it.second].b * tps[it.second].c;
    }
    cout << res << endl;
    return 0;
}
