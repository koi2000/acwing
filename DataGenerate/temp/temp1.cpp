//
// Created by DELL on 2023/10/31.
//
#include "stdio.h"

int main() {
  int n;
  scanf("%d", &n);
  int res[n];
  int arr[n];
  int index = 0;
  int maxx = -1;
  for (int i = 0; i < n; ++i) {
    int temp;
    scanf("%d", &temp);
    if (temp > maxx) {
      index = 0;
      maxx = temp;
      res[index] = i;
      index++;
    } else if (temp == maxx) {
      maxx = temp;
      res[index] = i;
      index++;
    }
  }
  for (int i = 0; i < index; ++i) {
    printf("%d ", res[i]);
  }
  return 0;
}