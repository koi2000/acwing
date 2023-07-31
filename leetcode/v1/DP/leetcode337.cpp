#include <bits/stdc++.h>

#define ll long long
#define pii pair<int,int>
using namespace std;

/**
 * Definition for a binarySearch tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    map<pair<TreeNode *, int>, int> mp;

    int dfs(TreeNode *now, int money, int mark) {
        if (now == nullptr) {
            return money;
        }
        if (mp.count({now, mark}))return mp[{now, mark}];
        int res = -1;
        if (!mark) {
            int lr1 = dfs(now->left, money, 1);
            int rr1 = dfs(now->right, money, 1);
            int lr2 = dfs(now->left, money, 0);
            int rr2 = dfs(now->right, money, 0);
            mp[{now, mark}] = max(lr1 + rr1 + now->val, lr2 + rr2);
            return max(lr1 + rr1 + now->val, lr2 + rr2);
        } else {
            int lr = dfs(now->left, money, 0);
            int rr = dfs(now->right, money, 0);
            mp[{now, mark}] = lr + rr;
            return lr + rr;
        }
        return res;
    }

    int rob(TreeNode *root) {
        return dfs(root, 0, 0);
    }
};

int main() {
    return 0;
}

