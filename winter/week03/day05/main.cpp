#include<bits/stdc++.h>

#define ll long long
#define lowbit(x) (x&-x)
using namespace std;
const ll N = 1e5 + 10;

int main() {
    int w = 1189;
    int h = 594;
    string s;
    cin >> s;
    int n = s[1] - '0';
    while (n--) {
        if (w > h) {
            w /= 2;
        } else {
            h /= 2;
        }
    }
    cout << max(w, h) << " " << min(w, h) << endl;
    return 0;
}