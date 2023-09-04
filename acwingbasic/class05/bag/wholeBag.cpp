////
//// Created by DELL on 2023/1/14.
////
//#include "bits/stdc++.h"
//
//#define ll long long
//using namespace std;
//const int maxn = 1010;
//int N, V;
//int dp[maxn][maxn];
//int v[maxn];
//int w[maxn];
//
//int main() {
////    ios::sync_with_stdio(false);
////    cin >> N >> V;
//    scanf("%d%d", &N, &V);
//    for (int i = 1; i <= N; ++i) {
//        int a, b;
//        scanf("%d%d", &a, &b);
////        cin >> a >> b;
//        v[i] = a;
//        w[i] = b;
//    }
//    for (int i = 1; i <= N; ++i) {
//        for (int j = 0; j <= V; j++) {
//            for (int k = 0; k * v[i] <= j; ++k) {
//                dp[i][j] = max(dp[i][j], dp[i - 1][j - k * v[i]] + k * w[i]);
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
const int maxn = 1010;
int N, V;
int dp[maxn][maxn];
int v[maxn];
int w[maxn];

int main() {
//    ios::sync_with_stdio(false);
//    cin >> N >> V;
    scanf("%d%d", &N, &V);
    for (int i = 1; i <= N; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
//        cin >> a >> b;
        v[i] = a;
        w[i] = b;
    }
    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j <= V; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j >= v[i]) {
                dp[i][j] = max(dp[i][j], dp[i][j - v[i]] + w[i]);
            }
        }
    }
    cout << dp[N][V] << endl;
    return 0;
}

