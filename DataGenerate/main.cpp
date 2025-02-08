//
// Created by DELL on 2023/10/31.
//
#include <bits/stdc++.h>
using namespace std;

// ----------------------- 数据生成函数 --------------------------------------
auto rand_t = bind(uniform_int_distribution<int>(2, 5), mt19937(time(0)));
auto rand_n = bind(uniform_int_distribution<int>(10, 30), mt19937(time(0)));
auto rand_m = bind(uniform_int_distribution<int>(1, 10), mt19937(time(0)));
auto rand_x = bind(uniform_int_distribution<int>(-1e8, 1e8), mt19937(time(0)));

void gen() {
  int t = rand_t();
  cout << t << endl;
  int row1, col1, row2, col2;
  row1 = rand_m();
  col1 = rand_m();
  cout << row1 << " " << col1 << endl;
  for (int j = 0; j < row1; ++j) {
    for (int k = 0; k < col1; ++k) {
      cout << rand_n() << " ";
    }
    cout << endl;
  }
  for (int i = 0; i < t - 1; ++i) {
    row2 = col1;
    col2 = rand_m();
    cout << row2 << " " << col2 << endl;
    for (int j = 0; j < row2; ++j) {
      for (int k = 0; k < col2; ++k) {
        cout << rand_n() << " ";
      }
      cout << endl;
    }
    col1 = col2;
  }
}

// --------------------- 题解 -----------------------------------------------
#define MAX_ROWS 100
#define MAX_COLS 100
int result[MAX_ROWS][MAX_COLS];
void multiplyMatrices(int A[MAX_ROWS][MAX_COLS], int B[MAX_ROWS][MAX_COLS],
                      int rowsA, int colsA,
                      int rowsB, int colsB) {
  for (int i = 0; i < rowsA; ++i) {
    for (int j = 0; j < colsB; ++j) {
      result[i][j] = 0;
      for (int k = 0; k < colsA; ++k) {
        result[i][j] += A[i][k] * B[k][j];
      }
    }
  }
}

void solve() {
  int N, rowsA, colsA, rowsB, colsB;

  //输入矩阵数
  scanf("%d", &N);

  // 输入矩阵 A 的行列数
  scanf("%d", &rowsA);
  scanf("%d", &colsA);
  int A[MAX_ROWS][MAX_COLS];
  for (int i = 0; i < rowsA; ++i) {
    for (int j = 0; j < colsA; ++j) {
      scanf("%d", &A[i][j]);
    }
  }

  for (int k = 0; k < N - 1; k++) {
    // 输入矩阵 B 的行列数
    scanf("%d", &rowsB);
    scanf("%d", &colsB);

    // 输入矩阵 B
    int B[MAX_ROWS][MAX_COLS];
    for (int i = 0; i < rowsB; ++i) {
      for (int j = 0; j < colsB; ++j) {
        scanf("%d", &B[i][j]);
      }
    }

    // 创建结果矩阵
//    int result[MAX_ROWS][MAX_COLS];

    // 调用矩阵乘法函数
    multiplyMatrices(A, B, rowsA, colsA, rowsB, colsB);

    colsA = colsB;
    for (int i = 0; i < rowsA; i++) {
      for (int j = 0; j < colsA; j++) {
        A[i][j] = result[i][j];
      }
    }
  }
  for (int i = 0; i < rowsA; ++i) {
    for (int j = 0; j < colsA; ++j) {
      printf("%d ", A[i][j]);
    }
    printf("\n");
  }
}

// --------------------------------- 下面可以不用关注 -------------------------
int main() {
  for (int i = 1; i <= 10; i++) {
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