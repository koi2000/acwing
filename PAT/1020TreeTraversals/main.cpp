#include "bits/stdc++.h"

#define ll long long
using namespace std;
const int maxn = 1e6 + 10;
vector<int> postorder;
vector<int> midorder;
vector<int> res;

class node {
public:
    int v;
    node *l;
    node *r;

    node(int v) : v(v) {}
};

node *build(vector<int> post, vector<int> mid) {
    if (post.empty() || mid.empty())return nullptr;
    int root = *post.rbegin();
    int idx = 0;
    for (int i = 0; i < mid.size(); ++i) {
        if (mid[i] == root) {
            idx = i;
            break;
        }
    }
    vector<int> lmid(mid.begin(), mid.begin() + idx);
    vector<int> rmid(mid.begin() + idx + 1, mid.end());

    vector<int> lpost(post.begin(), post.begin() + idx);
    vector<int> rpost(post.begin() + idx, post.end());
    rpost.pop_back();
    node *rt = new node(root);
    rt->l = build(lpost, lmid);
    rt->r = build(rpost, rmid);
    return rt;
}

void levelorder(node *root) {
    if (root == nullptr)return;
    queue<node *> q;
    q.push(root);
    while (!q.empty()) {
        node *rt = q.front();
        q.pop();
        if (rt != nullptr) {
            res.push_back(rt->v);
            q.push(rt->l);
            q.push(rt->r);
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int tp;
        cin >> tp;
        postorder.push_back(tp);
    }
    for (int i = 0; i < N; ++i) {
        int tp;
        cin >> tp;
        midorder.push_back(tp);
    }
    node *root = build(postorder, midorder);
    levelorder(root);
    for (int i = 0; i < res.size(); ++i) {
        if (i != res.size() - 1) {
            cout << res[i] << " ";
        } else {
            cout << res[i];
        }
    }
    return 0;
}
