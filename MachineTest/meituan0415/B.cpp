#include<bits/stdc++.h>

#define ll long long
#define pii pair<int,int>
using namespace std;

int n, a, b;

bool check(int x) {
    int num1 = a / x;
    int num2 = b / x;
    int num11 = a % x;
    int num22 = b % x;
    num2 += num22 / x;
    num1 += num11 / x;
    return num1 + num2 >= n;
}

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> a >> b;
        int l = 0;
        int r = a + b;
        while (r - l > 1) {
            int mid = (l + r) >> 1;
            if (check(mid)) {
                l = mid;
            } else {
                r = mid;
            }
        }
        cout << l << endl;
    }
    return 0;
}
