#include <stdio.h>
#include <string.h>
#define ROWS 10
#define COLS 10

// 矩阵乘法函数
void mul(int A[ROWS][COLS], int B[ROWS][COLS], int result[ROWS][COLS], int row1,
         int cols1, int cols2) {
  for (int i = 0; i < row1; ++i) {
    for (int j = 0; j < cols2; ++j) {
      for (int k = 0; k < cols1; ++k) {
        result[i][j] += A[i][k] * B[k][j];
      }
    }
  }
}

int main() {
  int n, row1, cols1, rows2, cols2;
  scanf("%d", &n);
  scanf("%d", &row1);
  scanf("%d", &cols1);
  int A[ROWS][COLS];
  for (int i = 0; i < row1; ++i) {
    for (int j = 0; j < cols1; ++j) {
      scanf("%d", &A[i][j]);
    }
  }

  for (int k = 0; k < n - 1; k++) {
    scanf("%d", &rows2);
    scanf("%d", &cols2);
    // 检查矩阵是否可以相乘
    if (cols1 != rows2) {
      printf("wrong\n");
      return 0;
    }
    int B[ROWS][COLS];
    for (int i = 0; i < rows2; ++i) {
      for (int j = 0; j < cols2; ++j) {
        scanf("%d", &B[i][j]);
      }
    }

    // 创建结果矩阵
    int result[ROWS][COLS];
    // 将result初始化为0
    memset(result, 0, 4 * ROWS * COLS);
    mul(A, B, result, row1, cols1, cols2);
    // 使用矩阵A存储上一次计算的结果，需要重新设置矩阵A的列数
    // c = A[m n] * b [n z]  c.size = [m z]
    cols1 = cols2;
    for (int i = 0; i < row1; i++) {
      for (int j = 0; j < cols1; j++) {
        A[i][j] = result[i][j];
      }
    }
  }
  for (int i = 0; i < row1; ++i) {
    for (int j = 0; j < cols1; ++j) {
      printf("%d ", A[i][j]);
    }
    printf("\n");
  }
  return 0;
}
