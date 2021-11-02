#include <iostream>

using namespace std;

void show(int* arr, int len) {
  for (int i = 0; i < len; ++i) {
    printf(" %d", arr[i]);
  }
  printf("\n");
}

// 时间复杂度O(n)，空间复杂度O(1)
int solve(int* arr, int n) {
  int pivot, mid = n / 2;       // 枢轴元素，和中间位置
  int left = 0, right = n - 1;  // 边界游标

  // 边界游标索引，保存每次划分后的游标位置，逐渐逼近中间位置
  int lindex = left, rindex = right;

  // 定义标志
  int flag = 1, s1 = 0, s2 = 0;

  while (flag) {
    pivot = arr[left];

    while (left < right) {
      while (left < right && arr[right] >= pivot) right--;
      arr[left] = arr[right];
      while (left < right && arr[left] <= pivot) left++;
      arr[right] = arr[left];
    }
    arr[left] = pivot;

    // 判断是否继续划分
    if (left < mid) {
      lindex = ++left;
      right = rindex;
    } else if (left > mid) {
      rindex = --right;
      left = lindex;
    } else {
      flag = 0;
    }
  }

  for (int i = 0; i < mid; ++i) {
    s1 += arr[i];
  }
  for (int i = mid; i < n; ++i) {
    s2 += arr[i];
  }

  return s2 - s1;
}

int main() {
  int arr[] = {1, 2};
  int len = sizeof(arr) / sizeof(arr[0]);

  printf("ans: %d\n", solve(arr, len));
  show(arr, len);

  return 0;
}