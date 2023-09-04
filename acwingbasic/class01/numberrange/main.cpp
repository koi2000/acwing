//
// Created by Administrator on 2023年01月08日0008.
//
#include "bits/stdc++.h"

#define ll long long
using namespace std;
const int N = 1e5 + 10;

int arr[N];
int tmp[N];

void binarySearch() {

}

int main() {
    ios::sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < q; ++i) {
        int k;
        cin >> k;
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = (l + r) / 2;
            if (k > arr[mid]) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        if (arr[l] != k) {
            cout << "-1 -1" << endl;
        } else {
            cout << l << " ";
            int l = 0, r = n - 1;
            while (l < r) {
                int mid = (l + r + 1) / 2;
                if (k < arr[mid]) {
                    r = mid - 1;
                } else {
                    l = mid;
                }
            }
            cout << l << endl;
        }

    }
    return 0;
}