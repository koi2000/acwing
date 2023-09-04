#include "bits/stdc++.h"

#define ll long long
using namespace std;
const int N = 1e5 + 10;
int arr[N];
int res[N];
int st[N];
int n;

void per(int depth) {
    if (depth == n) {
        for (int i = 0; i < n; ++i) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    } else {
        for (int i = depth; i < n; ++i) {
            swap(arr[depth], arr[i]);
            per(depth + 1);
            swap(arr[depth], arr[i]);
        }
    }
}

void dfs(int depth) {
    if (depth == n) {
        for (int i = 0; i < n; ++i) {
            cout << res[i] << " ";
        }
        cout << "\n";
    } else {
        for (int i = 0; i < n; ++i) {
            if (!st[i]) {
                res[depth] = arr[i];
                st[i] = true;
                dfs(depth + 1);
                st[i] = false;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        arr[i] = i + 1;
    }
    dfs(0);
    return 0;
}
