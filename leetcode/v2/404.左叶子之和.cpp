/*
 * @lc app=leetcode.cn id=404 lang=cpp
 *
 * [404] 左叶子之和
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
    int sumOfLeftLeaves(TreeNode *root) {
        queue<TreeNode *> q;
        q.push(root);
        int res = 0;
        while (!q.empty()) {
            TreeNode *it = q.front();
            q.pop();
            if (it == nullptr) {
                continue;
            }
            if (it->left != nullptr&&it->left->left == nullptr&&it->left->right == nullptr) {
                res += it->left->val;
            }

            q.push(it->left);
            q.push(it->right);
        }
        return res;
    }
};
// @lc code=end
