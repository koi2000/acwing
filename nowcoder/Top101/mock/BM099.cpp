//
// Created by DELL on 2023/4/29.
//
#include <algorithm>
#include <fstream>
class Solution {
public:
    vector<vector<int> > rotateMatrix(vector<vector<int> > mat, int n) {
        // write code here
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                swap(mat[i][j], mat[j][i]);
            }
        }
        for (int i = 0; i < n; i++) {
            reverse(mat[i].begin(), mat[i].end());
        }
        return mat;
    }
};
