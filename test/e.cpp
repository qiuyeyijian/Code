#include <stdio.h>

// 递归找最大数， 每次比较数组开始结束和中间的数
int findMax(int *arr, int begin, int end) {
  static int max = arr[begin];

  // 如果开始位置和结束位置相等，无需比较直接返回最大值
  if (begin >= end) return max;

  int mid = (begin + end) / 2;
  max = max > arr[begin] ? max : arr[begin];
  max = max > arr[end] ? max : arr[end];
  max = max > arr[mid] ? max : arr[mid];

  findMax(arr, begin + 1, mid - 1);
  findMax(arr, mid + 1, end - 1);
}

int main(int argc, char const *argv[]) {
  int arr[] = {2, 6, 30, 9, 11, 5, 20, 7, 33};

  printf("Max: %d\n", findMax(arr, 0, 2));

  return 0;
}
