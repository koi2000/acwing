//
// Created by DELL on 2023/1/11.
//

#include "bits/stdc++.h"

#define ll long long
using namespace std;

int mat[3][3];

int bfs(string start) {
    string end = "12345678x";
    queue<string> q;
    unordered_map<string, int> d;
    q.push(start);
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    while (!q.empty()) {
        auto t = q.front();
        q.pop();
        int distance = d[t];
        if (t == end) {
            return distance;
        }
        int k = t.find('x');
        int x = k / 3, y = k % 3;
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < 3 && ny < 3 && ny >= 0) {
                swap(t[k], t[nx * 3 + ny]);
                if (!d.count(t)) {
                    d[t] = distance + 1;
                    q.push(t);
                }
                swap(t[k], t[nx * 3 + ny]);
            }
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    char str[2];
    string stage;
    for (int i = 0; i < 9; ++i) {
        char c;
        cin >> c;
        stage += c;
    }
    cout << bfs(stage);
    return 0;
}
