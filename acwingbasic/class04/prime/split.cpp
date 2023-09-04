//
// Created by DELL on 2023/1/13.
//
#include "bits/stdc++.h"

#define ll long long
using namespace std;
const int N = 105;
int arr[N];

void split(int n) {
    for (int i = 2; i <= n / i; ++i) {
        if (n % i == 0) {
            int s = 0;
            while (n % i == 0) {
                n /= i;
                s++;
            }
            cout << i << " " << s << endl;
        }
    }
    if (n > 1) {
        cout << n << " " << 1 << endl;
    }
    cout << endl;
}


int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        split(arr[i]);
    }
    return 0;
}

