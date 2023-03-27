#include<bits/stdc++.h>

#define ll long long
#define pii pair<int,int>
using namespace std;

class Solution {
public:
    int d[4][2] = {{0,  1},
                   {1,  0},
                   {0,  -1},
                   {-1, 0}};
    int n;

    bool check(int x, int y) {
        if (x >= 0 && y >= 0 && x < n && y < n) {
            return true;
        }
        return false;
    }

    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> mat(n, vector<int>(n));
        this->n = n;
        bool vis[n][n];
        memset(vis, 0, sizeof vis);
        int x = 0;
        int y = 0;
        int cnt = 1;
        int idx = 0;
        while (true) {
            mat[x][y] = cnt;
            vis[x][y] = 1;
            cnt++;
            if (cnt > n * n)break;
            int dx = x + d[idx][0];
            int dy = y + d[idx][1];
            if (check(dx, dy) && !vis[dx][dy]) {
                x = dx;
                y = dy;
            } else {
                idx = (idx + 1) % 4;
                x = x + d[idx][0];
                y = y + d[idx][1];
            }
        }
        return mat;
    }
};

int main() {
    ios::sync_with_stdio(false);
    Solution solution = Solution();
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(4);
    arr.push_back(5);
    solution.generateMatrix(3);
    return 0;
}

