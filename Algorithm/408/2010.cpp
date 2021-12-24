#include <stdio.h>

void reverse(int* arr, int start, int end) {
  int temp = 0;
  // 交换前后对应元素实现逆置
  while (start < end) {
    temp = arr[start];
    arr[start++] = arr[end];
    arr[end--] = temp;
  }
}

void solve(int* arr, int len, int p) {
  //将整个数组逆置
  reverse(arr, 0, len - 1);
  // 将数组前p个元素逆置
  reverse(arr, 0, p - 1);
  // 将数组后n-p个元素逆置
  reverse(arr, p, len - 1);
}

int main() {
  int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  solve(arr, 10, 4);

  for (int i = 0; i < 10; ++i) {
    printf("%d ", arr[i]);
  }

  return 0;
}