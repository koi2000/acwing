#include "bits/stdc++.h"

#define ll long long
using namespace std;
const int maxn = 1e6 + 10;

int n;

void update(char &c) {
    if (c == 'W')c = 'B';
    else c = 'W';
}

bool check(string s, char c) {
    vector<int> res;
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] != c) {
            update(s[i]);
            update(s[i + 1]);
            res.push_back(i);
        }
    }
    if (s.back() != c)return false;
    cout << res.size() << endl;
    for (int x: res) cout << x + 1 << ' ';
    if (res.size()) cout << endl;

    return true;
}


int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {

        cin >> n;
        string s;
        cin >> s;
        if (!check(s, 'W') && !check(s, 'B')) {
            cout << "-1" << endl;
        }
    }

    return 0;
}
