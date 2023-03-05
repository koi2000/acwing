//
// Created by DELL on 2022/6/7.
//
#include <bits/stdc++.h>

#define ll long long
using namespace std;

static unsigned long nxt = 1;

/* RAND_MAX assumed to be 32767 */
int myrand(void) {
    nxt = nxt * 1103515245 + 12345;
    return ((unsigned) (nxt / 65536) % 32768);
}

double dt;

class neu {
public:
    double u, v, a, b, c, d;

    neu() {}

    neu(int u, int v, int a, int b, int c, int d) : u(u), v(v), a(a), b(b), c(c), d(d) {}

    void update(double Ik) {
        double uk = u;
        double vk = v;
        u = vk + dt * (0.04 * vk * vk + 5 * vk + 140 - uk) + Ik;
        v = uk + dt * a * (b * vk - uk);
        if (vk > 30) {
            emit();
        }
    };

    void emit() {
        v = c;
        u += d;


    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, s, p, t;
    cin >> n >> s >> p >> t;

    cin >> dt;
    int RN = 0;
    while (true) {
        cin >> RN;
        int u, v, a, b, c, d;
        cin >> u >> v >> a >> b >> c >> d;


        n -= RN;
        if (n == 0) {
            break;
        }
    }

    return 0;
}
