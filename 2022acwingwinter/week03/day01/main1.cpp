#include<bits/stdc++.h>

#define ll long long
using namespace std;
const int N = 2e5 + 10;

ll topdiv(ll a, ll b) {
    if (a % b == 0) {
        return a / b;
    } else {
        return a / b + 1;
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> q;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        q.push({a, b});
    }
    int res = 0;
    while (m--) {
        pair<int, int> tp = q.top();
        if (tp.first >= 0) {
            res += tp.first;
            tp.first -= tp.second;
            q.pop();
            q.push(tp);
        }else{
            break;
        }
    }
    cout << res << endl;
    return 0;
}