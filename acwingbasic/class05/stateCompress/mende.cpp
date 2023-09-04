#include "bits/stdc++.h"

#define ll long long
using namespace std;

const int N = 12, M = 1 << N;
// 第一维表示列，第二维表示所有的可能
ll f[N][M];

// 存储每种状态是否有奇数个连续的0，如果奇数个0是无效状态
// 如果是偶数个0则为true
bool st[M];

// 二维数组记录合法的状态
vector<vector<int>> states(M);

int n, m;

int main() {
    ios::sync_with_stdio(false);
    while (cin >> n >> m, n || m) {
        // 第一部分：预处理
        // 对于每种状态，先预处理每列不能有奇数个连续的0
        for (int i = 0; i < (1 << n); ++i) {
            // 记录连续的0的个数
            int cnt = 0;
            bool isValid = true;
            // 遍历这一列 从上到下
            for (int j = 0; j < n; ++j) {
                // 判断i的第j位是否为1
                if ((i >> j) & 1) {
                    if (cnt & 1) {
                        isValid = false;
                        break;
                    }
                    cnt = 0;
                } else cnt++;
            }
            if (cnt & 1)isValid = false;
            // 状态i是否有奇数个连续的0的情况，输入到st数组中
            st[i] = isValid;
        }
        // 上面筛掉了连续奇数个0的情况
        // 判断i-2列伸出去的和第i-1列伸出去的是否冲突
        // 判断第i列所有的状态
        for (int j = 0; j < (1 << n); ++j) {
            states[j].clear();
            // 判断第i-1列所有的状态
            for (int k = 0; k < (1 << n); ++k) {
                // st数组表示的是这一列没有连续奇数个0的情况
                // 第i-1列由第i-2列横插过来
                // j和k进行异或 可以得到当前这一列的真实情况
                if ((j & k) == 0 && st[j | k]) {
                    states[j].push_back(k);
                }
            }
        }
        memset(f, 0, sizeof f);
        f[0][0] = 1;
        // 遍历每一列
        for (int i = 1; i <= m; ++i) {
            // 遍历当前列的所有合法的状态
            for (int j = 0; j < (1 << n); ++j) {
                // 遍历所有当前状态可由哪些状态转移而来
                for (auto k:states[j]) {
                    f[i][j] += f[i - 1][k];
                }
            }
        }
        // 答案为第m列没有伸出的状态
        cout << f[m][0] << endl;
    }
    return 0;
}
