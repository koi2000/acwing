//
// Created by DELL on 2022/6/7.
//
// 写的思路优点问题，导致代码很长且时间复杂度也超了
#include "bits/stdc++.h"

#define ll long long
#define pii pair<int,int>
using namespace std;

class message {
public:
    string sender;
    string receiver;
    string type;
    int ip;

    message() {
        this->type = "NULL";
    }

    int time;

    message(const string &sender, const string &receiver, const string &type, const int &ip, const int &time)
            : sender(sender), receiver(receiver), type(type), ip(ip), time(time) {}
};

class DHCP {
public:
    int N, Tdef, Tmax, Tmin;
    string H;
    // 未分配
    set<int> left;
    // 待分配
    set<int> ready;
    // 占用，ip->owner
    set<int> own;

    // 过期
    set<int> delay;

    map<int, string> ip2owner;
    map<int, int> ip2time;

    DHCP(int n, int tdef, int tmax, int tmin, string h) : N(n), Tdef(tdef), Tmax(tmax), Tmin(tmin), H(std::move(h)) {
        for (int i = 1; i <= n; ++i) {
            left.insert(i);
        }
    }

    void update(int tc) {
        for (auto it = ready.begin(); it != ready.end();) {
            int ip = *it;
            if (ip2time.count(ip)) {
                if (tc >= ip2time[ip]) {
                    left.insert(ip);
                    ip2time.erase(ip);
                    ip2owner.erase(ip);
                    ready.erase(it++);
                } else {
                    it++;
                }
            } else {
                it++;
            }
        }
        for (auto it = own.begin(); it != own.end();) {
            int ip = *it;
            if (ip2time.count(ip)) {
                if (tc >= ip2time[ip]) {
                    delay.insert(ip);
                    ip2time.erase(ip);
                    own.erase(it++);
                } else {
                    it++;
                }
            } else {
                it++;
            }
        }
    }

    message handleDis(int t, message msg) {
        int ip = -1;
        for (auto it:ip2owner) {
            if (it.second == msg.sender) {
                ip = it.first;
            }
        }
        if (ip == -1) {
            if (!left.empty()) {
                ip = *left.begin();
                left.erase(ip);
            } else if (!delay.empty()) {
                ip = *delay.begin();
                delay.erase(ip);
            } else {
                return message();
            }
        }
        ready.insert(ip);
        ip2owner[ip] = msg.sender;
        int time;
        if (msg.time == 0) {
            time = t + Tdef;
        } else {
            if (msg.time >= t + Tmax) {
                time = t + Tmax;
            } else if (msg.time <= t + Tmin) {
                time = t + Tmin;
            } else {
                time = msg.time;
            }
        }
        ip2time[ip] = time;
        return message(H, msg.sender, "OFR", ip, time);
    }

    message handleReq(int t, message msg) {
        if (msg.receiver != H) {
            for (auto it = ip2owner.begin(); it != ip2owner.end();) {
                if (it->second == msg.sender) {
                    int ip = it->first;
                    if (ready.count(ip)) {
                        left.insert(ip);
                        ip2owner.erase(it++);
                        ip2time.erase(ip);
                    }
                } else {
                    it++;
                }
            }
            return message();
        }
        if (ip2owner.count(msg.ip) && ip2owner[msg.ip] == msg.sender) {
            int ip = msg.ip;
            if (left.count(ip))left.erase(ip);
            if (delay.count(ip))delay.erase(ip);
            if (ready.count(ip))ready.erase(ip);
            own.insert(ip);

            int time;
            if (msg.time == 0) {
                time = t + Tdef;
            } else {
                if (msg.time >= t + Tmax) {
                    time = t + Tmax;
                } else if (msg.time <= t + Tmin) {
                    time = t + Tmin;
                } else {
                    time = msg.time;
                }
            }
            ip2time[msg.ip] = time;
            return message(H, msg.sender, "ACK", msg.ip, time);
        } else {
            return message(H, msg.sender, "NAK", msg.ip, 0);
        }
    }

    message response(int t, message msg) {
        update(t);
        //if (msg.receiver != H&& msg.type=="REQ") return handleReq(t,msg);
        if (msg.receiver != "*" && msg.receiver != H && msg.type != "REQ") return message();
        if (msg.type != "DIS" && msg.type != "REQ")return message();
        if (msg.receiver == "*" && msg.type != "DIS")return message();
        if (msg.receiver == H && msg.type == "DIS")return message();

        if (msg.type == "DIS") {
            return handleDis(t, msg);
        } else {
            return handleReq(t, msg);
        }
    }
};

void output(message msg) {
    if (msg.type == "NULL") return;
    cout << msg.sender << " " << msg.receiver << " "
         << msg.type << " " << msg.ip << " " << msg.time << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, Tdef, Tmax, Tmin;
    string H;
    cin >> N >> Tdef >> Tmax >> Tmin >> H;
    DHCP dhcp = DHCP(N, Tdef, Tmax, Tmin, H);
    int n;
    cin >> n;
    string sender;
    string receiver;
    string type;
    int ip;
    int time;
    for (int i = 0; i < n; ++i) {
        int t;
        cin >> t;
        cin >> sender >> receiver >> type >> ip >> time;
        message msg = message(sender, receiver, type, ip, time);
        message res = dhcp.response(t, msg);
        output(res);
    }
    return 0;
}
