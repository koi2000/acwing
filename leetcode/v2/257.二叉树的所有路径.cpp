/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
  public:
    vector<string> binaryTreePaths(TreeNode *root) {
        queue<pair<TreeNode *, string>> q;
        vector<string> res;
        q.push({root, ""});
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            if (it.first == nullptr) {
                continue;
            }
            if (it.first->left == nullptr && it.first->right == nullptr) {
                string tmp = it.second + to_string(it.first->val);
                res.push_back(tmp);
            }
            string str = it.second + to_string(it.first->val) + "->";
            q.push({it.first->left, str});
            q.push({it.first->right, str});
        }
        return res;
    }
};
// @lc code=end
