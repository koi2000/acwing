#include<bits/stdc++.h>
using namespace std;
const int ll = 1000000007;

//递推公式 f[i] = A * f[i - 1] - B * f[i - 2]
//f[i] = x ^ i + y ^ i
int helper(int A, int B, int n){
    vector<long> dp(3);
    dp[0] = 2;
    dp[1] = A;
    for(int i = 2; i <= n; i++){
        dp[2] = ((A * dp[1] % ll) - (B * dp[0] % ll) + ll) % ll;
        dp[0] = dp[1];
        dp[1] = dp[2];
    }
    return dp[2];
}

int main(){
    int count;
    cin >> count;
    while(count-- > 0){
        int A, B, n;
        cin >> A >> B >> n;
        cout << helper(A, B, n) << endl;
    }
    return 0;
}