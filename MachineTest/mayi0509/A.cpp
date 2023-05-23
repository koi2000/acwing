#include "bits/stdc++.h"
#include "stdlib.h"

#define ll long long
#define pii pair<int,int>
using namespace std;

bool check(string num) {
    unordered_set<int> st;
//    if (num.size() < 3) return false;
//    if (num.size() < 4)st.insert(0);
    for (int i = 0; i < num.size(); ++i) {
        if (st.count(num[i] - '0')) {
            return false;
        }
        st.insert(num[i] - '0');
    }
    return true;
}

string myiota(int num) {
    string res = "0000";
    int idx = 0;
    while (num) {
        int tp = num % 16;
        if (tp < 10) {
            res[idx] = '0' + tp;
        } else {
            res[idx] = 'A' + tp - 10;
        }
        idx++;
        num /= 16;
    }
    reverse(res.begin(),res.end());
    return res;
}

int main() {
    int k;
    cin >> k;
    int idx = 0;
    string res;
    for (int i = 0; i < 65536; ++i) {
        if (idx == k) {
            break;
        }
        string re = myiota(i);
        if (check(re)) {
            idx++;
            res = re;
        }
    }
    if (res.size() < 4) {
        cout << 0;
    }
    for (int i = 0; i < res.size(); ++i) {
        if (islower(res[i]))cout << (char) (res[i] - 'a' + 'A');
        else cout << res[i];
    }
    return 0;
}