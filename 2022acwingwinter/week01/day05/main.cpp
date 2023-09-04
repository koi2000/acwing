#include<bits/stdc++.h>

#define ll long long
using namespace std;
const int N = 1e5 + 10;

int main() {
    ll n;
    cin >> n;
    ll arr[N];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    ll maxx = INT_MIN;
    int num = 0;
    for (int i = 0; i < n; ++i) {
        if (arr[i] * (n - i) > maxx) {
            maxx = arr[i] * (n - i);
            num = arr[i];
        }
    }
    cout << maxx << " " << num << endl;
    return 0;
}