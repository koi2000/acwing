//
// Created by csp on 2023/3/19.
//
#include"bits/stdc++.h"

#define ll long long
#define pii pair<int,int>
using namespace std;
int n;
// quan bu yong hu
set<int> all;
// shu xing dao yong hu de ying she
map<int, set<pii>> attr2usr;

bool isHighCommand(string command) {
    return !isdigit(command[0]);
}

vector<string> splitCommand(string command) {
    vector<string> ret;
    for (int i = 0; i < command.size(); ++i) {
        if (command[i] == '(') {
            int left = 1;
            for (int j = i + 1; j < command.size(); ++j) {
                if (command[j] == ')') {
                    left--;
                } else if (command[j] == '(') {
                    left++;
                }
                if (left == 0) {
                    string res = command.substr(i + 1, j - i - 1);
                    ret.push_back(res);
                    i = j;
                    break;
                }
            }
        }
    }
    return ret;
}

int string2int(string str) {
    return atoi(str.c_str());
}

set<int> lowCommand(string command) {
    int idx = -1;
    for (int i = 0; i < command.size(); ++i) {
        if (command[i] == ':' || command[i] == '~') {
            idx = i;
            break;
        }
    }

    int attr = string2int(command.substr(0, idx));
    char op = command[idx];
    int value = string2int(command.substr(idx + 1, command.size() - idx + 1));
    set<int> res;
    set<pii > st = attr2usr[attr];
    if (op == ':') {
        for (pii usr: st) {
            if (usr.first == value) {
                res.insert(usr.second);
            }
        }
    } else {
        for (pii usr: st) {
            if (usr.first != value) {
                res.insert(usr.second);
            }
        }
    }
    return res;
}

set<int> highCommand(string command) {
    char op = command[0];
    vector<string> commands = splitCommand(command);

    set<int> res;
    if (op == '&') {
        res = all;
        for (int i = 0; i < commands.size(); ++i) {
            set<int> tp;
            if (isHighCommand(commands[i])) {
                tp = highCommand(commands[i]);
            } else {
                tp = lowCommand(commands[i]);
            }
            for (auto it = res.begin(); it != res.end();) {
                if (!tp.count(*it)) {
                    res.erase(it++);
                } else {
                    it++;
                }
            }
        }
    } else if (op == '|') {
        for (int i = 0; i < commands.size(); ++i) {
            set<int> tp;
            if (isHighCommand(commands[i])) {
                tp = highCommand(commands[i]);
            } else {
                tp = lowCommand(commands[i]);
            }
            for (auto it: tp) {
                res.insert(it);
            }
        }
    }
    return res;
}


int main() {
    //freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int dn, m;
        cin >> dn >> m;
        for (int j = 0; j < m; ++j) {
            int x, y;
            cin >> x >> y;
            if (attr2usr.count(x)) {
                attr2usr[x].insert({y, dn});
            } else {
                attr2usr[x] = set<pii >();
                attr2usr[x].insert({y, dn});
            }
            all.insert(dn);
        }
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        string command;
        cin >> command;
        set<int> res;
        if (!isHighCommand(command)) {
            res = lowCommand(command);
        } else {
            res = highCommand(command);
        }
        for (auto it: res) {
            cout << it << " ";
        }
        cout << endl;
    }
    return 0;
}