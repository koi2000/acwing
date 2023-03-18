//#include<bits/stdc++.h>
//
//#define ll long long
//#define pii pair<int,int>
//using namespace std;
//const int N = 1010;
//int dp[N][N];
//
//int main() {
//    ios::sync_with_stdio(false);
//    int n, v;
//    cin >> n >> v;
//    int vs[n + 1];
//    int ws[n + 1];
//    for (int i = 1; i <= n; ++i) {
//        cin >> vs[i] >> ws[i];
//    }
//    for (int i = 1; i <= n; ++i) {
//        for (int j = v; j >= 0; --j) {
//            dp[i][j] = dp[i - 1][j];
//            for (int k = 0; k * vs[i] <= j; ++k) {
//                dp[i][j] = max(dp[i][j], dp[i - 1][j - k * vs[i]] + k * ws[i]);
//            }
//        }
//    }
//    cout << dp[n][v];
//    return 0;
//}
#include<bits/stdc++.h>

#define ll long long
#define pii pair<int,int>
using namespace std;
const int N = 1010;
int dp[N];

int main() {
    ios::sync_with_stdio(false);
    int n, v;
    cin >> n >> v;
    int vs[n + 1];
    int ws[n + 1];
    for (int i = 1; i <= n; ++i) {
        cin >> vs[i] >> ws[i];
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = vs[i]; j <= v; j++) {
            dp[j] = max(dp[j], dp[j - vs[i]] + ws[i]);
        }
    }
    cout << dp[v];
    return 0;
}