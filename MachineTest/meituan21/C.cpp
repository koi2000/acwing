#include<bits/stdc++.h>

#define ll long long
#define pii pair<int,int>
using namespace std;
int n, m;
string now, que;

//int locate(char sex) {
//    if (sex == 'F') {
//        int loc = -1;
//        for (int i = 0; i < now.size(); ++i) {
//            if (now[i] == '2')continue;
//            if (now[i] == '0') {
//                loc = i + 1;
//                now[i] = '1';
//                break;
//            }
//        }
//        if (loc == -1) {
//            for (int i = 0; i < now.size(); ++i) {
//                if (now[i] == '2')continue;
//                if (now[i] == '1') {
//                    loc = i + 1;
//                    now[i] = '2';
//                    break;
//                }
//            }
//        }
//        return loc;
//    } else {
//        int loc = -1;
//        for (int i = 0; i < now.size(); ++i) {
//            if (now[i] == '2')continue;
//            if (now[i] == '1') {
//                loc = i + 1;
//                now[i] = '2';
//                break;
//            }
//        }
//        if (loc == -1) {
//            for (int i = 0; i < now.size(); ++i) {
//                if (now[i] == '2')continue;
//                if (now[i] == '0') {
//                    loc = i + 1;
//                    now[i] = '1';
//                    break;
//                }
//            }
//        }
//        return loc;
//    }
//}

vector<pii > st;

//int locate(char sex) {
//    if (sex == 'F') {
//        auto it = upper_bound(st.beg{0, 0});
//        if (it != st.end()) {
//            it = st.upper_bound({1, 0});
//        }
//        int idx = 0;
//        for(auto &item:st){
//            if (item.first==it->first&&item.second==it->first){
//                st.insert({});
//                st.erase(item);
//            }
//        }
//        return it - st.begin();
//    } else {
//        auto it = st.upper_bound({1, 0});
//        if (it != st.end()) {
//            it = st.upper_bound({0, 0});
//        }else{
//
//        }
//        return it - st.begin();
//    }
//}


int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        cin >> now;
        for (int i = 0; i < now.size(); ++i) {
            st.insert({now[i] - '0', i + 1});
        }

        cin >> m;
        cin >> que;
        for (int i = 0; i < que.size(); i++) {
            // cout << locate(que[i]) << endl;

        }
    }
    return 0;
}
