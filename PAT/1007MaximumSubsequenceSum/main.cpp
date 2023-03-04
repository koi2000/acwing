#include "bits/stdc++.h"

#define ll long long
using namespace std;
const int N = 10010;
int arr[N];

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }
    int dp[n + 1];
    memset(dp, -0x7f, sizeof dp);
    int l = 1, r = n;
    int flag = 0;
    for (int i = 1; i <= n; ++i) {
        if (!flag && dp[i - 1] > dp[i - 1] + arr[i] && dp[i - 1] > arr[i]) {
            flag = 1;
            dp[i] = dp[i - 1];
            continue;
        }
        if (flag) {
            if (dp[i - 1] < arr[i]) {
                r = i;
                l = i;
                flag = 0;
                dp[i] = arr[i];
            } else {
                dp[i] = dp[i - 1];
            }
        } else {
            if (dp[i - 1] + arr[i] > arr[i]) {
                r++;
                dp[i] = dp[i - 1] + arr[i];
            } else {
                l = i;
                r = i;
                dp[i] = arr[i];
            }
        }
    }
    if (dp[n] < 0) {
        cout << 0 << " " << arr[1] << " " << arr[n];
    }else{
        cout << dp[n] << " " << arr[l] << " " << arr[r];
    }
    return 0;
}
