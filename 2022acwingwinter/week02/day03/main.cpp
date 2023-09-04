#include<bits/stdc++.h>

#define ll long long
using namespace std;
const int N = 2e5 + 10;

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first) {
        return a.second < b.second;
    }
    return a.first < b.first;
}

int convert(int a) {
    int aa = 0;
    while (a) {
        aa += (a % 10);
        a /= 10;
    }
    return aa;
}


int main() {
    ll n, m;
    cin >> n >> m;
    pair<int, int> arr[n];
    for (int i = 1; i <= n; i++) {
        arr[i - 1].first = convert(i);
        arr[i - 1].second = i;
    }
    sort(arr, arr + n, cmp);
    cout << arr[m - 1].second;
    return 0;
}
//999999
//863362