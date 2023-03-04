#include "bits/stdc++.h"

#define ll long long
using namespace std;

map<int, string> mp = {{0, "zero"},
                       {1, "one"},
                       {2, "two"},
                       {3, "three"},
                       {4, "four"},
                       {5, "five"},
                       {6, "six"},
                       {7, "seven"},
                       {8, "eight"},
                       {9, "nine"}};

int main() {
    ios::sync_with_stdio(false);
    string str;
    cin >> str;
    int sum = 0;
    for (int i = 0; i < str.size(); ++i) {
        sum += (str[i] - '0');
    }
    if (sum == 0) {
        cout << "zero";
        return 0;
    }
    vector<string> res;
    while (sum != 0) {
        int sec = sum % 10;
        res.push_back(mp[sec]);
        sum /= 10;
    }
    reverse(res.begin(), res.end());
    for (int i = 0; i < res.size(); ++i) {
        if (i == 0 && res[0] == "zero")continue;
        if (i != res.size() - 1) {
            cout << res[i] << " ";
        } else {
            cout << res[i];
        }
    }
    return 0;
}
