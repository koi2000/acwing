//
// Created by DELL on 2023/10/31.
//
#include <bits/stdc++.h>
using namespace std;

// ----------------------- 数据生成函数 --------------------------------------
auto rand_t = bind(uniform_int_distribution<int>(100, 1000), mt19937(time(0)));
auto rand_n = bind(uniform_int_distribution<int>(30000, 50000), mt19937(time(0)));
auto rand_m =
    bind(uniform_int_distribution<int>(1000, 1000000), mt19937(time(0)));
auto rand_x = bind(uniform_int_distribution<int>(-1e8, 1e8), mt19937(time(0)));

void gen() {
  set<int> st;
  int n = rand_n();
  int m = rand_n();
  for (int i = 0; i < n; ++i) {
    int num = rand_m();
    st.insert(num);
  }
  int key;
  cout << st.size() << " " << m << endl;
  for (int num : st) {
    cout << num << " ";
  }
  cout << "\n";
  for (int i = 0; i < m; ++i) {
    if (rand_t() >= 700) {
      key = rand_m();
    } else {
      int offset = 4 * st.size() / 5 + rand_m() % (int)(1 * st.size() / 5);
      auto it = st.begin();
      while (offset--) {
        it++;
      }
      key = *it;
    }
    cout << key << " ";
  }
}

// --------------------- 题解 -----------------------------------------------
int search(int *arr, int key, int length) {
  int head = 0, tail = length, mid;
  while (head <= tail) {
    mid = (head + tail) / 2;
    if (key == arr[mid])
      return mid;
    else if (key > arr[mid])
      head = mid + 1;
    else
      tail = mid - 1;
  }
  return -1;
}

void solve() {
  int n, m;
  scanf("%d %d", &n, &m);
  int arr[n];
  int target[m];
  for (int i = 0; i < n; ++i) {
    scanf("%d", &arr[i]);
  }
  for (int i = 0; i < m; ++i) {
    scanf("%d", &target[i]);
  }
  for (int i = 0; i < m; ++i) {
    printf("%d\n", search(arr, target[i], n));
  }
}

// --------------------------------- 下面可以不用关注 -------------------------
int main() {
  for (int i = 1; i <= 5; i++) {
    stringstream stream;
    stream << i << ".in";
    string fileName;
    stream >> fileName;
    stringstream stream2;
    stream2 << i << ".out";
    string fileName2;
    stream2 >> fileName2;
    // 生成
    freopen(fileName.c_str(), "w", stdout);
    gen();
    // 输出
    freopen(fileName.c_str(), "r", stdin);
    freopen(fileName2.c_str(), "w", stdout);
    solve();
  }
  return 0;
}