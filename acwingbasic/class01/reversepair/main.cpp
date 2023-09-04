//
// Created by Administrator on 2023年01月08日0008.
//
#include "bits/stdc++.h"

#define ll long long
using namespace std;
const int N = 1e5 + 10;

int arr[N];
int tmp[N];

ll mergesort(int a[], int l, int r) {
    if (l >= r) return 0;
    int mid = (l + r) >> 1;

    ll res = mergesort(a, l, mid) + mergesort(a, mid + 1, r);
    int k = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r) {
        if (a[i] <= a[j]) {
            tmp[k++] = a[i++];
        } else {
            tmp[k++] = a[j++], res += (mid - i + 1);
        }
    }
    while (i <= mid) {
        tmp[k++] = a[i++];
    }
    while (j <= r) {
        tmp[k++] = a[j++];
    }
    for (i = l, j = 0; i <= r; i++, j++) {
        a[i] = tmp[j];
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    ll res = mergesort(arr, 0, n - 1);
//    for (int i = 0; i < n; ++i) {
//        cout << arr[i] << " ";
//    }
    cout << res << endl;
    return 0;
}