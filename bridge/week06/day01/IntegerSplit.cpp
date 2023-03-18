//#include<bits/stdc++.h>
//
//#define ll long long
//#define pii pair<int,int>
//using namespace std;
//
//int main() {
//    ios::sync_with_stdio(false);
//    int n;
//    cin >> n;
//    int tp = n;
//    int num = 0;
//    while (tp) {
//        tp >>= 1;
//        num++;
//    }
//    int dp[num + 1][n + 1];
//    memset(dp, 0, sizeof dp);
//    dp[0][0] = dp[0][1] = 1;
//    for (int i = 1; i <= num; i++) {
//        for (int j = n; j >= 0; --j) {
//            dp[i][j] = dp[i - 1][j];
//            if (pow(2, i) <= j) {
//                //dp[i][j] += max(dp[i - 1][j], dp[i - 1][j - (int) pow(2, i)] + 1);
//                dp[i][j] += dp[i - 1][j - (int) pow(2, i)];
//            }
//        }
//    }
//    cout << dp[num][n];
//    return 0;
//}
#include<bits/stdc++.h>

#define ll long long
#define pii pair<int,int>
using namespace std;
const int mod = 1e9;

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int dp[n + 1];
    memset(dp, 0, sizeof dp);
    dp[0] = 1;
    for (int i = 1; i <= n; i *= 2) {
        for (int j = i; j <= n; ++j) {
            dp[j] = (dp[j] + dp[j - i]) % mod;
        }
    }
    cout << dp[n];
    return 0;
}
