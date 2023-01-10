//
// Created by Administrator on 2023年01月08日0008.
//
#include "bits/stdc++.h"

#define ll long long
using namespace std;
const int N = 1e5 + 10;

int arr[N];

void qsort(int a[], int l, int r) {
    if (l >= r) {
        return;
    }
    int p = a[(r + l) >> 1];
    int i = l - 1;
    int j = r + 1;
    while (i < j) {
        do {
            i++;
        } while (a[i] < p);
        do {
            j--;
        } while (a[j] > p);
        if (i < j) {
            swap(a[i], a[j]);
        }
    }
    qsort(a, l, j);
    qsort(a, j + 1, r);
}

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    qsort(arr, 0, n - 1);
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    return 0;
}