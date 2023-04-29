//
// Created by DELL on 2023/4/28.
//
#include <any>
#include <vector>
class Solution {
public:

    vector<vector<int>>res;

    int n;
    void dfs(vector<int> arr, int depth) {
        if (depth == n-1) {
            res.push_back(arr);
        } else {
            for (int i = depth; i < n; i++) {
                swap(arr[depth], arr[i]);
                dfs(arr,depth+1);
                swap(arr[depth], arr[i]);
            }
        }
    }

    vector<vector<int> > permute(vector<int>& num) {
        n = num.size();
        dfs(num,0);
        return res;
    }
};
