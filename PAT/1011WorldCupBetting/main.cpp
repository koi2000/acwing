#include <iostream>
#include <cstdio>

int main() {
    double res = 0.65;
    char symbol[] = {'W', 'T', 'L'};
    for (int i = 0; i < 3; i++) {
        int maxJ = -1;
        double t, maxN = -1.;
        for (int j = 0; j < 3; j++) {
            scanf("%lf", &t);
            if (t > maxN) {
                maxN = t;
                maxJ = j;
            }
        }
        res *= maxN;
        printf("%c ", symbol[maxJ]);
    }
    printf("%.2lf", (res - 1.) * 2.);
    return 0;
}
