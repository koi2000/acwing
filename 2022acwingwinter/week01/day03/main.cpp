#include<bits/stdc++.h>

using namespace std;

bool check(vector<int> arr, int k) {
    int sum = 0;
    for (int i = 0; i < arr.size(); ++i) {
        sum += arr[i];
        if (sum > k)return false;
        if (sum == k) sum = 0;
    }
    return true;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        int sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            sum += arr[i];
        }
        for (int i = n; i >= 0; --i) {
            if (sum % i == 0 && check(arr, sum / i)) {
                cout << n - i << endl;
                break;
            }
        }
    }
    return 0;
}