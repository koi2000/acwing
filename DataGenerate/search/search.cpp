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

int main() { return 0; }
