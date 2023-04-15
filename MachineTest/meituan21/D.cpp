#include<bits/stdc++.h>

#define ll long long
#define pii pair<int,int>
using namespace std;

vector<int> a;
int n;
struct TreeNode {
    int val = 1;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;
};

pii buildAll(vector<int> arr) {
    if (arr.empty())return {0, 0};
    int res = INT_MAX;
    int val = 1;
    for (auto it = arr.begin(); it != arr.end(); it++) {
        int sum = 0;
        vector<int> left(arr.begin(), it);
        pii le = buildAll(left);
        sum += *it * le.second;
        sum += le.first;
        vector<int> right(it + 1, arr.end());
        pii ri = buildAll(right);
        sum += *it * ri.second;
        sum += ri.first;
        if (sum <= res) {
            res = sum;
            val = *it;
        }
    }
    return {res, val};
}


int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int tp;
        cin >> tp;
        a.push_back(tp);
    }
    cout << buildAll(a).first << endl;
    return 0;
}
