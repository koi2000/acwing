//
// Created by csp on 22-6-12.
//
#include <bits/stdc++.h>

#define ll long long
#define lowbit(x) (x & -x)
using namespace std;
const int maxn = 1e6 + 10;

int dir[4][2] = {
        {1,  0},
        {0,  1},
        {-1, 0},
        {0,  -1}
};

int d = 0;

class line {
public:
    int x1, x2, y1, y2;
    double a;
    int type;

    int ctx;
    int cty;

    line(int x1, int x2, int y1, int y2, int a) : x1(x1), x2(x2), y1(y1), y2(y2), a(a) {
        if (y1 > y2) {
            swap(y1, y2);
            swap(x1, x2);
        }
        if (x2 > x1) {
            type = 1;
        } else {
            type = 2;
        }
    }

    int isLove(int x, int y, int t) {
        ctx = -1;
        cty = -1;
        if (d == 0) {
            if (type == 1) {
                if (x2 > x && (y >= y1 && y <= y2)) {
                    ctx = (y - y1) + x1;
                    cty = y;
                    d = 1;
                    return t - (ctx - x);
                }
            } else {
                if (x1 > x && (y >= y1 && y <= y2)) {
                    ctx = (y - y1) + x2;
                    cty = y;
                    d = 3;
                    return t - (ctx - x);
                }
            }
        } else if (d == 1) {
            if (type == 1) {
                if ((x >= x1 && x <= x2) && y <= y2) {
                    ctx = x;
                    cty = (x - x1) + y1;
                    d = 0;
                    return t - (cty - y);
                }
            } else {
                if ((x >= x2 && x <= x1) && y <= y2) {
                    ctx = x;
                    cty = (x - x2) + y1;
                    d = 2;
                    return t - (cty - y);
                }
            }
        } else if (d == 2) {
            if (type == 1) {
                if (x1 < x && (y >= y1 && y <= y2)) {
                    ctx = (y - y1) + x1;
                    cty = y;
                    d = 3;
                    return t - abs(ctx - x);
                }
            } else {
                if (x2 < x && (y >= y1 && y <= y2)) {
                    ctx = (y - y1) + x2;
                    cty = y;
                    d = 1;
                    return t - abs(ctx - x);
                }
            }
        } else if (d == 3) {
            if (type == 1) {
                if ((x >= x1 && x <= x2) && y <= y2) {
                    ctx = x;
                    cty = (x - x1) + y1;
                    d = 2;
                    return t - abs(cty - y);
                }
            } else {
                if ((x >= x2 && x <= x1) && y <= y2) {
                    ctx = x;
                    cty = (x - x2) + y1;
                    d = 0;
                    return t - abs(cty - y);
                }
            }
        }
    }
};

struct cmp0 {
    bool operator()(const line &l1, const line &l2) {
        return l1.x1 < l2.x1;
    }
};

struct cmp1 {
    bool operator()(const line &l1, const line &l2) {
        return l1.y1 < l2.y1;
    }
};

struct cmp2 {
    bool operator()(const line &l1, const line &l2) {
        return l1.x1 < l2.x1;
    }
};

struct cmp3 {
    bool operator()(const line &l1, const line &l2) {
        return l1.x1 < l2.x1;
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int m;
    cin >> m;
    int op;
    vector<line> lines;
    map<int, int> no2idx;
    int idx = 0;
    for (int i = 0; i < m; ++i) {
        cin >> op;
        if (op == 1) {
            int x1, y1, x2, y2;
            double a;
            cin >> x1 >> y1 >> x2 >> y2;
            cin >> a;
            lines.emplace_back(x1, y1, x2, y2, a);
            no2idx[i] = idx;
            idx++;
        }
        if (op == 2) {
            int k;
            cin >> k;
            lines.erase(lines.begin() + no2idx[k]);
        }
        if (op == 3) {
            int x, y;
            int I;
            int t;
            cin >> x >> y >> d >> I >> t;

            while (true) {
                int flag = 0;
                for (int j = 0; j < lines.size(); ++j) {
                    int pd = d;
//                    if (d == 0) {
//                        sort(lines.begin(), lines.end());
//                    } else if (d == 1) {
//
//                    } else if (d == 2) {
//
//                    } else {
//
//                    }
                    int res = lines[j].isLove(x, y, t);
                    if (res > 0) {
                        I *= lines[j].a;
                        flag = 1;
                        x = lines[j].ctx;
                        y = lines[j].cty;
                        t = res;
                        break;
                    } else {
                        if (d != pd) {
                            x += t * dir[d][0];
                            y += t * dir[d][1];
                            break;
                        }
                        continue;
                    }
                }
                if (I == 0 || flag == 0) {
                    break;
                }
            }
            if (I == 0) {
                cout << 0 << " " << 0 << " " << 0 << endl;
            } else {
                cout << x << " " << y << " " << I << endl;
            }
        }

    }

    return 0;
}