//
// Created by DELL on 2022/6/7.
//
#include <bits/stdc++.h>

#define ll long long
using namespace std;

struct point {
public:
    int id;
    double x, y;
};
point u;

double distance(point x, point y) {
    return pow((x.x - y.x), 2) + pow((x.y - y.y), 2);
}

bool cmp(point x, point y) {
    if (distance(u, x) == distance(y, u)) {
        return x.id < y.id;
    }
    return distance(u, x) < distance(u, y);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    cin >> u.x >> u.y;
    vector<point> ps(n);
    for (int i = 0; i < n; ++i) {
        cin >> ps[i].x >> ps[i].y;
        ps[i].id = i + 1;
    }
    sort(ps.begin(), ps.end(), cmp);
    for (int i = 0; i < 3; ++i) {
        cout << ps[i].id << endl;
    }
    return 0;
}
