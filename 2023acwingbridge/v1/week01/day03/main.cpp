#include "bits/stdc++.h"

#define ll long long
using namespace std;
const int maxn = 1e6 + 10;

string s;
int n;

bool check(int mid) {
    unordered_set<string> st;
    for (int i = 0; i < n - mid + 1; ++i) {
        string str = s.substr(i,mid);
        if (st.count(str))return false;
        st.insert(str);
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);

    cin >> n;
    cin >> s;
    int l = 1;
    int r = s.size();
    int ans = 0;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid)) {
            r = mid - 1;
            ans = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << ans << endl;
    return 0;
}


