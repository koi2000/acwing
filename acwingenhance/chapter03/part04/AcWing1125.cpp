#include <bits/stdc++.h>
using namespace std;
#define MAXN 99999999
struct city {
  int x, y;
} p[200];
double step[200][200], Maxstep[200], ans1, ans2 = MAXN;
int n, m, Maps[200][200];
char Map;
void F() {
  for (int k = 1; k <= n; k++)
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
        if (step[i][j] > step[i][k] + step[k][j])
          step[i][j] = step[i][k] + step[k][j];
}
double len(int x1, int y1, int x2, int y2) {
  return sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    scanf("%d %d", &p[i].x, &p[i].y);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      cin >> Map;
      Maps[i][j] = Map - '0';
    }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      if (Maps[i][j])
        step[i][j] = len(p[i].x, p[i].y, p[j].x, p[j].y);
      else if (i != j)
        step[i][j] = MAXN;
    }
  F();
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      if (step[i][j] != MAXN)
        Maxstep[i] = max(step[i][j], Maxstep[i]);
      ans1 = max(ans1, Maxstep[i]);
    }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      if (step[i][j] == MAXN)
        ans2 =
            min(Maxstep[i] + len(p[i].x, p[i].y, p[j].x, p[j].y) + Maxstep[j],
                ans2);
  double ans = max(ans1, ans2);
  printf("%.6lf", ans);
  return 0;
}