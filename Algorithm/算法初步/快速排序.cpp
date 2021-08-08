#include <stdio.h>

// 将[left, right]按照arr[left]分成两部分
// 左边都比arr[left]小，右边都比arr[left]大
// 返回中心下标
int partition(int arr[], int left, int right) {
  int pivot = arr[left];  // 将arr[left] 作为主元
  while (left < right) {  // 只要left和right不相遇
    // 反复左移right直到找到一个元素比pivot小
    while (left < right && arr[right] > pivot) right--;
    // 将找到的元素移到左边
    arr[left] = arr[right];
    // 再反复右移left直到找到一个元素比pivot大
    while (left < right && arr[left] <= pivot) left++;
    // 将该元素移动到右边
    arr[right] = arr[left];
  }

  // left 和 right相遇，则将pivot元素放到该位置下，一轮快排结束
  arr[left] = pivot;
  return left;  // left和right相遇的地方就是中心下标
}

// 快读排序， left和right初始值为序列的首尾下标
void quickSort(int arr[], int left, int right) {
  // 当前区间长度超过1
  if (left < right) {
    // 将[left, right]按照arr[left]分成两部分
    // 左边都比arr[left]小，右边都比arr[left]大
    int pos = partition(arr, left, right);
    // 对左边区间进行递归快速排序
    quickSort(arr, left, pos - 1);
    // 对右边区间进行递归快速排序
    quickSort(arr, pos + 1, right);
  }
}