#include<bits/stdc++.h>

#define ll long long
#define pii pair<int,int>
using namespace std;
int n, x, y;
vector<int> arr;

bool check(int mid) {
    auto it = upper_bound(arr.begin(), arr.end(), mid);
    int low = it - arr.begin();
    int upp = arr.size() - low;
    if (low >= x && low <= y && upp >= x && upp <= y)return true;
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> x >> y;
    int r = -1;
    for (int i = 0; i < n; i++) {
        int tp;
        cin >> tp;
        arr.push_back(tp);
        r = max(r, tp);
    }
    sort(arr.begin(), arr.end());
    r++;
    int mx = r;
    int l = 0;
//    while (r - l > 1) {
//        int mid = (l + r) / 2;
//        if (check(mid)) {
//            r = mid;
//        } else {
//            l = mid;
//        }
//    }
    for (int i = 0; i < r; ++i) {
        if (check(i)) {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
//    if (r == mx) {
//        cout << -1 << endl;
//    } else {
//        cout << r << endl;
//    }
    return 0;
}
