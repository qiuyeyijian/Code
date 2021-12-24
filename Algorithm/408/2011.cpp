#include <stdio.h>

// 时间复杂度O(n)，空间复杂度O(1)
int solve(int* arr1, int* arr2, int len) {
  int i = 0, j = 0;  // 两个序列的下标
  // 只需比较len-1次, 找到第n个和第n+1个数
  for (int k = 0; k < len - 1; ++k) {
    arr1[i] > arr2[j] ? j++ : i++;
  }
  // 返回二者当中较小的，就是中位数
  return arr1[i] > arr2[j] ? arr2[j] : arr1[i];
}

// 时间复杂度O(logn)，空间复杂度O(1)
int midNum(int* a, int* b, int n) {
  int s1 = 0, d1 = n - 1, s2 = 0, d2 = n - 1;
  int m1, m2;

  while (s1 != d1 || s2 != d2) {
    m1 = (s1 + d1) / 2;
    m2 = (s2 + d2) / 2;

    if (a[m1] == b[m2]) {
      return a[m1];
    } else if (a[m1] < b[m2]) {
      if ((s1 + d1) % 2 == 0) {  // 元素个数为奇数
        s1 = m1;                 // 保留中间点
        d2 = m2;                 // 保留中间点
      } else {                   // 元素个数为偶数
        s1 = m1 + 1;             // 不保留中间点
        d2 = m2;                 // 保留中间点
      }
    } else {
      if ((s2 + d2) % 2 == 0) {  // 元素个数为奇数
        s2 = m2;                 // 保留中间点
        d1 = m1;                 // 保留中间点
      } else {                   // 元素个数为偶数
        s2 = m2 + 1;             // 不保留中间点
        d1 = m1;                 // 保留中间点
      }
    }

  }  // end of while

  return (a[s1] < b[s2]) ? a[s1] : b[s2];
}

int main() {
  int arr1[5] = {11, 13, 15, 17, 19};
  int arr2[5] = {2, 4, 6, 8, 20};

  // printf("%d", midNum(arr1, arr2, 5));
  printf("%d", solve(arr1, arr2, 5));

  return 0;
}