#include <cstdio>

int main() {
    int n, last = 0, total = 0, current;
    scanf("%d", &n);
    while (n-- > 0) {
        scanf("%d", &current);
        if (current > last) {
            total += 6 * (current - last) + 5;
        } else {
            total += 4 * (last - current) + 5;

        }
        last = current;
    }
    printf("%d", total);
    return 0;
}
