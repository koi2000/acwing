#include <iostream>
#include <cstdio>

long n, radix, a[1000];
int len = 0;

bool check() {
    for (int i = 0, l = len / 2; i < l; i++) {
        if (a[i] != a[len - i - 1]) return false;
    }
    return true;
}

int main() {
    scanf("%ld %ld", &n, &radix);
    if (n > 0) {
        while (n > 0) {
            a[len++] = n % radix;
            n /= radix;
        }
        printf(check() ? "Yes\n" : "No\n");

        // 从高位开始输出
        printf("%ld", a[len - 1]);
        for (int i = len - 2; i >= 0; i--) {
            printf(" %ld", a[i]);
        }
    } else {
        printf("Yes\n0");
    }
    return 0;
}
