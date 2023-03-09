#include<bits/stdc++.h>

#define ll long long
#define pii pair<int,int>
#define lowbit(x) (x & -x)
using namespace std;

const int maxn = 1E6+10;

ll s[maxn];
// 传统的树状数组可以解决区间查询和单点修改
// 转变为差分建树可以实现区间修改和单点查询
// 如果想要实现区间查询和区间修改可以结合上面建两棵树
void upd(ll p,ll x) {
    for (int i = p; i <= maxn; i+=lowbit(i)) {
        s[i]+=x;
    }
}

ll ask(int p){
    ll res= 0;
    for (int i = p; i >=1 ; i-=lowbit(i)) {
        res+=s[i];
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    return 0;
}
