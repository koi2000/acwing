#include<bits/stdc++.h>

#define ll long long
#define pii pair<int,int>
using namespace std;

struct state {
    vector<int>board;
    int dept;
    int p0;
    int cost;
    int val;
    struct state* father;

//    state()  {
//        board = vector<int>();
//    }
};


int main() {
    ios::sync_with_stdio(false);
    vector<int>start = { 1,3,2,4,5,6,7,8,0 };
    state* now = new state();
    for (int i = 0; i < 9; i++) {
        (now->board).push_back(start[i]);
    }

    return 0;
}
