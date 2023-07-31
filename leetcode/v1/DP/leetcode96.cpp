//
// Created by DELL on 2023/3/23.
//
#include<bits/stdc++.h>

#define ll long long
#define pii pair<int,int>
using namespace std;

// 递归+记忆化搜索
class Solution {
public:
    map<pair<int, int>, int> mp;

    int generateTree(int start, int end) {
        if (start > end)return 1;
        if (mp.count({start, end}))return mp[{start, end}];
        int sum = 0;
        for (int i = start; i <= end; i++) {
            int l = generateTree(start, i - 1);
            int r = generateTree(i + 1, end);
            sum += l * r;
        }
        mp[{start, end}] = sum;
        return sum;
    }

    int numTrees(int n) {
        if (!n)return 0;
        return generateTree(1, n);
    }
};

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; ++i) {
        int tp;
        cin >> tp;
        arr.push_back(tp);
    }
    Solution solution;
    solution.canJump(arr);
    return 0;
}

