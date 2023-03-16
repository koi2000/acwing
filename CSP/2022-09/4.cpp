//
// Created by DELL on 2022/6/7.
//
#include <bits/stdc++.h>

#define ll long long
using namespace std;
#define pii pair<int,int>
#define INF 0x3f3f3f3f
const int N = 10000;
// 映射回作品真正的ID
map<int, int> mp;

struct cmp {
    bool operator()(const pair<ll, int> &a, const pair<ll, int> &b) const {
        if (a.first == b.first)return a.second < b.second;
        return a.first > b.first;
    }
};

int f[200010], p[200010];
int tot;

int finds(int x) {
    if (f[x] == x)return x;
    f[x] = finds(f[x]);
    return f[x];
}

void unions(int x, int y) {
    int fx = finds(x);
    int fy = finds(y);
    f[fx] = fy;
}

ll n;
int m, q;
// 记录每个作品的票数
map<int, ll> cnt;
// 维护现有的段，<右端点，<左端点，id>>
set<pair<ll, pair<ll, int>>> seg;
// 维护当前各个作品的得票数排名
set<pair<ll, int>, cmp> heap;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> q;
    tot = m;
    for (int i = 1; i <= max(2 * q, 2 * m); ++i) {
        f[i] = p[i] = i;
    }
    for (int i = 1; i <= m; ++i) {
        mp[i] = i;
    }
    cnt[0] = n;
    seg.insert(make_pair(n, make_pair(1, 0)));
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int l, r, x;
            cin >> l >> r >> x;
            int rx = p[x];
            auto bg = seg.lower_bound(make_pair(l, make_pair(0, rx)));
            auto ed = seg.lower_bound(make_pair(r, make_pair(0, rx)));
            if (bg != seg.end()) {
                ll a, b;
                int c, rc;
                vector<pair<ll, pair<ll, int>>> add;
                // 删除bg和ed之间的端，这一段都被覆盖了
                for (auto it = bg; it != seg.end(); it++) {
                    b = it->first;
                    a = it->second.first;
                    c = it->second.second;
                    // 找到这一段真正的作品id
                    rc = finds(c);
                    // 更新投了rc的数量
                    heap.erase(make_pair(cnt[rc], rc));

                    cnt[rc] -= (b - a + 1);
                    if (rc && cnt[rc] > 0) {
                        heap.insert(make_pair(cnt[rc], rc));
                    }
                    if (it == ed)break;
                }
                b = bg->first;
                a = bg->second.first;
                c = bg->second.second;
                rc = finds(c);
                // 开头的第一段可能没有被完全覆盖
                // 需要新补充一段
                if (a <= l - 1 && l <= b) {
                    heap.erase(make_pair(cnt[rc], rc));
                    cnt[rc] += (l - a);
                    if (rc && cnt[rc] > 0) {
                        heap.insert(make_pair(cnt[rc], rc));
                    }
                    add.push_back(make_pair(l - 1, make_pair(a, rc)));
                }
                // 结尾没有覆盖完，需要新增加一段
                if (ed != seg.end()) {
                    b = ed->first;
                    a = ed->second.first;
                    c = ed->second.second;
                    rc = finds(c);
                    if (a <= r && r + 1 <= b) {
                        heap.erase({cnt[rc], rc});
                        cnt[rc] += (b - r);
                        if (rc && cnt[rc] > 0)
                            heap.insert(make_pair(cnt[rc], rc));
                        add.push_back(make_pair(b, make_pair(r + 1, rc)));
                    }
                }
                if (ed != seg.end())ed = next(ed);
                seg.erase(bg, ed);
                for (auto ad: add) seg.insert(ad);
                seg.insert(make_pair(r, make_pair(l, rx)));
                heap.erase(make_pair(cnt[rx], rx));
                cnt[rx] += (r - l + 1);
                heap.insert(make_pair(cnt[rx], rx));
            }
        } else if (op == 2) {
            int x, w;
            cin >> x >> w;
            heap.erase(make_pair(cnt[p[x]], p[x]));
            heap.erase(make_pair(cnt[p[w]], p[w]));
            cnt[p[w]] += cnt[p[x]];
            if (p[w])heap.insert(make_pair(cnt[p[w]], p[w]));
            // 将x合并到w中
            unions(p[x], p[w]);
            // 给x一个新身份id（原来的已经被合并到w了，再用就会出错）
            p[x] = ++tot;
            mp[tot] = x;
        } else if (op == 3) {
            int x, y;
            cin >> x >> y;
            swap(mp[p[x]], mp[p[y]]);
            swap(p[x], p[y]);
        } else if (op == 4) {
            int w;
            cin >> w;
            w = p[w];
            cout << cnt[w] << endl;
        } else {
            if (heap.size() == 0)cout << 0 << endl;
            else {
                int ans = 0;
                int ans_id = 0;
                for (auto it:heap) {
                    if (it.first > ans) {
                        ans = it.first;
                        ans_id = mp[it.second];
                    }
                    if (it.first == ans && mp[it.second] < ans_id) {
                        ans_id = mp[it.second];
                    }
                    if (ans > it.second)break;
                }
                cout << ans_id << endl;
            }
        }
    }

    return 0;
}
