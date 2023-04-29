//
// Created by DELL on 2023/4/29.
//
#include <cstring>
#include <vector>

class Solution {
public:
    int n;
    int m;
    int dir[4][2] = {{0,  1},
                     {1,  0},
                     {0,  -1},
                     {-1, 0}};
    int vis[11][11];

    bool check(int x, int y) {
        if (x >= 0 && x < n && y >= 0 && y < m && !vis[x][y]) {
            return true;
        }
        return false;
    }

    vector<int> spiralOrder(vector <vector<int>> &matrix) {
        n = matrix.size();
        vector<int> res;
        if (n == 0) {
            return res;
        }
        m = matrix[0].size();
        memset(vis, 0, sizeof vis);
        int idx = 0;
        res.push_back(matrix[0][0]);
        vis[0][0] = 1;
        int x = 0;
        int y = 0;
        int sz = 1;
        while (sz < n * m) {
            int dx = dir[idx][0] + x;
            int dy = dir[idx][1] + y;
            if (check(dx, dy)) {
                res.push_back(matrix[dx][dy]);
                x = dx;
                y = dy;
                vis[dx][dy] = 1;
                sz++;
            } else {
                idx = (idx + 1) % 4;
            }
        }
        return res;
    }

};
