#include<bits/stdc++.h>

#define ll long long
#define pii pair<int,int>
using namespace std;

int n, k;

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> k;
        if (k % 3 == 0) {
            n %= (k + 1);
            if (n == k) {
                cout << "Alice" << endl;
                continue;
            }
        }
        if (n % 3 == 0) {
            cout << "Bob" << endl;
        } else {
            cout << "Alice" << endl;
        }

    }
    return 0;
}
