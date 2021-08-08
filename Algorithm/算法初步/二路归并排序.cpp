#include <stdio.h>

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

// 将arr数组当前区间[left, right]进行归并排序
void mergeSort(int arr[], int left, int right) {
  if (left < right) {  // 只要left < right，说明还可以进行二分
    int mid = (left + right) / 2;  // 取[left, right]的中点
    mergeSort(arr, left, mid);  // 递归，将左区间[left, mid]归并排序
    mergeSort(arr, mid + 1, right);  // 递归，将右区间[mid + 1, right]归并排序
    merge(arr, left, mid, mid + 1, right);
  }
}

int main() {
  int arr[] = {3, 5, 2, 19, 33, 12, 1, 0};

  int len = sizeof(arr) / sizeof(arr[0]);

  mergeSort(arr, 0, len - 1);

  for (int i = 0; i < len; i++) {
    printf("%d ", arr[i]);
  }

  return 0;
}