/*
 * @lc app=leetcode.cn id=222 lang=cpp
 *
 * [222] 完全二叉树的节点个数
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
    int countNodes(TreeNode *root) {
        queue<TreeNode *> q;
        q.push(root);
        int res = 0;
        while (!q.empty()) {
            TreeNode* it = q.front();
            q.pop();
            if (it == nullptr) {
                continue;
            }
            res++;
            q.push(it->left);
            q.push(it->right);
        }
        return res;
    }
};
// @lc code=end
