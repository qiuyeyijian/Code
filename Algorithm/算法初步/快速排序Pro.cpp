#include <stdio.h>

int getMid(int arr[], int left, int right) {
  int pivot = arr[left];
  while (left < right) {
    while (left < right && arr[right] > pivot) right--;
    arr[left] = arr[right];
    while (left < right && arr[left] <= pivot) left++;
    arr[right] = arr[left];
  }

  arr[left] = pivot;

  return left;
}

void quickSort(int arr[], int left, int right) {
  if (left < right) {
    int mid = getMid(arr, left, right);
    quickSort(arr, left, mid - 1);
    quickSort(arr, mid + 1, right);
  }
}