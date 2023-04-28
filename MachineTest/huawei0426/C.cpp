//
// Created by DELL on 2023/4/26.
//
#include<bits/stdc++.h>

#define pii pair<int,int>
using namespace std;
map<pii, set<int>> mat;
queue<pair<pii, int>> q;
int dir[8][2] = {{1,  0},
                 {-1, 0},
                 {0,  -1},
                 {0,  1},
                 {1,  1},
                 {1,  -1},
                 {-1, 1},
                 {-1, -1}};
int m, n;

void bfs() {
    while (!q.empty()) {
        auto node = q.front();
        pii pos = node.first;
        int cv = node.second;
        q.pop();
        for(int color:mat[pos]){
            for (int i = 0; i < 8; ++i) {
                int dx = pos.first + dir[i][0];
                int dy = pos.second + dir[i][1];
                if(!mat[{dx,dy}].count(color)){
                    mat[{dx,dy}].insert(color);
                    q.push({{dx,dy},cv+1});
                }
                if(mat[{dx,dy}].size()>=m){
                    cout<<cv+1<<endl;
                    return;
                }
            }
        }
    }
}

int main() {
    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        q.push({{x, y},0});
        mat[{x, y}].insert(i);
    }
    bfs();
    return 0;
}

