#include<bits/stdc++.h>

#define ll long long
using namespace std;
const int N = 2e5 + 10;

int main() {
    int n, k;
    cin >> n >> k;
    set<int> st;
    int res = 0;
    for (int i = 0; i < k; ++i) {
        int l, r;
        cin >> l >> r;
        if (st.count(r) || r == 0) {
        }else{
            res++;
        }
        st.insert(l);
    }
    cout << res << endl;
    return 0;
}