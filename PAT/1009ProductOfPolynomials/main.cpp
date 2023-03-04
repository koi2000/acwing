#include "bits/stdc++.h"

#define ll long long
using namespace std;

int main() {
//    ios::sync_with_stdio(false);
    int n;
    map<int, double> mp1;
    map<int, double> mp2;
    map<int, double> res;
    cin >> n;
    int a;
    double b;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        mp1[a] = b;
    }
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        mp2[a] = b;
    }
    for (auto it1:mp1) {

        for (auto it2:mp2) {
            int key = it1.first + it2.first;
            if (res.count(key)) {
                res[key] += it1.second * it2.second;
            } else {
                res[key] = it1.second * it2.second;
            }
        }
    }
    for (auto it = res.begin(); it != res.end();) {
        if (fabs(it->second) <= 1e-7) {
            res.erase(it++);
        } else {
            it++;
        }
    }
    cout << res.size();
    for (auto i = res.rbegin(); i != res.rend(); ++i) {
        printf(" %d %.1f", i->first, i->second);
    }
    return 0;
}
