#include "bits/stdc++.h"

#define ll long long
#define pii pair<int,int>
using namespace std;
string str;
int n;
int num = 0;
const int mod = 1e9 + 7;
unordered_set<string> st;

bool check(string ck) {
    unordered_map<char, int> q;
    for (int i = 0; i < ck.size(); ++i) {
        if (q.count(ck[i])) {
            q[ck[i]]++;
        } else {
            q[ck[i]] = 1;
        }

    }
    if (q.empty()) return false;
    for (auto it:q) {
        if (it.second % 2 == 1)return false;
    }
    return true;
}

void dfs(int step, string now) {
    if (step >= n) {
        st.insert(now);
        return;
    };
//    if (st.count(now))return;
    //st.insert(now);
    dfs(step + 1, now);
    now[step] = '1';
    dfs(step + 1, now);
}

int main() {
    cin >> str;
    n = str.size();
    string tp;
    tp.resize(n);
    for (int i = 0; i < n; ++i) {
        tp[i] = '0';
    }
    dfs(0, tp);
    for (auto it : st) {
        string tps;
        for (int i = 0; i < it.size(); ++i) {
            if (it[i] == '1') {
                tps += str[i];
            }
        }
        if (check(tps)) {
            num = (num + 1) % mod;
        }
    }
    cout << num << endl;
    return 0;
}