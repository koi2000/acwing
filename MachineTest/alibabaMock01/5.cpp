//
// Created by DELL on 2023/4/14.
//
#include<bits/stdc++.h>

#define ll long long
#define pii pair<int,int>
using namespace std;
int n;
pii arr[200010];

bool cmp(pii &p1, pii &p2) {
    return abs(p1.first - p1.second) < abs(p2.first - p2.second);
}

int main() {
//    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i].first >> arr[i].second;
    }
    sort(arr, arr + n, cmp);
    int maxX = arr[0].first;
    int maxY = arr[0].second;
    double ans = 0;
    for (int i = 1; i < n; ++i) {
        int cur;
        if (arr[i].first > arr[i].second) {
            cur = arr[i].second + maxY;
        } else {
            cur = arr[i].first + maxX;
        }
        if (cur > ans)ans = cur;
        maxX = max(arr[i].first, maxX);
        maxY = max(arr[i].second, maxY);
    }
    printf("%.1f", ans / 2);
//    cout << ans / 2 << endl;
    return 0;
}


