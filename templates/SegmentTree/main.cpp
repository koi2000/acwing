//
// Created by DELL on 2023/3/5.
//
#include<bits/stdc++.h>

#define ll long long
#define pii pair<int,int>
using namespace std;
const int N = 1e5 + 10;
int number[N];

struct node {
    int l, r, sum, lazy;

    node() {
        l = r = sum = lazy = 0;
    }
} a[N];

inline void update(int k) {
    a[k].sum = a[k * 2].sum + a[k * 2 + 1].sum;
}

void build(int k, int l, int r) {
    a[k].l = l;
    a[k].r = r;
    if (l == r) {
        a[k].sum = number[l];
        return;
    }
    int mid = (l + r) / 2;
    build(2 * k, l, mid);
    build(2 * k + 1, mid + 1, r);
    update(k);
}

void change(int k, int x, int y) {
    if (a[k].l == a[k].r) {
        a[k].sum = y;
        return;
    }
    int mid = (a[k].l + a[k].r) / 2;
    if (x <= mid) {
        change(2 * k, x, y);
    } else {
        change(2 * k + 1, x, y);
    }
    // 最后更新一下k值
    update(k);
}

void changeSegment(int k, int l, int r, int x) {
    if (a[k].l == l && a[k].r == r) {
        a[k].sum += (r - l + 1) * x;
        a[k].lazy += x;
        return;
    }
    int mid = (a[k].l + a[k].l) / 2;
    if (r <= mid) {
        // 被修改区间全部在左区间
        changeSegment(2 * k, l, r, x);
    } else if (l > mid) {
        // 被修改区间全部在右区间
        changeSegment(2 * k + 1, l, r, x);
    } else {
        // 将要更新的区间分为两段，分别去更新
        changeSegment(2 * k, l, mid, x);
        changeSegment(2 * k + 1, mid + 1, r, x);
    }
    update(x);
}

// 将点k的懒惰标记下传
void pushdown(int k) {
    // 如果节点k已经是叶节点了，没有子节点，那么标记无需下穿
    // 直接删除即可
    if (a[k].l == a[k].r) {
        a[k].lazy = 0;
        return;
    }
    // 更新子节点的值
    a[2 * k].sum += (a[2 * k].r - a[k].l + 1) * a[k].lazy;
    a[2 * k + 1].sum += (a[2 * k + 1].r - a[2 * k + 1].l + 1) * a[k].lazy;
    // 将标记下传到子节点
    a[2 * k].lazy += a[k].lazy;
    a[2 * k + 1].lazy += a[k].lazy;
    a[k].lazy = 0;
}

int query(int k, int l, int r) {
    if (a[k].lazy)pushdown(k);
    if (a[k].l == l && a[k].r == r)return a[k].sum;
    int mid = (a[k].l + a[k].r) / 2;
    if (r <= mid) return query(2 * k, l, r);
    if (l > mid) return query(2 * k + 1, l, r);
    return query(2 * k, l, mid) + query(2 * k + 1, mid + 1, r);
}

int main() {
    ios::sync_with_stdio(false);
    return 0;
}


