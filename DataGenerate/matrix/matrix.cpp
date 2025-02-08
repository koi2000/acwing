//
// Created by DELL on 2023/11/15.
//
#include <stdio.h>

// 定义最大矩阵大小
#define MAX_ROWS 100
#define MAX_COLS 100

// 函数声明
void multiplyMatrices(int A[MAX_ROWS][MAX_COLS], int B[MAX_ROWS][MAX_COLS],
                      int result[MAX_ROWS][MAX_COLS], int rowsA, int colsA,
                      int rowsB, int colsB);

int main() {
  int N, rowsA, colsA, rowsB, colsB;

  //输入矩阵数
  scanf("%d", &N);
  if (N != 2) {
    return 0;
  }

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

    // 检查矩阵是否可以相乘
    if (colsA != rowsB) {
      printf("wrong\n");
      return 0;
    }

    // 输入矩阵 B
    int B[MAX_ROWS][MAX_COLS];
    for (int i = 0; i < rowsB; ++i) {
      for (int j = 0; j < colsB; ++j) {
        scanf("%d", &B[i][j]);
      }
    }

    // 创建结果矩阵
    int result[MAX_ROWS][MAX_COLS];

    // 调用矩阵乘法函数
    multiplyMatrices(A, B, result, rowsA, colsA, rowsB, colsB);

    colsA = colsB;
    for (int i = 0; i < rowsA; i++) {
      for (int j = 0; j < colsA; j++) {
        A[i][j] = result[i][j];
      }
    }
  }
  for (int i = 0; i < rowsA; ++i) {
    for (int j = 0; j < colsA; ++j) {
      printf("%d\t", A[i][j]);
    }
    printf("\n");
  }
  return 0;
}

// 矩阵乘法函数
void multiplyMatrices(int A[MAX_ROWS][MAX_COLS], int B[MAX_ROWS][MAX_COLS],
                      int result[MAX_ROWS][MAX_COLS], int rowsA, int colsA,
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
