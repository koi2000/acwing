/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
 */
#include<bits/stdc++.h>
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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    int maxDepth(TreeNode* root) {
        queue<pair<TreeNode*,int>>q;
        q.push({root,1});
        int res = 1;
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            res = max(res,it.second);
            if(it.first==nullptr){
                continue;
            }
            q.push({it.first->left,it.second+1});
            q.push({it.first->right,it.second+1});
        }
        return res-1;
    }
};
// @lc code=end

