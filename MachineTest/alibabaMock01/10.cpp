#include "bits/stdc++.h"
using namespace std;

int No10_hash(vector<int>& a, vector<int>& b) {
    int n = a.size();
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++) mp[b[i]] = i;
    int len = 0, cur = 0, curi = -1;
    for (int i = 0; i < n; i++) {
        if (mp[a[i]] > curi) cur++;
        else {
            len = max(len, cur);
            cur = 1;
        }
        curi = mp[a[i]];
    }
    len = max(len, cur);
    return n - len;
}

int main() {
    int n;
    cin>>n;
    vector<int> a(n, 0);
    vector<int> b(n, 0);
    for(int i=0; i<n; i++) cin>>a[i];
    for(int i=0; i<n; i++) cin>>b[i];

    cout<<No10_hash(a, b)<<'\n';
    return 0;
}
