#include<bits/stdc++.h>

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

    bool valid(TreeNode *root, long lower, long higher) {
        if (root == nullptr)return true;
        if (root->val <= lower || root->val >= higher) {
            return false;
        }
        return valid(root->left, lower, root->val) & valid(root->right, root->val, higher);
    }

    bool isValidBST(TreeNode *root) {
        return valid(root, LONG_MIN, LONG_MAX);
    }
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}
