#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>

using namespace std;
typedef long long LL;
const LL N = 3e5 + 10;
vector<LL> son[N];
vector<LL> sets[N];
LL a[N];
LL n;

vector<LL> Find(LL x) {
    vector<LL> ans;
    ans.push_back(x);
    if (son[x].size() == 0)
        return ans;
    vector<LL> &t = son[x];
    vector<vector<LL>> s;
    for (LL i = 0; i < t.size(); i++) {
        s.push_back(Find(t[i]));
    }
    for (LL i = 0; i < s.size(); i++) {
        vector<LL> &k = s[i];
        for (LL j = 0; j < k.size(); j++)
            ans.push_back(k[j]);
    }
    sets[x] = ans;
    return ans;
}

//输入x,找到以它为根的树的全部编号
LL Count(vector<LL> v) {
    LL ans = 0;
    vector<LL> s;
    for (LL i = 0; i < v.size(); i++) {
        s.push_back(a[v[i]]);
    }
    if (s.size() == 1)
        return 0;
    sort(s.begin(), s.end());
    LL size = s.size();
    for (LL i = 0; i < size; i++) {
        LL tmp = 0x3f3f3f3f3f3f3f3f;
        if (i + 1 >= 0 && i + 1 < size)
            tmp = min((s[i + 1] - s[i]) * (s[i + 1] - s[i]), tmp);
        if (i - 1 >= 0 && i - 1 < size)
            tmp = min((s[i - 1] - s[i]) * (s[i - 1] - s[i]), tmp);
        ans += tmp;
        //cout<<"----"<<ans<<" "<<tmp<<endl;
    }
    return ans;
}

//给定一个集合,求解集合中元素的G值
int main() {
    scanf("%lld", &n);
    for (LL i = 2; i <= n; i++) {
        LL tmp;
        scanf("%lld", &tmp);
        son[tmp].push_back(i);
    }
    //build tree
    for (LL i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    Find(1);
    for (LL i = 1; i <= n; i++) {
        cout << Count(sets[i]) << endl;
    }
    //cout<<endl;
}
