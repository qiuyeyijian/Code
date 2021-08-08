#include <stdio.h>

void twoPointers(int arr[], int i, int j, int m) {
  while (i < j) {
    if (arr[i] + arr[j] == m) {
      printf("%d %d\n", i, j);
      i++;
      j--;
    } else if (arr[i] + arr[j] < m) {
      i++;
    } else {
      j--;
    }
  }
}

int merge(int a[], int b[], int c[], int n, int m) {
  int i = 0, j = 0, index = 0;

  while (i < n && j < m) {
    if (a[i] <= b[j]) {
      c[index++] = a[i++];
    } else {
      c[index++] = b[j++];
    }
  }

  while (i < n) c[index++] = a[i++];
  while (j < m) c[index++] = b[j++];

  return index;
}