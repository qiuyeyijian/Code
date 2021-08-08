#include <stdio.h>
#include <string.h>
int binarySearch(int arr[], int data) {
  int left = 0;
  int right = sizeof(arr) / arr[0] - 1;

  while (left <= right) {
    // 获取中间下标
    // 这样做比 （left + right）/ 2 更安全，可以避免int溢出
    int mid = left + (right - left) / 2;
    if (arr[mid] == data) {
      // 查找成功，返回下标
      return mid;
    } else if (arr[mid] > data) {
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }

  // 查找失败
  return -1;
}

int main() {
  int arr[] = {1, 2, 3, 4, 5, 6, 7};

  printf("%d", binarySearch(arr, 5));

  return 0;
}