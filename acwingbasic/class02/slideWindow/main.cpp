//
// Created by DELL on 2022/6/7.
//
#include <bits/stdc++.h>
#define ll long long
using namespace std;

class num {
public:
    ll val;
    ll pos;

    num(ll val, ll pos) : val(val), pos(pos) {}

    num() {}
};

ll n, k;
deque<num> minw;
deque<num> maxw;
vector<ll> resn;
vector<ll> resx;
vector<ll> arr;

void windowMax() {
    for (ll i = 0; i < k - 1; ++i) {
        while (!maxw.empty() && maxw.back().val <= arr[i]) {
            maxw.pop_back();
        }
        maxw.emplace_back(arr[i], i);
    }
    for (ll i = k - 1; i < arr.size(); ++i) {
        while (!maxw.empty() && maxw.back().val <= arr[i]) {
            maxw.pop_back();
        }
        while (!maxw.empty() && maxw.front().pos < i - k + 1) {
            maxw.pop_front();
        }
        maxw.emplace_back(arr[i], i);
        resx.push_back(maxw.front().val);
    }
}

void windowMin() {
    for (ll i = 0; i < k - 1; ++i) {
        while (!minw.empty() && minw.back().val >= arr[i]) {
            minw.pop_back();
        }
        minw.emplace_back(arr[i], i);
    }
    for (ll i = k - 1; i < arr.size(); ++i) {
        while (!minw.empty() && minw.back().val >= arr[i]) {
            minw.pop_back();
        }
        while (!minw.empty() && minw.front().pos < i - k + 1) {
            minw.pop_front();
        }
        minw.emplace_back(arr[i], i);
        resn.push_back(minw.front().val);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;

    ll tp;
    for (ll i = 0; i < n; ++i) {
        cin >> tp;
        arr.push_back(tp);
    }
    windowMax();
    windowMin();

    for (ll i = 0; i < resx.size(); ++i) {
        cout << resn[i] << " ";
    }
    cout << "\n";
    for (ll i = 0; i < resx.size(); ++i) {
        cout << resx[i] << " ";
    }
    return 0;
}