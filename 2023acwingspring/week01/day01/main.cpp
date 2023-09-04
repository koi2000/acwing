#include<bits/stdc++.h>

#define ll long long
#define pii pair<int,int>
using namespace std;
string str;
int idx;

void build() {
    if (str[idx] == '#') {
        idx++;
        return;
    }
    char root = str[idx++];
    build();
    cout << root << " ";
    build();
}

int main() {
    ios::sync_with_stdio(false);
    cin >> str;
    build();
    return 0;
}
