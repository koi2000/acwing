#include<bits/stdc++.h>

#define ll long long
#define pii pair<int,int>
using namespace std;
const int N = 100010;
int n;
int arr[N];

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    map<int, int> st;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        if (st.count(arr[i])) {
            st[arr[i]]++;
        } else {
            st[arr[i]] = 1;
        }
    }
    int res = 0;
    for (int i = 0; i < n; ++i) {
        if (!st.count(i)) {
            if (!st.empty() && st.begin()->first > i) {
                break;
            }
            set<int> tp;
            for (int j = 0; j < i; ++j) {
                tp.insert(j);
            }
            for (int j = 0; j < n; ++j) {
                if (tp.count(arr[j])) {
                    tp.erase(arr[j]);
                    continue;
                }
                if (arr[j] < i) {
                    arr[j] = i;
                    res = i;
                    if (st[arr[j]] > 1) {
                        st[arr[j]]--;
                    } else {
                        st.erase(arr[j]);
                    }
                    break;
                }
            }
        } else {
            res = i;
        }
    }
    cout << res + 1 << endl;
    return 0;
}
