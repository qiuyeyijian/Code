#include <stdio.h>

// 冒泡排序
void bubbleSort(int* arr, int len) {
  int temp = 0;

  for (int i = 0; i < len; ++i) {
    for (int j = len - 1; j > i; --j) {
      if (arr[j - 1] > arr[j]) {
        temp = arr[j - 1];
        arr[j - 1] = arr[j];
        arr[j] = temp;
      }
    }
  }

  for (int i = len - 1; i > 0; --i) {
    for (int j = 0; j < i; ++j) {
      if (arr[j + 1] < arr[j]) {
        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}

// 选择排序
void selectSort(int* arr, int len) {
  int temp = 0;
  for (int i = 0; i < len - 1; ++i) {
    for (int j = i + 1; j < len; ++j) {
      if (arr[i] > arr[j]) {
        temp = arr[j];
        arr[j] = arr[i];
        arr[i] = temp;
      }
    }
  }
}

// 直接插入排序
void insertSort(int* arr, int len) {
  for (int i = 1; i < len; ++i) {
    int temp = arr[i], j = i;

    // 向后移动
    while (j > 0 && arr[j - 1] > temp) {
      arr[j] = arr[--j];
    }

    // 插入数据
    arr[j] = temp;
  }
}

// 将数组arr的[l1, r1] 与 [l2, r2]区间合并为有序区间（此处l2为 r1+1）
// 利用双指针将两个区间合并，注意while的边界
void merge(int* arr, int l1, int r1, int l2, int r2) {
  const int maxn = 100;
  int i = l1, j = l2;  // i 指向arr[l1], j 指向arr[l2]

  int temp[maxn], index = 0;
  while (i <= r1 && j <= r2) {
    // if (arr[i] <= arr[j]) {
    //   temp[index++] = arr[i++];
    // } else {
    //   temp[index++] = arr[j++];
    // }
    temp[index++] = arr[i] <= arr[j] ? arr[i++] : arr[j++];
  }

  while (i <= r1) temp[index++] = arr[i++];
  while (j <= r2) temp[index++] = arr[j++];

  // 将合并后的序列赋值回数组
  for (int i = 0; i < index; i++) {
    arr[l1 + i] = temp[i];
  }
}

void mergeSort(int* arr, int left, int right) {
  if (left < right) {
    int mid = (left + right) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, mid + 1, right);
  }
}