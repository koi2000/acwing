#include "bits/stdc++.h"

#define ll long long
#define pii pair<int,int>
using namespace std;
int n;

int myatoi(string num) {
    int sum = 0;
    int base = 1;
    for (int i = num.size() - 1; i >= 0; --i) {
        sum += (num[i] - '0') * base;
        base *= 10;
    }
    return sum;
}

int main() {
    cin >> n;
    vector<string> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    int minn = INT_MAX;
    int maxx = -1;
    int mark = -1;
    for (int i = 0; i < n; ++i) {

        string tp = arr[i];
        for (int j = 0; j < arr[i].size(); ++j) {
            if (tp[j] == '?') {
                tp[j] = '0';
            }
        }
        if (tp.size() > 1 && tp[0] == '0') tp[0] = '1';
        int num = myatoi(tp.c_str());
//        minn = min(minn, num);
        if (num < minn) {
            minn = num;
            mark = i;
        }
    }

    for (int i = 0; i < n; ++i) {
        if (i == mark)continue;
        string tp = arr[i];
        for (int j = 0; j < arr[i].size(); ++j) {
            if (tp[j] == '?') {
                tp[j] = '9';
            }
        }
        if (tp.size() > 1 && tp[0] == '0')continue;
        int num = atoi(tp.c_str());
        if (num > maxx) {
            maxx = num;
        }
    }

    cout << maxx - minn;
    return 0;
}