#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

#define H 24
#define maxN 1000
using namespace std;
struct Customer {
    string name;
    int M;
    int d;
    int h;
    int m;
    int type;
} customers[maxN];

bool cmp(Customer c1, Customer c2) {
    // 名字同根据名字排序
    if (c1.name != c2.name) {
        return c1.name < c2.name;
    }
    // 月份不同按月份排
    int t = c2.M - c1.M;
    if (t != 0) return t > 0 ? true : false;
    // 日
    t = c2.d - c1.d;
    if (t != 0) return t > 0 ? true : false;
    // 小时
    t = c2.h - c1.h;
    if (t != 0) return t > 0 ? true : false;
    // 分钟
    t = c2.m - c1.m;
    return t > 0 ? true : false;
}

int main() {
    int rate[H + 1], totalRate = 0;
    // 读取每个时段的费用
    for (int i = 0; i < H; i++) {
        scanf("%d", &rate[i]);
        totalRate += rate[i];
    }
    rate[H] = totalRate;

    // 读取通话记录
    int n
    string type;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        cin >> customers[i].name;
        scanf("%d:%d:%d:%d", &customers[i].M, &customers[i].d, &customers[i].h, &customers[i].m);
        cin >> type;
        customers[i].type = type == "on-line" ? 0 : 1;
    }
    // 排序
    sort(customers, customers + n, cmp);

    int n, rate[H + 1], lastMonth = -1, totalRate = 0, total = -1;
    // 初始时total为-1，当前遍历的是第一个用户，没遍历完一个用户，total都被置为0
    string type, lastCustomer = "";
    for (int i = 1; i < n; i++) {
        // 名称相同且当前为off，上一条为on，即为有效记录
        if (customers[i].name == customers[i - 1].name && customers[i].type == 1 && customers[i - 1].type == 0) {
            int
                    d1 = customers[i - 1].d,
                    d2 = customers[i].d,
                    h1 = customers[i - 1].h,
                    h2 = customers[i].h,
                    m1 = customers[i - 1].m,
                    m2 = customers[i].m;
            int cost = m2 * rate[h2] - m1 * rate[h1];
            int minute = m2 - m1;
            // 根据跨天和不跨天两种情况计算时间和费用
            if (customers[i].M > customers[i - 1].M || d2 > d1) {
                minute += (d2 - d1 - 1) * 24 * 60;
                cost += (d2 - d1 - 1) * 60 * rate[H];
                minute += (24 - h1 + h2) * 60;
                for (int h = h1; h < H; h++) {
                    cost += rate[h] * 60;
                }
                for (int h = 0; h < h2; h++) {
                    cost += rate[h] * 60;
                }
            } else {
                minute += (h2 - h1) * 60;
                for (int h = h1; h < h2; h++) {
                    cost += rate[h] * 60;
                }
            }
            // 如果遍历到了另一个人，或者另外一个月份，切换到新的一组
            if (lastCustomer == "" || customers[i].name != lastCustomer || customers[i].M != lastMonth) {
                lastCustomer = customers[i].name;
                lastMonth = customers[i].M;

                // 当前不是第一个组，则输出上一个组的总费用
                if (total != -1) {
                    printf("Total amount: $%.2lf\n", total / 100.);
                }

                // 将总费用计数器重新置为0
                total = 0;

                // 输出费用记录头部
                cout << lastCustomer;
                printf(" %02d\n", lastMonth);
            }
            // 输出一条通话记录
            printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2lf\n", d1, h1, m1, d2, h2, m2, minute, cost / 100.);

            // 累计总费用
            total += cost;
        }
    }
    // 输出最后一个用户的总费用
    printf("Total amount: $%.2lf\n", total / 100.);
    return 0;
}

