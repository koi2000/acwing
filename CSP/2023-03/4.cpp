//
// Created by csp on 2023/3/19.
//
#include <utility>

#include"bits/stdc++.h"

#define ll long long
#define pii pair<int,int>
using namespace std;
int n, q;
map<ll, ll> ips;

ll ip2ll16(string ip) {
    //string high = ip.substr(0, 4);
    //string low = ip.substr(5, 4);
    string low = std::move(ip);
    ll res = 0;
    int base = 1;
    for (int i = 3; i >= 0; --i) {
        if (isalpha(low[i])) {
            ll tp = low[i] - 'a' + 10;
            res += tp * base;
        } else {
            ll tp = low[i] - '0';
            res += tp * base;
        }
        base *= n;
    }
    return res;
}

ll ip2ll32(string ip) {
    string high = ip.substr(0, 4);
    string low = ip.substr(5, 4);
    ll res = 0;
    int base = 1;
    for (int i = 3; i >= 0; --i) {
        if (isalpha(low[i])) {
            ll tp = low[i] - 'a' + 10;
            res += tp * base;
        } else {
            ll tp = low[i] - '0';
            res += tp * base;
        }
        base *= n;
    }

    for (int i = 3; i >= 0; --i) {
        if (isalpha(high[i])) {
            ll tp = high[i] - 'a' + 10;
            res += tp * base;
        } else {
            ll tp = high[i] - '0';
            res += tp * base;
        }
        base *= n;
    }
    return res;
}

ll ip2ll(string ip) {
    if (n == 16) {
        return ip2ll16(ip);
    } else {
        return ip2ll32(ip);
    }
}

int main() {
    //freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n >> q;
    for (int i = 0; i < q; ++i) {
        int op;
        cin >> op;
        if (op == 1) {
            int usr;
            cin >> usr;
            string low;
            string high;
            cin >> low >> high;
            int cnt = 0;
            bool flag = true;
            ll ilow = ip2ll(low);
            ll ihigh = ip2ll(high);
            for (ll j = ilow; j <= ihigh; ++j) {
                if (ips.count(j)) {
                    if (ips[j] == usr) {
                        cnt++;
                    } else {
                        flag = false;
                        break;
                    }
                }
            }
            if (flag && cnt < (ihigh - ilow)) {
                cout << "YES" << endl;
                for (ll j = ilow; j <= ihigh; ++j) {
                    ips[j] = usr;
                }
            } else {
                cout << "NO" << endl;
            }
        } else if (op == 2) {
            string ip;
            cin >> ip;
            ll ipll = ip2ll(ip);
            if (ips.count(ipll)) {
                cout << ips[ipll] << endl;
            } else {
                cout << 0 << endl;
            }
        } else if (op == 3) {
            string l, r;
            cin >> l >> r;
            set<ll> usr;
            bool flag = true;
            for (ll j = ip2ll(l); j <= ip2ll(r); ++j) {
                if (ips.count(j)) {
                    usr.insert(ips[j]);
                } else {
                    flag = false;
                    break;
                }
                if (usr.size() > 1) {
                    flag = false;
                    break;
                }
            }
            if (!flag) {
                cout << 0 << endl;
            } else {
                cout << *usr.begin() << endl;
            }
        }
    }
    return 0;
}
