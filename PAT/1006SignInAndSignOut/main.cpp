#include <iostream>
#include <climits>

using namespace std;

int main() {
    int n, minN = INT_MAX, maxN = INT_MIN;
    scanf("%d", &n);
    string unlocked, locked;
    int in, out;
    for (int i = 0; i < n; i++) {
        string t;
        cin >> t;
        int h1, m1, s1, h2, m2, s2;
        scanf("%d:%d:%d %d:%d:%d", &h1, &m1, &s1, &h2, &m2, &s2);
        in = h1 * 3600 + m1 * 60 + s1;
        out = h2 * 3600 + m2 * 60 + s2;
        if (in < minN) {
            minN = in;
            unlocked = t;
        }
        if (out > maxN) {
            maxN = out;
            locked = t;
        }
    }
    cout << unlocked << " " << locked;
    return 0;
}
