//
// Created by DELL on 2025/1/29.
//
#include <bits/stdc++.h>
using namespace std;

const int N = 1009;

int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

int n;
int mp[N][N];
bool vis[N][N];
pair<int, int> res[N][N];

bool isValid(int x, int y) {
  if (x >= 0 && y >= 0 && x < n && y < n) {
    return true;
  }
  return false;
}

void bfs() {
  queue<pair<int, int>> q;
  q.push({0, 0});
  while (!q.empty()) {
    auto node = q.front();
    q.pop();
    for (int i = 0; i < 4; ++i) {
      int newx = dir[i][0] + node.first;
      int newy = dir[i][1] + node.second;
      if (isValid(newx, newy) && mp[newx][newy] != 1 && !vis[newx][newy]) {
        res[newx][newy] = node;
        vis[newx][newy] = true;
        if (newx == n - 1 && newy == n - 1) {
          while (!q.empty())
            q.pop();
          break;
        }
        q.push({newx, newy});
      }
    }
  }
  std::vector<pair<int, int>> re;
  pair<int, int> node = {n - 1, n - 1};
  while (true) {
    re.push_back(node);
    if (node.first == 0 && node.second == 0) {
      break;
    }
    node = res[node.first][node.second];
  }
  for (int i = re.size() - 1; i >= 0; --i) {
    cout << re[i].first << " " << re[i].second << endl;
  }
}

int main() {
  cin >> n;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      cin >> mp[i][j];
  bfs();
  return 0;
}
