#include "bits/stdc++.h"

#define ll long long
#define pii pair<int,int>
using namespace std;

string convertTime(int t) {
    if (t > 540) {
        return "Sorry";
    } else {
        int hour = 8 + t / 60;
        int min = t % 60;
        string s = "";
        if (hour < 10) s += "0";
        s += to_string(hour);
        s += ":";
        if (min < 10)s += "0";
        s += to_string(min);
        return s;
    }
}

queue<pii > customers;

struct window {
    int size;
    queue<pii > q;
    int endTime;

    window() {
        size = 0;
        q = queue<pii >();
        endTime = 0;
    }
};

int main() {
    ios::sync_with_stdio(false);
    int n, m, k, q;
    cin >> n >> m >> k >> q;
    window windows[n];
    map<int, int> endTimeMap;
    for (int i = 1; i <= k; ++i) {
        int tp;
        cin >> tp;
        customers.push({i, tp});
    }
    while (!customers.empty()) {
        // 为每一个顾客选一个通道
        // 先找有没有空着的，有就先塞进去
        // 如果没有空着的，就挤出来一个
        pii cus = customers.front();
        customers.pop();
        int minSize = m;
        int idx = -1;
        for (int i = 0; i < n; i++) {
            if (windows[i].size < minSize) {
                idx = i;
                minSize = windows[i].size;
            }
        }
        if (idx != -1) {
            windows[idx].q.push(cus);
            windows[idx].size++;
        } else {
            // 找一个最早结束的踢出来
            int minTime = INT_MAX;
            int idx = -1;
            for (int i = 0; i < n; ++i) {
                window w = windows[i];
                if (w.q.front().second + w.endTime < minTime) {
                    idx = i;
                    minTime = w.q.front().second + w.endTime;
                }
            }
            for (int i = 0; i < n; ++i) {
                window w = windows[i];
                if (w.q.front().second + w.endTime == minTime) {
                    pii fcus = windows[i].q.front();
                    windows[i].q.pop();
                    windows[i].endTime += fcus.second;
                    windows[i].size--;
                    endTimeMap[fcus.first] = minTime;
                }
            }
//            pii fcus = windows[idx].q.front();
//            windows[idx].endTime += fcus.second;
//            windows[idx].q.pop();
            windows[idx].q.push(cus);
            windows[idx].size++;
//            endTimeMap[fcus.first] = windows[idx].endTime;
        }
    }
    for (int i = 0; i < n; ++i) {
        window w = windows[i];
        while (!w.q.empty()) {
            pii fcus = w.q.front();
            w.endTime += fcus.second;
            w.q.pop();
            endTimeMap[fcus.first] = w.endTime;
        }
    }
    for (int i = 0; i < q; ++i) {
        int tp;
        cin >> tp;
        cout << convertTime(endTimeMap[tp]) << endl;
    }
    return 0;
}
