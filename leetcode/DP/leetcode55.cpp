//
// Created by DELL on 2023/3/23.
//
#include<bits/stdc++.h>

#define ll long long
#define pii pair<int,int>
using namespace std;

class Solution {
public:
    bool canJump(vector<int> &nums) {
        int k = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i > k) return false;
            k = max(k, i + nums[i]);
        }
        return true;
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

