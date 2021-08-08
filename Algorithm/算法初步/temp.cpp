#include <stdio.h>
// arr为递增序列， x为欲查询的数， 函数返回第一个大于等于x的元素的位置
int lower_bound(int arr[], int left, int right, int x) {
  int mid;
  while (left < right) {
    mid = (left + right) / 2;
    if (arr[mid] >= x) {
      right = mid;
    } else {
      left = mid + 1;
    }
  }

  return left;
}