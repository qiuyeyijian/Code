#include <stdio.h>

// 时间复杂度O(n)，空间复杂度O(n)
int solve(int* arr, int len) {
  // 定义最大值，比数组长度稍大一些，防止溢出
  const int maxn = len + 10;
  // 定义辅助标记数组
  int* t = new int[maxn]{0};

  // 将数组arr中出现的[1, len]区间内的正整数进行标记
  for (int i = 0; i < len; ++i) {
    if (arr[i] > 0 && arr[i] <= len) t[arr[i]] = 1;
  }

  // 寻找最小未出现的正整数
  for (int i = 1; i < maxn; ++i) {
    if (t[i] == 0) return i;
  }

  return -1;
}

int main() {
  int arr[5] = {-5, -2, 3, 2, 3};
  int arr1[3] = {1, 2, 3};
  printf("%d\n", solve(arr1, 3));
  return 0;
}