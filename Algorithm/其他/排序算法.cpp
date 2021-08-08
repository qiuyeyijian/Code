#include <iostream>

using namespace std;

void show(int arr[], int len) {
  for (int i = 0; i < len; ++i) {
    printf("%d ", arr[i]);
  }
}

// 冒泡排序
void bubbleSort(int* arr, int len) {
  // 从后向前冒泡，从小到大排序
  /*for (int i = 0; i < len; ++i) {
      for (int j = len - 1; j > i; --j) {
          if (arr[j - 1] > arr[j]) {
              int temp = arr[j - 1];
              arr[j - 1] = arr[j];
              arr[j] = temp;
          }
      }
  }*/

  // 从前向后冒泡，从小到大排序
  for (int i = len - 1; i > 0; --i) {
    for (int j = 0; j < i; ++j) {
      if (arr[j + 1] < arr[j]) {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}

// 选择排序
void selectSort(int arr[], int len) {
  for (int i = 0; i < len - 1; ++i) {
    for (int j = i + 1; j < len; ++j) {
      if (arr[i] > arr[j]) {
        int temp = arr[j];
        arr[j] = arr[i];
        arr[i] = temp;
      }
    }
  }
}

// 插入排序
void insertSort(int arr[], int len) {
  for (int i = 1; i < len; ++i) {
    int temp = arr[i], j = i;

    // 向后移动
    while (j > 0 && arr[j - 1] > temp) {
      arr[j] = arr[j - 1];
      --j;
    }
    // 插入数据
    arr[j] = temp;
  }
}

int main() {
  int arr[] = {5, 2, 9, 4, 3, 7};
  int len = sizeof(arr) / sizeof(arr[0]);

  //   bubbleSort(arr, len);
  //   selectSort(arr, len);
  insertSort(arr, len);
  show(arr, len);

  return 0;
}