#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;
const int M = 1e4 + 10;
int m, Tdef, Tmax, Tmin, n;
string h;
struct IP {
    int state;//0:未分配；1:待分配；2:占用；3:过期
    int t;//过期时间
    string owner;//占有者
} ip[M];//类型

//更新地址池
void update_ips_state(int tc) {
    for (int i = 1; i <= n; i++) {
        //ip地址有一个大于0的过期时刻，并且在当前时间已经过期
        if (ip[i].t > 0 && ip[i].t <= tc) {
            //如果地址是待分配
            if (ip[i].state == 1) {
                ip[i].state = 0;//状态变为未分配
                ip[i].t = 0;//过期时刻清零
                ip[i].owner = "";//占用者清空
            } else {
                ip[i].state = 3;//状态变为过期
                ip[i].t = 0;//过期时刻清零
            }
        }
    }
}

//检查是否有占用者为发送主机的ip
int get_ip_by_owner(string client) {
    for (int i = 1; i <= n; i++) {
        if (ip[i].owner == client)
            return i;
    }
    return 0;
}

//选取特定状态的ip地址
int get_ip_by_state(int state) {
    for (int i = 1; i <= n; i++) {
        if (ip[i].state == state)
            return i;
    }
    return 0;
}

int main() {
    cin >> n >> Tdef >> Tmax >> Tmin >> h;//Tdef默认过期时间长度；Tmax最长过期时间；Tmin最短过期时间；H主机名
    cin >> m;
    while (m--) {
        int tc;//当前时间
        string client, server, type;//发送主机，接受主机，类型
        int id, te;//地址，过期时刻
        cin >> tc >> client >> server >> type >> id >> te;
        //按照处理细节进行处理
        if (server != h && server != "*") {
            if (type != "REQ")continue;
        }
        if (type != "DIS" && type != "REQ")continue;
        if ((server == "*" && type != "DIS") || (server == h && type == "DIS"))continue;
        update_ips_state(tc);//更新时间池，传入当前时刻

        //按照实现细节，处理两种类型的报文
        if (type == "DIS") {
            //1.检查是否有占用者为发送主机的ip地址
            //如果有，则选取该ip地址
            int k = get_ip_by_owner(client);
            //如果没有，则选取最小状态为未分配的ip地址
            if (!k) k = get_ip_by_state(0);
            //如果没有，则选取最小状态为过期的ip地址
            if (!k) k = get_ip_by_state(3);
            //如果没有，则不处理该报文
            if (!k)continue;
            //2.将ip地址设置为待分配，占用者设置为发送主机
            ip[k].state = 1;
            ip[k].owner = client;
            //3.
            //如果报文过期时刻为0，则设置过期时刻为t+Tdef
            if (te == 0) {
                ip[k].t = tc + Tdef;
            } else {
                int t = te - tc;
                //t不能小于最低时间也不能大于最长时间
                t = max(t, Tmin);
                t = min(t, Tmax);
                ip[k].t = tc + t;//更新过期时间
            }
            //发送报文
            cout << h << " " << client << " " << "OFR " << k << " " << ip[k].t << endl;
        } else {
            //1.如果接受主机不是本机
            if (server != h) {
                for (int i = 1; i <= n; i++) {
                    //占用者为发送主机，状态为待分配
                    if (ip[i].owner == client && ip[i].state == 1) {
                        ip[i].state = 0;//状态设置为未分配
                        ip[i].owner = "";//占用者清空
                        ip[i].t = 0;//清零过期时刻
                    }
                }
                continue;
            }
            //2.检查ip地址是否在地址池中，且占有者为发送主机
            if (!(id >= 1 && id <= n && ip[id].owner == client)) {
                cout << h << " " << client << " " << "NAK " << id << " " << 0 << endl;
            } else {
                //3.将该ip地址设置为占用
                ip[id].state = 2;
                //4.设置过期时刻
                if (te == 0) {
                    ip[id].t = tc + Tdef;
                } else {
                    int t = te - tc;
                    //t不能小于最低时间也不能大于最长时间
                    t = max(t, Tmin);
                    t = min(t, Tmax);
                    ip[id].t = tc + t;//更新过期时间
                }
                cout << h << " " << client << " " << "ACK" << " " << id << " " << ip[id].t << endl;
            }
        }
    }
    return 0;
}
