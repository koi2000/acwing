#include "bits/stdc++.h"

#define ll long long
using namespace std;
const int N = 1e5 + 10;
struct brNode {
    brNode *l;
    brNode *r;
    int val;
};
vector<int> nodes[N];
int n;

int dfs(int node) {
    int count = 0;
    if (nodes[node].size() == 0)return 0;
    for (int i = 0; i < nodes[node].size(); ++i) {
        count = max(count, dfs(nodes[node][i]));
    }
    return count + nodes[node].size();
}

void build(brNode *root) {
    if (!root) {
        return;
    }
    int node = root->val;
    if (nodes[node].size() == 0) {
        return;
    }
    root->l = new brNode();
    root->l->val = nodes[node][0];
    brNode *head = new brNode();
    brNode *r = new brNode();
    head->r = r;
    for (int i = 1; i < nodes[node].size(); ++i) {
        r->val = nodes[node][i];
        r->l = nullptr;
        if (i != nodes[node].size() - 1) {
            r->r = new brNode();
            r = r->r;
        } else {
            r->r = nullptr;
        }

    }
    if (nodes[node].size() > 1) {
        root->r = head->r;
    } else {
        root->r = nullptr;
    }
    build(root->l);
    build(root->r);
}


int main() {
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int fa;
        cin >> fa;
        nodes[fa].push_back(i + 2);
    }
    cout << dfs(1);
    brNode *root = new brNode();
    root->val = 1;
    build(root);
    return 0;
}
