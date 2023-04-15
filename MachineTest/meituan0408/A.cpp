#include<bits/stdc++.h>

#define ll long long
#define pii pair<int,int>
using namespace std;
int n, m, a;

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m >> a;
    vector<vector<string>> mat(n, vector<string>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> mat[i][j];
        }
    }
    vector<vector<string>> res = mat;
    vector<string> ed = *res.rbegin();
    res.erase(--res.end());
    res.insert(res.begin(), ed);
    for (int i = 0; i < n; ++i) {
        string end = *res[i].rbegin();
        res[i].erase(--res[i].end());
        res[i].insert(res[i].begin(), end);
    }
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            string str1 = mat[i][j];
            string str2 = res[i][j];
            for (int k = 0; k < str1.size(); ++k) {
                if (str1[k] != str2[k]) {
                    sum++;
                }
            }
        }
    }
    cout << sum << endl;
    return 0;
}
