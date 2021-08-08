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

// 随机选择算法， 从arr[left, right]中返回第k大的数
int randSelect(int* arr, int left, int right, int k) {
  if (left == right) return arr[left];  // 边界
  // 划分后的主元位置p
  int p = partition(arr, left, right);
  // arr[p] 是arr中的第m大
  int m = p - left + 1;
  // 找到第k大的数
  if (k == m) return arr[p];
  // 第K大的数在主元左侧
  if (k < m) {
    return randSelect(arr, left, p - 1, k);
  } else {
    return randSelect(arr, p + 1, right, k - m);
  }
}