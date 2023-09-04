//#include "bits/stdc++.h"
//
//#define ll long long
//using namespace std;
//
//int main() {
//    ios::sync_with_stdio(false);
//    int n;
//    cin >> n;
//    int arr[n+1];
//    for (int i = 1; i <= n; ++i) {
//        cin >> arr[i];
//    }
//    int dp[n + 1];
//    int g[n+1];
//    for (int i = 1; i <= n; ++i) {
//        dp[i] = 1;
//        for (int j = 1; j < i; ++j) {
//            if (arr[i] > arr[j]) {
//                dp[i] = max(dp[i], dp[j] + 1);
//            }
//        }
//    }
//    int res = 0;
//    for (int i = 1; i <= n; ++i) {
//        res = max(res, dp[i]);
//    }
//    cout<<res<<endl;
//    return 0;
//}
#include "bits/stdc++.h"

#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int arr[n + 1];
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }
    int dp[n + 1];
    memset(dp, 0, sizeof dp);
    int g[n + 1];
    for (int i = 1; i <= n; ++i) {
        dp[i] = 1;
        g[i] = 0;
        for (int j = 1; j < i; ++j) {
            if (arr[j] < arr[i]) {
                if (dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    g[i] = j;
                }
            }
        }
    }
    int k = 1;
    for (int i = 1; i <= n; ++i) {
        if (dp[k] < dp[i]) {
            k = i;
        }
    }
    cout << dp[k] << endl;
    return 0;
}
