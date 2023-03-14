#include <bits/stdc++.h>

using namespace std;

// 判断质数函数
bool isprime(int n) {
    if (n == 2 || n == 3 || n == 5) return true;
    if (n == 1 || n == 4) return false;
    for (int i = 2; i <= n / i; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    vector<int> primes;
    for (int i = 2; i <= 500; i++) {
        if (isprime(i)) primes.push_back(i);
    }
    vector<int> ans;
    for (int i = 1; i < primes.size(); i++) {
        int cur = primes[i - 1] + primes[i] + 1;
        if (isprime(cur)) {
            ans.push_back(cur);
        }
    }

    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        if (ans.size() < k || ans[k - 1] > n) puts("NO");
        else puts("YES");
    }
    return 0;
}