#include "bits/stdc++.h"

#define ll long long
using namespace std;
int n, m;

map<string, vector<string>> mp;
map<int, int> level;

void dfs(string now, int depth) {
    int cnt = 0;
    if (mp.count(now)) {
        if (mp[now].empty()) {
            cnt++;
        }
    } else {
        cnt++;
    }
    for (int i = 0; i < mp[now].size(); ++i) {
        string nt = mp[now][i];
        dfs(mp[now][i], depth + 1);
    }
    if (level.count(depth)) {
        level[depth] += cnt;
    } else {
        level[depth] = cnt;
    }
}

int main() {
//    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        string id1;
        int k;
        string idk;
        cin >> id1 >> k;
        for (int j = 0; j < k; ++j) {
            cin >> idk;
            if (mp.count(id1)) {
                mp[id1].push_back(idk);
            } else {
                mp[id1] = vector<string>(1, idk);
            }
        }
    }
    dfs("01", 1);
    for (auto it = level.begin(); ; ) {
        if (++it!=level.end()){
            it--;
            cout << it->second << " ";
            it++;
        }else{
            it--;
            cout << it->second;
            break;
        }
    }
    return 0;
}

