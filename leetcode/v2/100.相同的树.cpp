/*
 * @lc app=leetcode.cn id=100 lang=cpp
 *
 * [100] 相同的树
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
    bool isEqual(TreeNode *t1, TreeNode *t2) {
        if (t1 == nullptr && t2 == nullptr) {
            return true;
        }
        if (t1 == nullptr || t2 == nullptr) {
            return false;
        } else {
            if (t1->val != t2->val) {
                return false;
            }
            return isEqual(t1->left, t2->left) & isEqual(t1->right, t2->right);
        }
    }

    bool isSameTree(TreeNode *p, TreeNode *q) { return isEqual(p, q); }
};
// @lc code=end
