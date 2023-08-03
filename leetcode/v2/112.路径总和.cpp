/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
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
    bool hasPathSum(TreeNode *root, int targetSum) {
        if (root == nullptr) {
            return false;
        }

        queue<pair<TreeNode *, int>> q;
        q.push({root, root->val});
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            if (it.first->left == nullptr && it.first->right == nullptr) {
                if (it.second == targetSum) {
                    return true;
                }
                continue;
            }
            if (it.first->left != nullptr) {
                q.push({it.first->left, it.second + it.first->left->val});
            }
            if (it.first->right != nullptr) {
                q.push({it.first->right, it.second + it.first->right->val});
            }
        }
        return false;
    }
};
// @lc code=end
