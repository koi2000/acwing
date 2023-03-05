//
// Created by DELL on 2022/6/7.
//
#include <bits/stdc++.h>

using namespace std;

vector<pair<double, double>> points;

int main() {
    //ios::sync_with_stdio(false);
    //cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    points.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
        double tp1, tp2;
        cin >> tp1 >> tp2;
        points[i] = make_pair(tp1, tp2);
    }
    for (int i = 0; i < q; ++i) {
        int op;
        cin >> op;
        int l, r;
        double a, b, w, y0;
        double p;
        if (op == 1) {
            cin >> l >> r >> a >> b;
            for (int j = l; j <= r; ++j) {
                points[j].first += a;
                points[j].second += b;
            }
        }
        if (op == 2) {
            cin >> l >> r >> a >> b >> p;
            for (int j = l; j <= r; ++j) {
                points[j].first -= a;
                points[j].second -= b;

                double x = points[j].first;
                double y = points[j].second;

                double xx = x * cos(p) - y * sin(p);
                double yy = x * sin(p) + y * cos(p);
                points[j].first = xx;
                points[j].second = yy;

                points[j].first += a;
                points[j].second += b;
            }
        }
        if (op == 3) {
            cin >> l >> r >> a >> b >> w;
            for (int j = l; j <= r; ++j) {
                points[j].first -= a;
                points[j].second -= b;
                points[j].first *= w;
                points[j].second *= w;
                points[j].first += a;
                points[j].second += b;
            }
        }
        if (op == 4) {
            cin >> l >> r >> p >> y0;
            double k = atan(p);
            double bb = y0;
            for (int j = l; j <= r; ++j) {
                double x, y;
                x = points[j].first;
                y = points[j].second;

                double x1 = (y + (1 / k) * x - bb) / ((1 / k) + k);
                double y1 = (k * y + x - k * bb) / ((1 / k) + k) + bb;

                points[j].first = 2 * x1 - x;

                points[j].second = 2 * y1 - y;
            }
        }
        if (op == 5) {
            cin >> l >> r >> p >> y0;

            double k = atan(p);
            double bb = y0;
            for (int j = l; j <= r; ++j) {
                double x, y;
                x = points[j].first;
                y = points[j].second;

                points[j].first = (y + (1 / k) * x - bb) / ((1 / k) + k);
                points[j].second = (k * y + x - k * bb) / ((1 / k) + k) + bb;
            }
        }
        if (op == 6) {
            cin >> l >> r;
            double sumx = 0;
            double sumy = 0;
            for (int j = l; j <= r; ++j) {
                sumx += points[j].first;
                sumy += points[j].second;
            }
            sumx /= (r - l + 1);
            sumy /= (r - l + 1);
            printf("%.5f %.5f\n", sumx, sumy);
        }
        if (op == 7) {
            cin >> l >> r >> a >> b;
            double sum = 0;
            for (int j = l; j <= r; ++j) {
                sum += (points[j].first - a) * (points[j].first - a);
                sum += (points[j].second - b) * (points[j].second - b);
            }
            //cout << sum << endl;
            printf("%.5f\n", sum);
        }
    }

    return 0;
}
