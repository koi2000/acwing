#include <bits/stdc++.h>

#define ll long long
#define pii pair<int, int>
using namespace std;
class P1 {
  public:
    string name;
};

class P2 {
  public:
    P1 p;
};

void set(P2 *p2) {
    P1 p1 = P1();
    p1.name = "222";
    p2->p = p1;
}
int main() {
    ios::sync_with_stdio(false);
    // cout << "Hello,World" << endl;
    P2 *p2 = new P2();
    cout << p2->p.name << endl;
    return 0;
}
