/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
 */

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
    int minDepth(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }

        queue<pair<TreeNode *, int>> q;
        q.push({root, 1});
        int res = INT_MAX;
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            if (it.first == nullptr) {
                continue;
            }
            if (it.first->left == nullptr && it.first->right == nullptr) {
                res = min(res, it.second);
            }

            q.push({it.first->left, it.second + 1});
            q.push({it.first->right, it.second + 1});
        }

        return res;
    }
};
// @lc code=end
