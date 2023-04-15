#include<bits/stdc++.h>

#define ll long long
#define pii pair<int,int>
using namespace std;
int n, m, a;

int main() {
    ios::sync_with_stdio(false);
    int c;
    cin >> c;
    while (c--) {
        string s;
        string t;
        cin >> s;
        cin >> t;
        int sl = 0;
        int sr = 0;
        int tl = 0;
        int res = 0;
        res += max(0, (int) s.size() - (int) t.size());
        while (true) {
            if (t[tl] != s[sl]) {
                sl++;
                tl++;
                res++;
            } else if (t[tl] == s[sl]) {
                sl++;
                tl++;
            }
            if (sl == min(s.size(), t.size()))break;
        }
        cout << res << endl;
    }
    return 0;
}
