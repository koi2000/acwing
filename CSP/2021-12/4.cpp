//
// Created by csp on 2021/12/5.
//
#include<bits/stdc++.h>

using namespace std;

class disk {
public:
    vector<int> m;
    vector<int> vis;
    vector<int> last;

    disk(int n) {
        m.resize(n + 1);
        vis.resize(n + 1);
        last.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            m[i] = 0;
            vis[i] = 0;
            last[i] = 0;
        }
    }

    void write(int id, int l, int r, int x);

    void erase(int id, int l, int r);

    void recovery(int id, int l, int r);

    void read(int p);
};

void disk::write(int id, int l, int r, int x) {
    for (int i = l; i <= r; i++) {
        if (vis[i] == id) {
            m[i] = x;
        } else if (vis[i] == 0) {
            vis[i] = id;
            m[i] = x;
        } else {
            if (i == l) {
                cout << -1 << endl;
            } else {
                cout << i - 1 << endl;
            }
            break;
        }
        if (i == r) {
            cout << r << endl;
        }
    }
}

void disk::erase(int id, int l, int r) {
    int flag = 0;
    for (int i = l; i <= r; i++) {
        if (vis[i] != id) {
            flag = 1;
            break;
        }
    }
    if (flag != 1) {
        for (int i = l; i <= r; i++) {
            vis[i] = 0;
            last[i] = id;
        }
        cout << "OK" << endl;
    } else {
        cout << "FAIL" << endl;
    }
}

void disk::recovery(int id, int l, int r) {
    int flag = 0;
    for (int i = l; i <= r; i++) {
        if (!(vis[i] == 0 && last[i] == id)) {
            flag = 1;
            break;
        }
    }
    if (flag != 1) {
        for (int i = l; i <= r; i++) {
            vis[i] = id;
        }
        cout << "OK" << endl;
    } else {
        cout << "FAIL" << endl;
    }
}

void disk::read(int p) {
    if (vis[p] != 0) {
        cout << vis[p] << " " << m[p] << endl;
    } else {
        cout << 0 << " " << 0 << endl;
    }
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    disk dd = disk(m);
    for (int i = 0; i < k; i++) {
        int opt;
        cin >> opt;
        int id, l, r, x;
        if (opt == 0) {
            cin >> id >> l >> r >> x;
            dd.write(id, l, r, x);
        } else if (opt == 1) {
            cin >> id >> l >> r;
            dd.erase(id, l, r);
        } else if (opt == 2) {
            cin >> id >> l >> r;
            dd.recovery(id, l, r);
        } else {
            int p;
            cin >> p;
            dd.read(p);
        }
    }
    return 0;
}

