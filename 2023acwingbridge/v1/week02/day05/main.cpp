#include "bits/stdc++.h"

#define ll long long
using namespace std;
const int N = 1e6 + 10;

char str[N];
int nxt[N];
int n;

void get_next() {
    for (int i = 2, j = 0; i <= n; ++i) {
        while (j && str[i] != str[j + 1]) {
            j = nxt[j];
        }
        if (str[i] == str[j + 1]) {
            j++;
        }
        nxt[i] = j;
    }
}

int main() {
    ios::sync_with_stdio(false);

    int idx = 0;
    while (cin >> n) {
        idx++;
        if (n == 0) break;
        cin >> str + 1;
        get_next();

        cout << "Test case #" << idx << endl;
        for (int i = 2; i <= n; ++i) {
            int t = i - nxt[i];
            if (t != i && i % t == 0) {
                cout << i << " " << i / t << endl;
            }
        }
        cout<<"\n";
    }
    return 0;
}
