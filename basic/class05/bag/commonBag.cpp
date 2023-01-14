////
//// Created by DELL on 2023/1/14.
////
//#include "bits/stdc++.h"
//
//#define ll long long
//using namespace std;
//
//int N, V;
//
//int main() {
//    ios::sync_with_stdio(false);
//    cin >> N >> V;
//    int dp[N + 1][V + 1];
//    int v[N + 1];
//    int w[N + 1];
//    memset(dp,0,sizeof dp);
//    memset(v,0,sizeof v);
//    memset(w,0,sizeof w);
//    for (int i = 1; i <= N; ++i) {
//        int a, b;
//        cin >> a >> b;
//        v[i] = a;
//        w[i] = b;
//    }
//    for (int i = 1; i <= N; ++i) {
//        for (int j = V; j >= 0; --j) {
//            dp[i][j] = dp[i - 1][j];
//            if (v[i] <= j) {
//                dp[i][j] = max(dp[i][j], dp[i - 1][j - v[i]] + w[i]);
//            }
//        }
//    }
//    cout << dp[N][V] << endl;
//    return 0;
//}
//
//
// Created by DELL on 2023/1/14.
//
#include "bits/stdc++.h"

#define ll long long
using namespace std;

int N, V;

int main() {
    ios::sync_with_stdio(false);
    cin >> N >> V;
    int dp[V + 1];
    int v[N + 1];
    int w[N + 1];
    memset(dp, 0, sizeof dp);
    memset(v, 0, sizeof v);
    memset(w, 0, sizeof w);
    for (int i = 1; i <= N; ++i) {
        int a, b;
        cin >> a >> b;
        v[i] = a;
        w[i] = b;
    }
    for (int i = 1; i <= N; ++i) {
        for (int j = V; j >= v[i]; --j) {

            dp[j] = max(dp[j], dp[j - v[i]] + w[i]);

        }
    }
    cout << dp[V] << endl;
    return 0;
}

