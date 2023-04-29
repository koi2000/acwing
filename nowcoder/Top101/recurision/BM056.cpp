//
// Created by DELL on 2023/4/28.
//
#include <vector>

class Solution {
public:

    set <vector<int>> res;

    int n;

    void dfs(vector<int> arr, int depth) {
        if (depth == n - 1) {
            res.insert(arr);
        } else {
            for (int i = depth; i < n; i++) {
                swap(arr[depth], arr[i]);
                dfs(arr, depth + 1);
                swap(arr[depth], arr[i]);
            }
        }
    }

    vector <vector<int>> permuteUnique(vector<int> &num) {
        n = num.size();
        dfs(num, 0);
        vector <vector<int>> ret;
        for (auto it:res) {
            ret.push_back(it);
        }
        return ret;
    }
};

#include <vector>
class Solution {
public:
    void recursion(vector<vector<int>>& res, vector<int>& num, vector<int>& temp,
                   vector<int>& vis) {
        // 到达递归边界，将数组加入到其中
        if (temp.size() == num.size()) {
            res.push_back(temp);
            return;
        }
        // 遍历所有元素选一个加入
        for (int i = 0; i < num.size(); i++) {
            // 如果该元素已经被加入则不需要再加入了
            if (vis[i]) {
                continue;
            }
            if (i > 0 && num[i - 1] == num[i] && !vis[i - 1]) {
                continue;
            }
            vis[i] = 1;
            temp.push_back(num[i]);
            recursion(res, num, temp, vis);
            vis[i] = 0;
            temp.pop_back();
        }
    }

    vector<vector<int> > permuteUnique(vector<int>& num) {
        sort(num.begin(), num.end());
        vector<int> vis(num.size(), 0);
        vector<vector<int> > res;
        vector<int> temp;
        recursion(res, num, temp, vis);
        return res;
    }
};