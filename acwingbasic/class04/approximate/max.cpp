//
// Created by DELL on 2023/1/13.
//

#include "bits/stdc++.h"

using namespace std;


int gcd(int a, int b) {
    if (b) {
        return gcd(b, a % b);
    } else {
        return a;
    }
}


int main() {
    int n;
    cin >> n;
    while (n--) {
        int a, b;
        cin >> a >> b;
        cout << gcd(a, b) << endl;
    }

    return 0;
}