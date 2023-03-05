#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
#define maxK 1001
#define maxN 20
#define maxM 10
struct Window {
    queue<int> q;
    int popTime;
} windows[maxN];
int cost[maxK];
int finished[maxK];
int n, m, k, q;

// 填满黄线前的位置
int fillWindow() {
    int id = 1;
    for (int j = 0; j < n; j++) {
        windows[j].popTime = cost[id];
        windows[j].q.push(id);
        if (++id > k) return id;
    }
    for (int i = 0; i < m - 1; i++) {
        for (int j = 0; j < n; j++) {
            windows[j].q.push(id);
            if (++id > k) return id;
        }
    }
    return id;
}

int main() {
    scanf("%d %d %d %d", &n, &m, &k, &q);
    for (int i = 1; i <= k; i++) {
        scanf("%d", &cost[i]);
    }
    // 初始化完成时间， -1代表无法完成业务
    fill(finished, finished + maxK, -1);
    int id = fillWindow();
    // 模拟
    for (int t = 0; t < 540; t++) {
        for (int i = 0; i < n; i++) {
            if (windows[i].popTime != t) continue;
            // 出列， 记录完成时间
            finished[windows[i].q.front()] = t;
            windows[i].q.pop();

            if (windows[i].q.size() > 0) {
                // 更新出列时间
                windows[i].popTime = t + cost[windows[i].q.front()];
            }
            if (id > k) continue;

            // 空出空位， 黄线外的客户进去一个
            windows[i].q.push(id);
            id++;
        }
    }

    // 完成每个窗口当前服务的客户（如果有的话）
    for (int i = 0; i < n; i++) {
        if (windows[i].q.size() < 1) continue;
        finished[windows[i].q.front()] = windows[i].popTime;
    }

    int query, timestamp;
    for (int i = 0; i < q; i++) {
        scanf("%d", &query);
        timestamp = finished[query];
        if (timestamp == -1) {
            printf("Sorry\n");
            continue;
        }
        printf("%02d:%02d\n", timestamp / 60 + 8, timestamp % 60);
    }
    return 0;
}
