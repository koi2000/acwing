#include<bits/stdc++.h>

#define ll long long
#define pii pair<int,int>
using namespace std;
int n;
int arr[20010];

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    int res = 0;
    for (int i = 1; i <= n; ++i) {
        res += min(abs(i - arr[i-1]), abs(arr[i-1] - i));
    }
    cout << res << endl;
    return 0;
}
