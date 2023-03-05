#include <iostream>
#include <cstdio>
#include <cmath>

int isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2, l = (int) sqrt(n); i <= l; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int n, d;
    while (scanf("%d", &n) != EOF) {
        if (n < 0) break;
        scanf("%d", &d);
        if (isPrime(n) == false) {
            printf("No\n");
            continue;
        }
        int a[100], len = 0;
        do {
            a[len++] = n % d;
            n /= d;
        } while (n != 0);
        for (int i = 0; i < len; i++)
            n = n * d + a[i];
        printf(isPrime(n) ? "Yes\n" : "No\n");
    }
    return 0;
}
