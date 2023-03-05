//
// Created by DELL on 2022/6/7.
//
#include <bits/stdc++.h>

using namespace std;

class user {
public:
    string name;

    set<string> operators;

    set<string> kind;

    set<string> resource;

    vector<string> ruser;

    vector<string> rgroup;

    bool operator<(const user &rhs) const {
        return name < rhs.name;
    }

    bool operator>(const user &rhs) const {
        return rhs < *this;
    }

    bool operator<=(const user &rhs) const {
        return !(rhs < *this);
    }

    bool operator>=(const user &rhs) const {
        return !(*this < rhs);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, q;

    cin >> n >> m >> q;
    //vector<user> users;
    // 双方需要
    map<string, user> name2user;
    map<string, vector<string>> group2user;
    //users.resize(n);
    for (int i = 0; i < n; ++i) {
        string name;
        cin >> name;
        user user;
        user.name = name;
        int nv, no, nn;
        cin >> nv;
        string tp;
        for (int j = 0; j < nv; ++j) {
            cin >> tp;
            user.operators.insert(tp);
        }
        cin >> no;
        for (int j = 0; j < no; ++j) {
            cin >> tp;
            user.kind.insert(tp);
        }
        cin >> nn;
        for (int j = 0; j < nn; ++j) {
            cin >> tp;
            user.resource.insert(tp);
        }
        name2user[name] = user;
    }
    for (int i = 0; i < m; ++i) {
        string name;
        int ns;
        cin >> name >> ns;
        for (int j = 0; j < ns; ++j) {
            string op, rel;
            cin >> op >> rel;
            if (op == "g") {
                // 将user插入到gruop中
                group2user[rel].push_back(name);
                // 将group插入到user中
                name2user[name].rgroup.push_back(rel);
            } else {
                // 将关联用户插入其中
                name2user[name].ruser.push_back(rel);
                name2user[rel].ruser.push_back(name);
            }
        }
    }
    for (int i = 0; i < q; ++i) {
        string name;
        int ng;
        cin >> name >> ng;
        string cop, ckind, cres;

        user u = user(name2user[name]);
        for (int j = 0; j < ng; ++j) {
            string gname;
            cin >> gname;
            u.rgroup.push_back(gname);
        }
        cin >> cop >> ckind >> cres;
        // 组织所有关联到的用户
        //set<user> all;
        //all.insert(u);
        int flag = 0;
        for (const string &str:u.ruser) {
            user uu = name2user[str];
            if (!(uu.operators.count("*") || uu.operators.count(cop))) {
                //cout << 0 << endl;
                continue;
            }
            if (!(uu.kind.count("*") || uu.kind.count(ckind))) {
                //cout << 0 << endl;
                continue;
            }
            if (!(uu.resource.count(cres) || uu.resource.empty())) {
                //cout << 0 << endl;
                continue;
            }
            flag = 1;
            break;
        }
        if (flag) {
            cout << flag << endl;
            continue;
        }
        // 将关联到的组也加入
        for (const string &str:u.rgroup) {
            for (const string &ustr:group2user[str]) {
                user uu = name2user[ustr];
                if (!(uu.operators.count("*") || uu.operators.count(cop))) {
                    //cout << 0 << endl;
                    continue;
                }
                if (!(uu.kind.count("*") || uu.kind.count(ckind))) {
                    //cout << 0 << endl;
                    continue;
                }
                if (!(uu.resource.count(cres) || uu.resource.empty())) {
                    //cout << 0 << endl;
                    continue;
                }
                flag = 1;
                break;
            }
            if (flag) {
                break;
            }
        }

//        for (const user &uu:all) {
//            if (!(uu.operators.count("*") || uu.operators.count(cop))) {
//                //cout << 0 << endl;
//                continue;
//            }
//            if (!(uu.kind.count("*") || uu.kind.count(ckind))) {
//                //cout << 0 << endl;
//                continue;
//            }
//            if (!(uu.resource.count(cres) || uu.resource.empty())) {
//                //cout << 0 << endl;
//                continue;
//            }
//            flag = 1;
//            break;
//        }
        cout << flag << endl;
    }

    return 0;
}
