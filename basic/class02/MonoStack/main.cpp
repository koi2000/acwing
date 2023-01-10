#include "bits/stdc++.h"

#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    stack<int> stk;

    for (int i = 0; i < n; ++i) {
        int tp;
        cin >> tp;
        while (!stk.empty() && stk.top() >= tp) {
            stk.pop();
        }
        if (stk.empty()) {
            cout << -1 << " ";
        } else {
            cout << stk.top() << " ";
        }
        stk.push(tp);
    }
    return 0;
}
