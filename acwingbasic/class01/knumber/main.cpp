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

int qfind(int a[], int l, int r, int k) {
    if (l >= r) {
        return a[l];
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
    if (k <= j) {
        return qfind(a, l, j, k);
    } else {
        return qfind(a, j + 1, r, k);
    }

}

int main() {
    ios::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << qfind(arr, 0, n - 1, k - 1);
    return 0;
}