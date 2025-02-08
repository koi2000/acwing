#include <stdio.h>
#define MAX 100010
// 存储数组元素
int arr[MAX];
// 存储答案下标
int res[MAX];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &arr[i]);
  }
  int maxx = -1;
  int index = 0;
  for (int i = 0; i < n; ++i) {
    if (arr[i] > maxx) { // 当出现新的最大值时，将index置为0，表示清除了所有已存储的下标
      maxx = arr[i];
      index = 0;
      res[index++] = i;
    } else if (arr[i] == maxx) { // 若当前的最大值重复出现，在res数组中进行记录
      res[index++] = i;
    }
  }
  for (int i = 0; i < index; ++i) {
    printf("%d ", res[i]);
  }
  return 0;
}