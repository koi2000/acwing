////
//// Created by DELL on 2023/4/14.
////
//#include<bits/stdc++.h>
//
//#define ll long long
//#define pii pair<int,int>
//using namespace std;
//
//int main() {
//    ios::sync_with_stdio(false);
//    int T;
//    cin >> T;
//    while (T--) {
//        int n;
//        cin >> n;
//        pii arr[n];
//        for (int i = 0; i < n; ++i) {
//            cin >> arr[i].first;
//        }
//        for (int i = 0; i < n; ++i) {
//            cin >> arr[i].second;
//        }
//        sort(arr, arr + n);
//        int dp[n + 1];
//        for (int i = 0; i < n; ++i) {
//            dp[i] = 1;
//            for (int j = 0; j < i; ++j) {
//                if (arr[i].first > arr[j].first&&arr[i].second > arr[j].second) {
//                    dp[i] = max(dp[i], dp[j] + 1);
//                }
//            }
//        }
//        cout << *max_element(dp, dp + n) << endl;
//    }
//    return 0;
//}
//
//
// Created by DELL on 2023/4/14.
//
#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 10;

struct node {
    int x, y;
} goods[maxn];

bool cmp(node a, node b) {
    if (a.x == b.x) return a.y > b.y;
    return a.x < b.x;
}


int lengthOfLIS(vector<int> &nums) {
    int len = 1, n = (int) nums.size();
    if (n == 0) {
        return 0;
    }
    vector<int> d(n + 1, 0);
    d[len] = nums[0];
    for (int i = 1; i < n; ++i) {
        if (nums[i] > d[len]) {
            d[++len] = nums[i];
        } else {
            int l = 1, r = len, pos = 0;
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (d[mid] < nums[i]) {
                    pos = mid;
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
            d[pos + 1] = nums[i];
        }
    }
    return len;
}

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> goods[i].x;
    }
    for (int i = 0; i < n; i++) {
        cin >> goods[i].y;
    }
    sort(goods, goods + n, cmp);
    vector<int> vec;
    for (int i = 0; i < n; i++) {
        vec.push_back(goods[i].y);
    }
    //for(int i = 0;i < vec.size();i++) cout<<vec[i]<<" ";cout<<endl;
    cout << lengthOfLIS(vec) << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}


