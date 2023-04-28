#include<bits/stdc++.h>

using namespace std;
deque<int> pool;
unordered_map<int, int> val2idx;
unordered_set<int> inuse;
int n;
int l, r;
int t;
int lft = 0;

int main() {
    cin >> l >> r;
    int idxt = 0;
    for (int i = l; i <= r; i++) {
        pool.push_back(i);
        val2idx[i] = idxt;
        idxt++;
    }
    cin >> t;
    while (t--) {
        int op;
        cin >> op;
        if (op == 1) {
            int num;
            cin >> num;
            if (num > (pool.size() - lft))continue;
            for (int i = lft; i <= lft + num; i++) {
                if (pool[i] == INT_MAX) {
                    num++;
                    continue;
                }
                inuse.insert(pool[i]);
                val2idx.erase(pool[i]);
                pool[i] = INT_MAX;
            }
            lft += num;
        } else if (op == 2) {
            int id;
            cin >> id;
            if (id < l || id > r || inuse.count(id)) {
                continue;
            }
            int idx = val2idx[id];
            // pool.erase(pool.begin()+idx);
            pool[idx] = INT_MAX;
            val2idx.erase(id);
            inuse.insert(id);
        } else {
            int id;
            cin >> id;
            if (id < l || id > r || !inuse.count(id)) {
                continue;
            }
            inuse.erase(id);
            pool.push_back(id);
            val2idx[id] = pool.size() - 1;
        }
    }
    cout << pool[lft];
    return 0;
}

