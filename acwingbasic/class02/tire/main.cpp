//#include "bits/stdc++.h"
//
//#define ll long long
//using namespace std;
//
//int main() {
//    ios::sync_with_stdio(false);
//    int N;
//    cin >> N;
//    map<string, int> mp;
//    for (int i = 0; i < N; ++i) {
//        char op;
//        string str;
//        cin >> op >> str;
//        if (op == 'I') {
//            if (mp.count(str)) {
//                mp[str]++;
//            } else {
//                mp[str] = 1;
//            }
//        }
//        if (op == 'Q') {
//            cout << mp[str] << endl;
//        }
//    }
//    return 0;
//}
#include <iostream>

using namespace std;

const int N = 100010;

int son[N][26], cnt[N], idx;
char str[N];

void insert(char *str)
{
    int p = 0;
    for (int i = 0; str[i]; i ++ )
    {
        int u = str[i] - 'a';
        if (!son[p][u]) son[p][u] = ++ idx;
        p = son[p][u];
    }
    cnt[p] ++ ;
}

int query(char *str)
{
    int p = 0;
    for (int i = 0; str[i]; i ++ )
    {
        int u = str[i] - 'a';
        if (!son[p][u]) return 0;
        p = son[p][u];
    }
    return cnt[p];
}

int main()
{
    int n;
    scanf("%d", &n);
    while (n -- )
    {
        char op[2];
        scanf("%s%s", op, str);
        if (*op == 'I') insert(str);
        else printf("%d\n", query(str));
    }

    return 0;
}