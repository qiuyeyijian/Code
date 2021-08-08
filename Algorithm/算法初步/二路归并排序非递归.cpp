#include <stdio.h>

#include <algorithm>

using namespace std;
const int maxn = 100;

// 将数组a的[l1, r1]与[l2, r2]区间合并为有序区间（此处l2, 即为 r1 + 1）
// 利用双指针法将两个区间合并， 注意while的边界
void merge(int arr[], int l1, int r1, int l2, int r2) {
  int i = l1, j = l2;  // i 指向arr[l1], j指向a[l2]

  int temp[maxn], index = 0;
  while (i <= r1 && j <= r2) {
    if (arr[i] <= arr[j]) {
      temp[index++] = arr[i++];
    } else {
      temp[index++] = arr[j++];
    }
  }

  while (i <= r1) temp[index++] = arr[i++];
  while (j <= r2) temp[index++] = arr[j++];

  // 将合并后的序列赋值回数组A
  for (int i = 0; i < index; i++) {
    arr[l1 + i] = temp[i];
  }
}

void mergeSort(int arr[], int n) {
  // set 为组内元素个数， step / 2 为左区间元素个数，注意等号可以不取
  for (int step = 2; step / 2 <= n; step *= 2) {
    // 每step 个元素一组，组内前step / 2 和后 step / 2 个元素进行合并
    for (int i = 1; i <= n; i += step) {
      int mid = i + step / 2 - 1;
      if (mid + 1 <= n) {
        merge(arr, i, mid, mid + 1, min(i + step - 1, n));
      }
    }
  }
}

void mergeSortPro(int arr, int n) {
  for (int step = 2; step / 2 <= n; step *= 2) {
    for (int i = 0; i < n; i += step) {
      int mid = i + step / 2 - 1;
      if (mid + 1 <= n) {
        sort(arr + i, arr + min(i + step, n + 1));
        merge(arr, i, mid, mid + 1, min(i + step - 1, n));
      }
    }
  }
}