//
// Created by DELL on 2022/6/7.
//
#include <bits/stdc++.h>

using namespace std;

class node {
public:
    int id;
    int areaId;
    int tasks = 0;

    node() {}

    node(int id, int areaId) : id(id), areaId(areaId) {}

    node(const node &n) {
        id = n.id;
        areaId = n.areaId;
        tasks = n.tasks;
    }

    bool operator<(const node &rhs) const {
        if (tasks == rhs.tasks) {
            return id < rhs.id;
        }
        return tasks < rhs.tasks;
    }

    bool operator>(const node &rhs) const {
        return rhs < *this;
    }

    bool operator<=(const node &rhs) const {
        return !(rhs < *this);
    }

    bool operator>=(const node &rhs) const {
        return !(*this < rhs);
    }
};

class area {
public:
    int id;
    map<int, node> nodes;
};

map<int, set<int>> app2area;
map<int, set<int>> app2node;

void check(vector<struct node> &nd, int na, int pa, int paa) {
    if (na != 0) {
        for (auto it = nd.begin(); it != nd.end();) {
            if (it->areaId != na) {
                nd.erase(it);
            } else {
                it++;
            }
        }
    }
    if (pa != 0) {
        for (auto it = nd.begin(); it != nd.end();) {
            if (!app2area[pa].count(it->areaId)) {
                nd.erase(it);
            } else {
                it++;
            }
        }
    }
    if (paa != 0) {
        for (auto it = nd.begin(); it != nd.end();) {
            if (app2node[paa].find(it->id) != app2node[paa].end()) {
                nd.erase(it);
            } else {
                it++;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    // 维护一个任务到区域的映射，方便快速找到任务所在的区域
    map<int, int> task2area;
    map<int, int> task2node;
    map<int, area> id2area;
    map<int, int> id2idx;
    vector<node> nodes;
    int tp;
    for (int i = 1; i <= n; ++i) {
        cin >> tp;
        id2area[tp].nodes.insert({i, node(i, tp)});
        nodes.emplace_back(i, tp);
    }
    int g;
    cin >> g;

    for (int i = 0; i < g; ++i) {
        int f, a, na, pa, paa, paar;
        cin >> f >> a >> na >> pa >> paa >> paar;

        for (int j = 0; j < f; ++j) {
            vector<node> nd = vector<node>(n);
            for (int k = 0; k < nodes.size(); ++k) {
                nd[k] = nodes[k];
            }
            check(nd, na, pa, paa);
            if (paa != 0 && nd.empty() && paar == 0) {
                nd = vector<node>(n);
                for (int k = 0; k < nodes.size(); ++k) {
                    nd[k] = nodes[k];
                }
                check(nd, na, pa, 0);
            }
            if (nd.empty())cout << 0 << " ";
            else {
                sort(nd.begin(), nd.end());
                cout << nd[0].id << " ";
                // 更新区域，同时还需要更新每个节点的任务
                app2area[a].insert(nd[0].areaId);
                app2node[a].insert(nd[0].id);
                nodes[nd[0].id - 1].tasks++;
            }
        }
        cout << "\n";
    }
    return 0;
}
