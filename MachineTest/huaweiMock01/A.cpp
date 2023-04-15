//
// Created by DELL on 2023/4/14.
//

#include<bits/stdc++.h>

#define ll long long
#define pii pair<int,int>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n;
    while (cin >> n) {
        if (n == 0)break;
        int res = 0;
        while (n >= 3) {
            n -= 3;
            n += 1;
            res++;
        }
        if (n == 2) {
            res++;
        }
        cout << res << endl;
    }


    return 0;
}
