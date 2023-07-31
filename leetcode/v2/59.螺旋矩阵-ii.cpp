/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
  public:
    vector<vector<int>> mat;
    int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    vector<vector<int>> vis;
    int sz;
    bool check(int x, int y) {
        if (x >= 0 && x < sz && y >= 0 && y < sz) {
            return true;
        }
        return false;
    }

    void dfs() {
        int cnt = 2;
        int x = 0, y = 0;
        int idx = 0;
        mat[x][y] = 1;
        vis[x][y] = 1;
        while (true) {
            if (cnt == (sz * sz + 1))
                break;
            int dx = x + dir[idx][0];
            int dy = y + dir[idx][1];
            if (!check(dx, dy) || vis[dx][dy] == 1) {
                idx = (idx + 1) % 4;
                continue;
            }
            mat[dx][dy] = cnt;
            vis[dx][dy] = 1;
            x = dx, y = dy;
            cnt++;
        }
    }
    vector<vector<int>> generateMatrix(int n) {
        sz = n;
        mat = vector<vector<int>>(n, vector<int>(n));
        vis = vector<vector<int>>(n, vector<int>(n, 0));
        dfs();
        return mat;
    }
};
// @lc code=end

int main() {
    Solution solution;
    solution.generateMatrix(3);
}
