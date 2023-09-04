#include "bits/stdc++.h"

#define ll long long
using namespace std;
const int maxn = 1e6 + 10;

int get(string s, int b) {
    int num = 0;
    int n = s.size();
    for (int i = n - 1; i >= 0; --i) {
        num += (s[n - i - 1] - '0') * pow(b, i);
    }
    return num;
}

int main() {
    ios::sync_with_stdio(false);
    string bts;
    string tts;
    cin >> bts >> tts;
    unordered_set<int> st;
    for (auto &c:bts) {
        c ^= 1;
        st.insert(get(bts, 2));
        c ^= 1;
    }
    for (auto &c:tts) {
        char t = c;
        for (int i = 0; i < 3; ++i) {
            if (i + '0' != t) {
                c = i + '0';
                int x = get(tts, 3);
                if (st.count(x)) {
                    cout << x << endl;
                    return 0;
                }
            }
        }
        c = t;
    }
    return 0;
}
