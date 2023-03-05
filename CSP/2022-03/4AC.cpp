//
// Created by DELL on 2022/6/7.
//
#include <bits/stdc++.h>

#define ll long long
using namespace std;


int n, m;
const int maxn = 1e5 + 10;

struct node {
    ll value;
    int to;

    node(long long int value, int to) : value(value), to(to) {
    }

    bool operator<(const node &rhs) const {
        if (value == rhs.value) {
            return to < rhs.to;
        }
        return value > rhs.value;
    }
};

struct info {
    int u, v, x;

    info(int u, int v, int x) : u(u), v(v), x(x) {}
};

set<node> d[maxn];
map<pair<int, int>, ll> save;

vector<info> deActive[maxn];
int pValue, qValue;

// 检查一个点是否为孤岛
int check_p(int x) {
    return d[x].begin() == d[x].end() || d[x].begin()->value == 0;
}

// 检查一个点是否包含一个通讯对
int check_q(int x) {
    if (check_p(x))return 0;
    int y = d[x].begin()->to;
    return !check_p(y) && d[y].begin()->to == x;
}

void work(int u, int v, int x) {
    ll oValue = save[{u, v}];
    save[{u, v}] += x;

    // 处理 孤岛数量
    pValue -= check_p(u);
    // 处理 通讯对数量
    qValue -= check_q(u);

    // 删除旧的
    node org = node(oValue, v);
    d[u].erase(org);
    d[u].emplace(save[{u, v}], v);

    // 处理 孤岛数量
    pValue += check_p(u);
    // 处理 通讯对数量
    qValue += check_q(u);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    pValue = n;
    qValue = 0;
    for (int i = 0; i < m; ++i) {
        int k;
        cin >> k;
        // 处理过期额度
        for (const auto &x:deActive[i]) {
            work(x.u, x.v, -x.x);
            work(x.v, x.u, -x.x);
        }


        for (int j = 0; j < k; ++j) {
            int u, v, x, y;
            cin >> u >> v >> x >> y;
            if (i + y <= m) {
                deActive[i + y].emplace_back(u, v, x);
            }
            work(u, v, x);
            work(v, u, x);
        }
        int l;
        cin >> l;
        map<int, int> mp;
        for (int j = 0; j < l; ++j) {
            int x;
            cin >> x;
            if (check_p(x)) {
                cout << 0 << "\n";
            } else {
                cout << d[x].begin()->to << "\n";
            }
        }
        int p, q;
        cin >> p >> q;
        // p指的是孤岛数量
        if (p != 0) {

            cout << pValue << "\n";
        }
        // q指通信对
        if (q != 0) {
            cout << qValue << "\n";
        }
    }
    return 0;
}
