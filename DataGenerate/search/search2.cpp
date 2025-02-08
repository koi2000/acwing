//
// Created by DELL on 2023/11/13.
//
#include "stdio.h"

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

int search2(int *arr, int key, int length) {
  for (int i = 0; i < length; ++i) {
    if (arr[i] == key) {
      return i;
    }
  }
  return -1;
}

int main() {
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
  return 0;
}
