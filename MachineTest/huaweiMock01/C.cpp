//
// Created by DELL on 2023/4/14.
//

#include<bits/stdc++.h>

#define ll long long
#define pii pair<int,int>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    string num;
    cin >> num;
    int res = 0;
    int base = 1;
    for (int i = num.size() - 1; i >= 2; --i) {
        if (isalpha(num[i])) {
            res += (num[i] - 'A' + 10) * base;
        } else {
            res += (num[i] - '0') * base;
        }
        base *= 16;
    }
    cout << res << endl;
    return 0;
}
