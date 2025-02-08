//
// Created by DELL on 2023/9/4.
//
#include "bits/stdc++.h"
#define ll long long
#define pii pair<int,int>
using namespace std;
int get(string s, int b) {
    int num = 0;
    int n = s.size();
    for (int i = n - 1; i >= 0; --i) {
        num += (s[n - i - 1] - '0') * pow(b, i);
    }
    return num;
}
int main(){
    string bts;
    string tts;
    cin>>bts>>tts;
    unordered_set<int>st;
    for (auto &c:bts) {
        c ^= 1;
        st.insert(get(bts, 2));
        c ^= 1;
    }

    return 0;
}

